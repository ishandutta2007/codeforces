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
		int n = f.nextInt(), m = f.nextInt(), k = f.nextInt();
		boolean[] q = new boolean[n];
		LinkedList<Pair>[] adj = new LinkedList[n];
		for(int i = 0; i < n; i++) adj[i] = new LinkedList<>();
		for(int i = 0; i < m; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1, c = f.nextInt();
			adj[a].add(new Pair(b,c)); adj[b].add(new Pair(a,c));
		}
		while(k-->0) q[f.nextInt()-1] = true;
		int best = 2147483647;
		for(int i = 0;i  < n; i++)
			if(!q[i]) for(Pair p : adj[i])
				if(q[p.a]) best = Math.min(best, p.b);
		out.println(best == 2147483647 ? -1 : best);
		out.flush();
	}
	class Pair {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
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