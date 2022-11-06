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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt(), k = f.nextInt();
			boolean[] b = new boolean[n];
			char[] c = f.next().toCharArray();
			int a = 0;
			for(int i = 0; i < n; i++) {
				if(c[i] == '1') a = k+1;
				if(a-- > 0) b[i] = true;
			}
			a = 0;
			for(int i = n-1; i >= 0; i--) {
				if(c[i] == '1') a = k+1;
				if(a-- > 0) b[i] = true;
			}
			int cnt = 0;
			a = 0;
			while(a < n) {
				if(b[a]) a++;
				else {
					a += k+1;
					cnt++;
				}
			}
			out.println(cnt);
		}
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