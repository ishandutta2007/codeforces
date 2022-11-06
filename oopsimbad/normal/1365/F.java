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
            int n = f.nextInt();
            int[] a = new int[n];
            String[] s = new String[(n+1)/2];
            for(int i = 0; i < n; i++) {
                a[i] = f.nextInt();
                if(i >= n/2) {
                    if(n%2 == 1 && i == n/2) s[n-i-1] = ""+a[i];
                    else s[n-i-1] = Math.min(a[i], a[n-i-1]) + " " + Math.max(a[i], a[n-i-1]);
                }
            }
            int[] b = new int[n];
            String[] t = new String[(n+1)/2];
            for(int i = 0; i < n; i++) {
                b[i] = f.nextInt();
                if(i >= n/2) {
                    if(n%2 == 1 && i == n/2) t[n-i-1] = ""+b[i];
                    else t[n-i-1] = Math.min(b[i], b[n-i-1]) + " " + Math.max(b[i], b[n-i-1]);
                }
            }
            Arrays.sort(s); Arrays.sort(t);
            out.println(Arrays.toString(s).equals(Arrays.toString(t)) ? "Yes" : "No");
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