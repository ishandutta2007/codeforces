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
		int n = f.nextInt(), m = f.nextInt();
		long[] arr = new long[n];
		Pair[] sorted = new Pair[n];
		long[] cost = new long[n];
		for(int i = 0;  i < n; i++)
			arr[i] = f.nextLong();
		for(int i = 0; i < n; i++) {
			cost[i] = f.nextInt();
			sorted[i] = new Pair(cost[i], i);
		}
		Arrays.sort(sorted);
		int i = 0;
		while(m-->0) {
			int a = f.nextInt(), b = f.nextInt();
			long cur = 0;
			a--;
			if(arr[a] != 0) {
				if(arr[a] >= b) {
					cur += cost[a] * b;
					arr[a] -= b;
					out.println(cur);
					continue;
				}
				cur += arr[a] * cost[a];
				b -= arr[a];
				arr[a] = 0;
			}
			for(; i < n && b > 0;) {
				long val = Math.min(b, arr[sorted[i].b]);
				arr[sorted[i].b] -= val;
				b -= val;
				cur += val * cost[sorted[i].b];
				if(arr[sorted[i].b] == 0) i++;
			}
			if(b == 0) out.println(cur);
			else out.println(0);
		}
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		long a;
		int b;
		public Pair(long a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			if(a != p.a) return Long.compare(a, p.a);
			return Integer.compare(b,p.b);
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