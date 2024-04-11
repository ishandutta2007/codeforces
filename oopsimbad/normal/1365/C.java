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
        int n= f.nextInt();
        int[] map = new int[n];
        for(int i = 0; i < n; i++) map[f.nextInt()-1] = i;
        int[] cnt = new int[n];
        for(int i = 0; i < n; i++)
            cnt[(i-map[f.nextInt()-1]+n)%n]++;
        int best = 0;
        for(int i : cnt) best = Math.max(i, best);
        out.println(best);
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