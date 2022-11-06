import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final int MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt(), k = f.nextInt();
		int[] go = new int[n];
		long[] add = new long[n];
		Seg[] sarr = new Seg[2*k];
		for(int i = 0; i < k; i++) {
			int l = f.nextInt()-1, r = f.nextInt(), d = f.nextInt();
			long a = f.nextLong();
			sarr[2*i] = new Seg(l, d, a, false, i);
			sarr[2*i+1] = new Seg(r, d, a, true, i);
		}
		Arrays.sort(sarr, new Comparator<Seg>() {
			public int compare(Seg s1, Seg s2) {
				if(s1.x != s2.x) return Integer.compare(s1.x, s2.x);
				return Boolean.compare(s2.delete, s1.delete);
			}
		});
		TreeSet<Pair> ts = new TreeSet<Pair>();
		int j = 0;
		for(int i = 0; i < n; i++) {
			while(j < sarr.length && sarr[j].x == i) {
				if(sarr[j].delete) ts.remove(new Pair(sarr[j].d, sarr[j].val, sarr[j].i));
				else ts.add(new Pair(sarr[j].d, sarr[j].val, sarr[j].i));
				j++;
			}
			if(!ts.isEmpty()) {
				Pair p = ts.first();
				go[i] = p.a;
				add[i] = p.b;
			} else
				go[i] = i+1;
		}
		long[][] dp = new long[n+1][m+1];
		for(int i = n-1; i >= 0; i--) {
			dp[i][0] = dp[go[i]][0] + add[i];
			for(j = 1; j <= m; j++) {
				dp[i][j] = Math.min(dp[go[i]][j] + add[i], dp[i+1][j-1]);
			}
		}
		out.println(dp[0][m]);
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a; long b; int i;
		public Pair(int a, long b, int i) {
			this.a = a;
			this.b = b;
			this.i = i;
		}
		public int compareTo(Pair p) {
			if(b != p.b) return -Long.compare(b, p.b);
			if(a != p.a) return -Integer.compare(a, p.a);
			return Integer.compare(i, p.i); 
		}
	}
	class Seg {
		int x;
		boolean delete;
		int d;
		int i;
		long val;
		public Seg(int x, int d, long v, boolean b, int i) {
			this.x = x;
			this.d = d;
			val = v;
			delete = b;
			this.i = i;
		}
	}
    static class FastScanner {
        public BufferedReader reader;
        public StringTokenizer tokenizer;
        public FastScanner() {
            reader = new BufferedReader(new InputStreamReader(System.in), 32768);
            tokenizer = null;
        }
        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }
        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
        	return Long.parseLong(next());
        }
        public double nextDouble() {
        	return Double.parseDouble(next());
        }
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }
    }
}