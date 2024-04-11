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
        int n = f.nextInt(), k = f.nextInt();
        par = new int[n];
        if(n % 2 == 0) out.println("NO");
        else {
            ok = true;
            par[gen(n, k)] = -1;
            if(ok) {
                out.println("YES");
                for(int i : par) out.print(i+1 + " ");
            } else out.println("NO");
        }
///
		out.flush();
	}
    int[] par;
    int node;
    boolean ok;
    public int gen(int n, int k) {
        int me = node++;
        if(k < 0) ok = false;
        if(n == 1) {
        } else if(n == 3) {
            if(k != 0) ok = false;
            par[gen(1, 0)] = me;
            par[gen(1, 0)] = me;
        } else if(n == 5) {
            if(k != 1) ok = false;
            par[gen(1, 0)] = me;
            par[gen(3, 0)] = me;
        }
        else if(n == 7) {
            if(k == 0) {
                par[gen(3, 0)] = me;
                par[gen(3, 0)] = me;
            } else if(k == 2) {
                par[gen(1, 0)] = me;
                par[gen(5, 1)] = me;
            } else ok = false; 
        } else if(n == 9) {
            if(k == 1) {
                par[gen(1, 0)] = me;
                par[gen(7, 0)] = me;
            } else if(k == 3) {
                par[gen(1, 0)] = me;
                par[gen(7, 2)] = me;
            } else ok = false;
        } else if(n == 11) {
            if(k == 1 || k == 3) {
                par[gen(3, 0)] = me;
                par[gen(7, k-1)] = me;
            } else if(k == 2) {
                par[gen(5, 1)] = me;
                par[gen(5, 1)] = me;
            } else if(k == 4) {
                par[gen(1, 0)] = me;
                par[gen(9, 3)] = me;
            } else ok = false;
        } else if(k <= 1) {
            int d = 1;
            while((n - 1 - d) > 2*d) d = d*2+1;
            par[gen(d, 0)] = me;
            par[gen(n-d-1, k - (d > 2*(n-1-d) ? 1 : 0))] = me;
        } else {
            int asdf = n-1;
            while(asdf % 2 == 0) asdf /= 2;
            if(asdf == 1 && k == 2) {
                par[gen(3, 0)] = me;
                par[gen(n-4, k-1)] = me;
            } else {
                par[gen(1, 0)] = me;
                par[gen(n-2, k-1)] = me;
            }
        }
        return me;
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