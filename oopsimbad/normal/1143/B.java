import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		long n = f.nextLong();
		long best = 0;
		long t = 1;
		int c = 0;
		while(t*10 <= n) {
			t *= 10;
			c++;
		}
		long pref = 1;
		boolean asdf = true;
		for(; t >= 1; t /= 10) {
			best = Math.max(best,Math.round(Math.pow(9,c))*pref*(n/t%10-1 == 0 && asdf ? 1 : n/t%10-1));
			pref *= n/t%10;
			c--;
			asdf = false;
		}
		out.println(Math.max(best,pref));
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