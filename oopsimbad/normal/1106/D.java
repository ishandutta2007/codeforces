import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final int MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m= f.nextInt();
		LinkedList<Integer>[] adj = new LinkedList[n];
		for(int i = 0; i < n; i++)
			adj[i] = new LinkedList<Integer>();
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		pq.add(0);
		while(m-->0) {
			int a = f.nextInt(), b = f.nextInt();
			a--; b--;
			adj[a].add(b);
			adj[b].add(a);
		}
		boolean[] visited = new boolean[n];
		visited[0] = true;
		while(!pq.isEmpty()) {
			int i = pq.poll();
			out.print(i+1 + " ");
			for(int j : adj[i])
				if(!visited[j]) {
					pq.add(j);
					visited[j] = true;
				}
		}
		out.flush();
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