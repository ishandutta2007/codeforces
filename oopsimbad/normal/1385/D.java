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
            c = f.next().toCharArray();
            out.println(recur(0,n,0,'a'));
        }
///
		out.flush();
	}
    char[] c;
    public int recur(int l, int r, int t, int cc) {
        if(l == r-1) return c[l] == cc ? 0 : 1;
        if(t == 1) {
            int cnt = 0;
            for(int i = l; i < r; i++) if(c[i] == cc) cnt++;
            return r-l-cnt;
        }
        int m = (l+r)/2;
        return Math.min(recur(l,m,0,cc+1)+recur(m,r,1,cc), recur(l,m,1,cc)+recur(m,r,0,cc+1));
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