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
		int n  = f.nextInt(), m = f.nextInt(), k = f.nextInt();
		ArrayList<Integer>[] adj = new ArrayList[n];
		int[] d = new int[n];
		int[] c = new int[n];
		int[] par = new int[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
		for(int i = 0; i < m; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b); adj[b].add(a);
		}
		LinkedList<Integer> ll = new LinkedList<>();
		ll.add(0); c[0] = 1;
		int vb = 0, va = 0, st = -1;
		while(!ll.isEmpty()) {
			int i = ll.poll();
			if(c[i] == 1) va++;
			else vb++;
			if(Math.max(va, vb) >= (k+1)/2) break;
			for(int j : adj[i]) {
				if(c[j] == 0 || c[j] == (3^c[i])) {
					if(c[j] == 0) {
						ll.add(j);
						c[j] = 3^c[i];
						par[j] = i;
					}
				} else {
					LinkedList<Integer> l = new LinkedList<>();
					l.add(j); l.add(i);
					int a = par[j];
					int b = par[i];
					while(a != b) {
						l.addFirst(a);
						l.addLast(b);
						a = par[a];
						b = par[b];
					}
					l.addFirst(a);
					out.println(2);
					out.println(l.size());
					for(int q : l) out.print(q+1+ " ");
					out.println();
					out.flush();
					return;
				}
			}
		}
		if(va >= (k+1)/2) {
			out.println(1);
			k = (k+1)/2;
			for(int i = 0; k > 0 && i < n; i++)
				if(c[i] == 1) {
					out.print(i+1+" ");
					k--;
				}
			out.println();
		} else {
			out.println(1);
			k = (k+1)/2;
			for(int i = 0; k > 0 && i < n; i++)
				if(c[i] == 2) {
					out.print(i+1+" ");
					k--;
				}
			out.println();
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