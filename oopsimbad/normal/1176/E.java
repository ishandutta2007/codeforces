import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class E {
	public static void main(String[] args) throws Exception {
		new E().run();
	}
	boolean[] vis;
	LinkedList<Integer> adj[];
	boolean[] pick;
	int cnt;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int asdf = f.nextInt();
		adj = new LinkedList[200000];
		for(int i = 0; i < 200000; i++) adj[i] = new LinkedList<>();
		vis = new boolean[200000];
		pick = new boolean[200000];
		while(asdf-->0) {
			int n = f.nextInt(), m = f.nextInt();
			for(int i = 0; i < n; i++) {
				vis[i] = pick[i] = false;
				adj[i].clear();
			}
			for(int i = 0; i < m; i++) {
				int a = f.nextInt()-1, b = f.nextInt()-1;
				adj[a].add(b);
				adj[b].add(a);
			}
			cnt = 0;
			recur(0, true);
			boolean tar = true;
			if(cnt > n/2) {
				tar = false;
				cnt = n - cnt;
				}
				out.println(cnt);
			for(int i = 0; i < n; i++)
				if(pick[i] == tar) out.print(i+1+" ");
			out.println();
		}
        out.flush();
	}
	public void recur(int i, boolean b) {
		if(vis[i]) return;
		vis[i] = true;
		pick[i] = b;
		if(pick[i]) cnt++;
		b^= true;
		for(int j : adj[i])
			recur(j, b);
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