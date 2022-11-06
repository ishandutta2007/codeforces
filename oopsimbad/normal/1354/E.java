import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	boolean[] b, vis;
	ArrayList<Integer>[] adj;
	ArrayList<Integer>[][] comp;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt();
		b = new boolean[n];
		vis = new boolean[n];
		adj = new ArrayList[n];
		comp = new ArrayList[n][2];
		for(int i = 0; i < n; i++)
			adj[i] = new ArrayList<>();
		int n1 = f.nextInt(), n2 = f.nextInt(), n3 = f.nextInt();
		for(int i = 0; i < m; i++) {
			int a= f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		int cn = 0;
		boolean ans = true;
		for(int i = 0; i < n; i++) {
			if(!vis[i]) {
				comp[cn][0] = new ArrayList<>();
				comp[cn][1] = new ArrayList<>();
				ans &= dfs(i,cn++, true);
			}
		}
		if(ans) {
			boolean[][] use = new boolean[cn+1][n2+1];
			boolean[][] pos = new boolean[cn+1][n2+1];
			pos[0][0] = true;
			for(int i = 0; i < cn; i++)
				for(int j = 0; j <= n2; j++)
					if(pos[i][j]) {
						if(j+comp[i][0].size() <= n2) {
							pos[i+1][j+comp[i][0].size()] = true;
							use[i+1][j+comp[i][0].size()] = false;
						}
						if(j+comp[i][1].size() <= n2) {
							pos[i+1][j+comp[i][1].size()] = true;
							use[i+1][j+comp[i][1].size()] = true;
						}
					}
			if(pos[cn][n2]) {
				out.println("YES");
				int[] res = new int[n];
				for(int i = cn; i > 0; i--) {
					if(use[i][n2]) {
						for(int j : comp[i-1][1])
							res[j] = 2;
						n2 -= comp[i-1][1].size();
					} else {
						for(int j : comp[i-1][0])
							res[j] = 2;
						n2 -= comp[i-1][0].size();
					}
				}
				for(int i = 0; i < res.length; i++)
					if(res[i] == 0)
						if(n1-- <= 0) res[i] = 3;
						else res[i] = 1;
				for(int i : res) out.print(i);
				out.println();
			} else out.println("NO");
		} else out.println("NO");
		out.flush();
	}
	public boolean dfs(int i, int cn, boolean val) {
		if(vis[i]) return val == b[i];
		vis[i] = true;
		b[i] = val;
		if(val) comp[cn][0].add(i);
		else comp[cn][1].add(i);
		boolean ret = true;
		for(int j : adj[i])
			ret &= dfs(j,cn,val^true);
		return ret;
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