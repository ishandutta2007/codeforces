import java.io.*; 
import java.text.*; 
import java.util.*; 
import java.math.*;
public class template { 
    public static void main(String[] args) throws Exception {
        new template().run();
    } 
    public void run() throws Exception { 
        FastScanner f = new FastScanner(); 
        PrintWriter out = new PrintWriter(System.out); 
        ///
        int asdf = f.nextInt();
        while(asdf-->0) {
            int k = f.nextInt(), n = f.nextInt();
            Pair[] arr = new Pair[n];
            for(int i = 0; i < n; i++) {
                int a = f.nextInt(), b = f.nextInt();
                arr[i] = new Pair(a,b);
            }
            Arrays.sort(arr);
            long[] psum = new long[n+1];
            Pair[] parr = new Pair[n];
            for(int i = 0; i < n; i++) {
                parr[i] = arr[i];
                psum[i+1] = arr[i].a;
            }
            dumb_bool = true;
            Arrays.sort(arr);
            dumb_bool = false;
            for(int i = 1; i <= n; i++) psum[i] += psum[i-1];
            int l = 0;
            long best = psum[Math.min(k,n)];
            for(Pair p : arr) {
                while(l < k-1 && l < n && p.b < parr[l].a) l++;
                if(l == n || p.compareTo(parr[l]) < 0) {
                    best = Math.max(best, psum[l] + (k-l)*p.b);
                } else if(k-l >= 2) best = Math.max(best, psum[l] + p.a + (k-l-1)*p.b);
                else if(l != 0) best = Math.max(best, psum[l] + p.a + p.b - parr[l-1].a);
            }
            out.println(best);
        }
///
		out.flush();
	}
    boolean dumb_bool;
    class Pair implements Comparable<Pair> {
        long a, b;
        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
        public int compareTo(Pair p) {
            if(!dumb_bool) return -Long.compare(a, p.a);
            if(b == p.b) return Long.compare(a, p.a);
            else return -Long.compare(b, p.b);
        }
    }
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in), 32768);
			tokenizer = null;
		}
		public String next() { while (tokenizer == null || !tokenizer.hasMoreTokens()) {
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