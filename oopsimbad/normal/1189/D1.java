import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	LinkedList<Integer>[] adj;
	int[] par, sz;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		adj = new LinkedList[n];
		for(int i = 0; i < n; i++) adj[i] = new LinkedList<>();
		for(int i = 0; i < n-1; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		int st = -1;
		for(int i = 0 ; i < n && st == -1; i++)
			if(adj[i].size() == 1) st = i;
		par = new int[n];
		sz = new int[n];
		dfs(st, -1);
		boolean works = true;
		for(int i = 0; i < n; i++) 
			works &= st == i || sz[i] != 1;
		out.println(works ? "YES" : "NO");
///
		out.flush();
	}
	public void dfs(int i, int p) {
		if(p != -1) sz[p]++;
		par[i] = p;
		for(int j : adj[i])
			if(p != j) dfs(j, i);
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