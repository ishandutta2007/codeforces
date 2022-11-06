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
			int k = f.nextInt();
			int[][] a = new int[n][n];
			int r = 0, c = 0;
			while(k-->0) {
				a[r][c] = 1;
				r++; c++;
				if(r == n) r = 0;
				if(c == n) c = 0;
				if(a[r][c] == 1) c++;
			}
			int mina = n, maxa = 0, minb = n, maxb = 0;
			for(int i = 0; i < n; i++) {
				r = 0; c = 0;
				for(int j = 0; j < n; j++) {
					r += a[i][j];
					c += a[j][i];
				}
				mina = Math.min(mina, r);
				maxa = Math.max(maxa, r);
				minb = Math.min(minb, c);
				maxb = Math.max(maxb, c);
			}
			out.println(maxa+maxb-mina-minb);
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++)
					out.print(a[i][j]);
				out.println();
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