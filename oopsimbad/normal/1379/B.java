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
            long l = f.nextLong();
            long r = f.nextLong();
            long m = f.nextLong();
            for(long a = l; a <= r; a++) {
                {
                    long n = m/a;
                    long b = m-n*a+l;
                    if(n > 0 && b <= r) {
                        out.println(a + " " + b + " " + l);
                        break;
                    }
                }
                {
                    long n = (m+a-1)/a;
                    long b = m-n*a+r;
                    if(n > 0 && b >= l) {
                        out.println(a + " " + b + " " + r);
                        break;
                    }
                }
            }
        }
///
		out.flush();
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