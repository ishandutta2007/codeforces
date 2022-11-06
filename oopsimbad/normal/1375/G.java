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
		int n = f.nextInt();
		int[] cnt = new int[n], d = new int[n];
		ArrayList<Integer>[] adj = new ArrayList[n];
		for(int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
			d[i] = -1;
		}
		for(int i = 0; i < n-1; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
			cnt[a]++;
			cnt[b]++;
		}
		LinkedList<Integer> q = new LinkedList<>();
		q.add(0);
		d[0] = 0;
		int ans = 0;
		boolean[] vis = new boolean[n];
		while(!q.isEmpty()) {
			int i = q.poll();
			if(vis[i]) continue;
			if(d[i] % 2 == 0) ans++;
			vis[i] = true;
			for(int j : adj[i]) if(d[j] == -1) {
				q.add(j);
				d[j] = d[i]+1;
			}
		}
		out.println(Math.min(n-ans,ans)-1);
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