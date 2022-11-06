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
			adj = new ArrayList[n];
			q = new ArrayList[n];
			out.print("? "+n);
			for(int i = 0; i < n; i++) {
				adj[i] = new ArrayList<>();
				out.print(" " + (i+1));
				q[i] = new ArrayList<>();
			}
			for(int i = 0; i < n-1; i++) {
				int a = f.nextInt()-1, b = f.nextInt()-1;
				adj[a].add(b); adj[b].add(a);
			}
			out.println();
			out.flush();
			int r = f.nextInt()-1, min = f.nextInt();
			dists = new int[n];
			dfs(r, -1, 0);
			int lo = (min+1)/2, hi = min;
			int ans = 0, ind = -1;
			while(lo <= hi) {
				int m = (lo+hi)/2;
				if(q[m].size() == 0) {
					hi = m-1;
					continue;
				}
				out.print("? " + q[m].size());
				for(int i : q[m]) out.print(" " + (i+1));
				out.println();
				out.flush();
				int a = f.nextInt();
				if(f.nextInt() > min) hi = m-1;
				else {
					lo = m+1;
					if(m > ind) {
						ind = m;
						ans = a-1;
					}
				}
			}
			for(ArrayList<Integer> a : q) a.clear();
			dfs(ans, -1, 0);
			out.print("? " + q[min].size());
			for(int i : q[min]) out.print(" " + (i+1));
			out.println();
			out.flush();
			int b = f.nextInt();
			f.next();
			out.println("! "+ (ans+1) + " " + b);
			out.flush();
			if(!f.next().equals("Correct")) break;
		}
///
		out.flush();
	}
	ArrayList<Integer>[] adj;
	ArrayList<Integer>[] q;
	int[] dists;
	public void dfs(int i, int p, int v) {
		dists[i] = v;
		for(int j : adj[i]) if(j != p) dfs(j, i, v+1);
		q[v].add(i);
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