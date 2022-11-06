import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	ArrayList<Integer> adj[];
	boolean[] exist;
	int ans;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		adj = new ArrayList[n];
		for(int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		for(int i = 0; i < n-1; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		ans = n-1;
		exist = new boolean[2];
		for(int i = 0; i < n; i++)
			if(adj[i].size() != 1){
				dfs(i,-1,0);
				break;
			 }
		out.println((exist[0] && exist[1] ? "3 " : "1 ") + ans);
		out.flush();
	}
	public boolean dfs(int i, int p, int d) {
		int cnt = 0;
		for(int j : adj[i])
			if(j != p) 
				if(dfs(j, i, d^1)) cnt++;
		if(cnt >= 2) ans -= cnt-1;
		if(adj[i].size() == 1) {
			exist[d] = true;
			return true;
		}
		return false;
	}
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