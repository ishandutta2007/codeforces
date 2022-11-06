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
		int n = f.nextInt(), m = f.nextInt();
		ArrayList<Pair>[] adj = (ArrayList<Pair>[]) new ArrayList[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<Pair>();
		for(int i = 0; i < m; i++) {
			int a = f.nextInt()-1,  b = f.nextInt()-1;
			long l = f.nextLong();
			adj[a].add(new Pair(b,l));
			adj[b].add(new Pair(a,l));
		}
		boolean[] visited = new boolean[n];
		int[] prev = new int[n];
		long[] dist = new long[n];
		Arrays.fill(dist,-1);
		Arrays.fill(prev,-1);
		dist[0] = 0;
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		Pair beginning = new Pair(0,0);
		beginning.pi = -1;
		pq.add(beginning);
		while(true) {
			if(pq.isEmpty()) break;
			Pair best = pq.poll();
			while(!pq.isEmpty() && visited[best.i]) best = pq.poll();
			if(pq.isEmpty() && visited[best.i]) break;
			int minind = best.i;
			long mindist = best.v;
			prev[best.i] = best.pi;
			dist[best.i] = mindist;
			visited[minind] = true;
			for(Pair p : adj[minind]) {
				if(!visited[p.i]) {
					Pair np = new Pair(p.i,mindist + p.v);
					np.pi = minind;
					pq.add(np);
				}
			}
		}
		if(dist[n-1] == -1) out.println(-1);
		else {
			Stack<Integer> s = new Stack<Integer>();
			int cur = n-1;
			while(cur != -1) {
				s.add(cur+1);
				cur = prev[cur];
			}
			while(!s.isEmpty()) out.print(s.pop() +" ");
			out.println();
		}
		out.flush();
	}
 	class Pair implements Comparable<Pair> {
		int i;
		long v;
		int pi;
		public Pair(int n, long l) {
			i = n;
			v = l;
		}
		public int compareTo(Pair p) {
			if(p.v != v) return Long.compare(v, p.v);
			return i - p.i;
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

    }
}