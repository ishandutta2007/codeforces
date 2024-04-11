import java.io.*; 
import java.text.*; 
import java.util.*; 
import java.math.*;
public class C { 
    public static void main(String[] args) throws Exception {
        new C().run();
    } 
    public void run() throws Exception { 
        FastScanner f = new FastScanner(); 
        PrintWriter out = new PrintWriter(System.out); 
        int n = f.nextInt();
        double d = f.nextDouble();
        for(int i = 0; i <= n; i++) {
            double prob = 1.5 * i * (n-i) * (n-i-1) / n / (n-1) / (n-2);
            prob += 3.0 * i * (i-1) * (n-i) / n / (n-1) / (n-2);
            prob += 1.0 * i * (i-1) * (i-2) / n / (n-1) / (n-2);
            if(prob + 1e-8 >= d) {
                out.println(i);
                break;
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