import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	LinkedList<Integer>[] adj;
	boolean[] visited;
	long[] costs;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt();
		costs = new long[n];
		adj = (LinkedList<Integer>[]) new LinkedList[n];
		for(int i = 0; i < n; i++) {
			costs[i] = f.nextLong();
			adj[i] = new LinkedList<Integer>();
		}
		while(m-->0) {
			int x = f.nextInt()-1, y = f.nextInt()-1;
			adj[x].add(y);
			adj[y].add(x);
		}
		visited = new boolean[n];
		long total = 0;
		for(int i = 0; i < n; i++) {
			if(!visited[i]) {
				total += recur(i);
			}
		}
		out.println(total);
		out.flush();
	}
	public long recur(int i) {
		if(visited[i]) return costs[i];
		visited[i] = true;
		long best = costs[i];
		for(int j : adj[i]) best = Math.min(best, recur(j));
		return best;
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