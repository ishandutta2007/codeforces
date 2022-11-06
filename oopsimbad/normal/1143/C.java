import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int[] p = new int[n];
		boolean[] b = new boolean[n];
		boolean[] c=  new boolean[n];
		for(int i = 0; i < n; i++) {
			p[i] = f.nextInt()-1;
			b[i] = f.nextInt() == 1;
		}
		for(int i = 0; i < n; i++) {
			if(p[i] == -2) continue;
			if(!b[i]) c[p[i]] = true;
		}
		boolean asdf = true;
		for(int i = 0; i < n; i++) if(!c[i] && b[i]) {
			asdf = false;
			out.print(i+1 + " ");
		}
		out.println(asdf ? -1 : "");
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