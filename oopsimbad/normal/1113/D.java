import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final int MOD = 998_244_353;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		char[] c = f.next().toCharArray();
		boolean possible = false;
		for(int i = 0; i < c.length; i++)
			possible |= c[0] != c[i] && !(i == c.length/2 && c.length%2 == 1);
		if(!possible) {
			out.println("Impossible");
			out.flush();
			return;
		}
		int ans = 2;
		int n = c.length;
		for(int i = 1; i < n; i++) {
			boolean b = true;
			boolean d = false;
			for(int k = 0; k < n; k++) {
				b = b && c[(i+k)%n] == c[(i-1-k+n)%n];
				d = d || c[(i+k)%n] != c[k];
			}
			if(b && d) ans = 1;
		}
		out.println(ans);
		out.flush();
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