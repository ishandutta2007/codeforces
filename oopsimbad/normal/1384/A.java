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
		int times = f.nextInt();
		while(times-->0) {
			int n = f.nextInt();
			char[][] c = new char[n+1][200];
			Arrays.fill(c[0], 'a');
			for(int i = 0; i < n; i++) {
				int a = f.nextInt();
				for(int j = 0; j < a; j++)
					c[i+1][j] = c[i][j];
				c[i+1][a] = (char) ((c[i][a] - 'a' + 1) % 26  + 'a');
				for(int j = a+1; j < 200; j++) c[i+1][j] = 'a';
			}
			for(char[] cc : c) out.println(cc);
		}
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