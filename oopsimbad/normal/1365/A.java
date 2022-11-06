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
            int r = f.nextInt(), c = f.nextInt();
            boolean[] a = new boolean[r], b=  new boolean[c];
            Arrays.fill(a, true); Arrays.fill(b, true);
            int o = r, p = c;
            for(int i = 0; i < r; i++)
                for(int j = 0; j < c; j++)
                    if(f.nextInt() == 1) {
                        if(a[i]) {
                            o--;
                            a[i] = false;
                        }
                        if(b[j]) {
                            p--;
                            b[j] = false;
                        }
                    }
            out.println(Math.min(o, p) % 2 == 0 ? "Vivek" :"Ashish");
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