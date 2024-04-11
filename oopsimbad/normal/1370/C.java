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
			if(n == 1) out.println("FastestFinger");
			else if(n == 2) out.println("Ashishgup");
			else if(n % 2 == 1) out.println("Ashishgup");
			else {
				if(n % 2 == 0 && n % 4 != 0) {
					n /= 2;
					boolean b = false;
					for(int i = 3; i*i <= n; i++)
						b |= n%i == 0;
					if(b) out.println("Ashishgup");
					else out.println("FastestFinger");
				}
				else {
					while(n%2 == 0) n /= 2;
					if(n == 1) out.println("FastestFinger");
					else out.println("Ashishgup");
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