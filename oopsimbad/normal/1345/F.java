import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	double eps = 1e-7;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		long k = f.nextLong();
		int[] a = new int[n];
		long h = 0;
		for(int i = 0; i < n; i++)
			h = Math.max(a[i] = f.nextInt(), h);
		long l = -1;
		while(true) {
			long kk = 0;
			for(int i : a) {
				kk += Math.min(i,(long) (eps+Math.sqrt((i-l)/3.0)));
				if(kk >= k) break;
			}
			if(kk >= k) break;
			l *= 2;
		}
		while(l < h) {
			long m = (l+h)/2;
			if(m == h) m--;
			long kk = 0;
			for(int i : a) {
				kk += Math.min(i,(long) (eps+Math.sqrt((i-m)/3.0)));
				if(kk > k) break;
			}
			if(kk > k) l = m+1;
			else h = m;
		}
		int[] ans = new int[n];
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		for(int i = 0; i < n; i++) {
			k -= ans[i] = (int) Math.min(a[i],(long) Math.sqrt((a[i]-l)/3.0));
			if(ans[i] != a[i]) pq.add(new Pair(a[i]-3L*(ans[i]+1)*(ans[i]+1),i));
		}
		while(k-->0) ans[pq.poll().b]++;
		for(int i : ans) out.print(i + " ");
		out.println();
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		long a; int b;
		public Pair(long a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			return -Long.compare(a, p.a);
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