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
            int n = f.nextInt(), k = f.nextInt();
            int[] edges = new int[n];
            boolean[] used = new boolean[n];
            ArrayList<Integer>[] adj = new ArrayList[n];
            for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
            for(int i = 0; i < n-1; i++) {
                int a = f.nextInt()-1, b = f.nextInt()-1;
                adj[a].add(b);
                adj[b].add(a);
                edges[a]++;
                edges[b]++;
            }
            int[] leaf = new int[n];
            LinkedList<Integer> q = new LinkedList<>();
            for(int i = 0; i < n; i++) if(edges[i] == 1) {
                used[i] = true;
                for(int j : adj[i])
                    if(!used[j] && ++leaf[j] == k) q.add(j);
            }
            int ans = 0;
            while(!q.isEmpty()) {
                int i = q.poll();
                while(leaf[i] >= k) {
                    leaf[i] -= k;
                    edges[i] -= k;
                    ans++;
                }
                if(edges[i] == 1) {
                    used[i] = true;
                    for(int j : adj[i]) 
                        if(!used[j] && ++leaf[j] == k) q.add(j);
                }
            }
            out.println(ans);
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