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
            int[] arr = new int[n], barr = new int[n], c[] = new int[n][2];
            boolean ok = true;
            for(int i = 0; i < n; i++) {
                arr[i] = f.nextInt()-1;
                if(c[arr[i]][0] == 0) c[arr[i]][0] = i+1;
                else if(c[arr[i]][1] == 0) c[arr[i]][1] = i+1;
                else ok = false;
            }
            for(int i = 0; i < n; i++) {
                barr[i] = f.nextInt()-1;
                if(c[barr[i]][0] == 0) c[barr[i]][0] = -i-1;
                else if(c[barr[i]][1] == 0) c[barr[i]][1] = -i-1;
                else ok = false;
            }
            if(ok) {
                adj = new ArrayList[n];
                vis = new int[n];
                for(int i = 0; i < n; i++) adj[i] = new ArrayList<>(); 
                for(int i = 0; i < n; i++) {
                    int a = Math.abs(c[i][0])-1, b = Math.abs(c[i][1])-1;
                    if(c[i][0] < 0 != c[i][1] < 0) {
                        adj[a].add(b);
                        adj[b].add(a);
                    } else {
                        adj[a].add(-b);
                        adj[b].add(-a);
                    }
                }
                ok = true;
                boolean[] use = new boolean[n];
                int tot = 0;
                for(int i = 0; i < n; i++) {
                    if(vis[i] == 0) {
                         a.clear(); b.clear();
                         dfs(i, 1);
                         if(a.size() < b.size())
                            for(int q : a) use[q] = true;
                        else
                            for(int q : b) use[q] = true;
                        tot += Math.min(a.size(), b.size());
                    }
                }
                if(ok) {
                    out.println(tot);
                    for(int i = 0; i < n; i++) if(use[i]) out.print(i+1+" ");
                    out.println();
                } else out.println(-1);
            } else out.println(-1);
        }
///
		out.flush();
	}
    boolean ok;
    ArrayList<Integer>[] adj;
    int[] vis;
    ArrayList<Integer> a = new ArrayList<>(), b = new ArrayList<>();
    public void dfs(int i, int id) {
        if(vis[i] != 0) {
            ok &= vis[i] == id;
            return;
        }
        if(id < 0) b.add(i);
        else a.add(i);
        vis[i] = id;
        for(int j : adj[i]) 
            if(j < 0) dfs(-j, -id);
            else dfs(j, id);
    } 
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in), 32768);
			tokenizer = null;
		}
		public String next() { while (tokenizer == null || !tokenizer.hasMoreTokens()) {
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