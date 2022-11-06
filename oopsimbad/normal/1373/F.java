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
			long[] a = new long[2*n], b = new long[2*n];
			for(int i = 0; i < n; i++)
				a[i] = a[i+n] = f.nextInt();
			for(int i = 0; i < n; i++) {
				b[i] = b[i+n] = f.nextInt();
				a[i+n] = a[i] = b[i]-a[i];
			}
			n *= 2;
			boolean pos = false;
			Stack<Pair> ends = new Stack<>();
			ends.add(new Pair(n, Long.MAX_VALUE, Long.MAX_VALUE));
			for(int i = n-1; !pos && i >= 0; i--) {
				ends.peek().m = Math.min(ends.peek().m, b[i]);
				if(a[i] > 0) {
					while(!ends.isEmpty()) {
						Pair p = ends.peek();
						if(p.m == 0) break;
						long add = Math.min(Math.min(p.b, p.m), a[i]);
						p.b -= add;
						p.m -= add;
						a[i] -= add;
						if(p.b == 0) {
							long m = ends.pop().m;
							ends.peek().m = Math.min(ends.peek().m, m);
						}
						if(a[i] == 0) break;
					}
				}
				else if(a[i] < 0)
					ends.add(new Pair(i, -a[i], Long.MAX_VALUE));
				pos = ends.peek().a-i > n/2;
			}
			out.println(pos ? "YES" : "NO");
		}
///
		out.flush();
	}
	class Pair {
		int a; long b; long m;
		public Pair(int a, long b, long m) {
			this.a = a;
			this.b = b;
			this.m = m;
		}
		public String toString() {
			return "i: " + a + ", req: " + b + ", max: " + m;
		}
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