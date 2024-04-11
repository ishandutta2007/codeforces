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
		int n = f.nextInt(), k = f.nextInt();
		adj = new LinkedList[n];
		sz = new int[n]; d = new int[n];
		for(int i = 0; i < n; i++)
			adj[i] = new LinkedList<>();
		for(int i = 0; i < n-1; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		dfs(0,-1);
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		for(int i= 0; i < n; i++)
			pq.add(new Pair(d[i]-sz[i]+1,i));
		long cur = 0;
		while(k-->0) cur += pq.poll().a;
		out.println(cur);
		out.flush();
	}
	LinkedList<Integer>[] adj;
	int[] sz, d;
	public void dfs(int i, int p) {
		if(p != -1) d[i] = d[p]+1;
		sz[i] = 1;
		for(int j : adj[i]) {
			if(j != p) {
				dfs(j,i);
				sz[i] += sz[j];
			}
		}
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			return -Integer.compare(a, p.a);
		}
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