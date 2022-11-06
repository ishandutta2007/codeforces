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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int r = f.nextInt(), c = f.nextInt();
			int[][] a = new int[r][c];
			int[][] b = new int[r][c];
			boolean ok = true;
			for(int i = 0; i < r; i++) for(int j = 0; j < c; j++) {
				a[i][j] = f.nextInt();
				b[i][j] = 4;
				if(i == 0) b[i][j]--;
				if(i == r-1) b[i][j]--;
				if(j == c-1) b[i][j]--;
				if(j == 0) b[i][j]--;
				ok &= b[i][j] >= a[i][j];
			}
			if(ok) {
				out.println("YES");
				for(int i = 0; i < r; i++) {
					for(int j = 0; j < c; j++) out.print(b[i][j] + " ");
					out.println();
				}
			} else out.println("NO");
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