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
		int n = f.nextInt();
		long[] x = new long[n], y = new long[n];
		for(int i = 0; i < n; i++) {
			x[i] = f.nextInt();
			y[i] = f.nextInt();
		}
		long[] c = new long[n], k = new long[n];
		for(int i = 0; i < n; i++) c[i] = f.nextLong();
		for(int i = 0; i < n; i++) k[i] = f.nextLong();
		LinkedList<Pair>[] adj = new LinkedList[n+1];
		for(int i = 0; i <= n; i++)adj[i] = new LinkedList<>();
		for(int i = 0; i < n; i++) {
			adj[n].add(new Pair(i, c[i]));
			adj[i].add(new Pair(n, c[i]));
			for(int j = i+1; j < n; j++) {
				adj[i].add(new Pair(j,(k[i]+k[j])*(Math.abs(x[i]-x[j]) + Math.abs(y[i]-y[j]))));
				adj[j].add(new Pair(i,(k[i]+k[j])*(Math.abs(x[i]-x[j]) + Math.abs(y[i]-y[j]))));
			}
		}
		ArrayList<Integer> a = new ArrayList<>();
		ArrayList<Integer> b = new ArrayList<>();
		boolean[] visited = new boolean[n+1];
		long[] best = new long[n+1];
		int[] par = new int[n+1];
		Arrays.fill(par, -1);
		Arrays.fill(best, Long.MAX_VALUE);
		visited[n] = true;
		best[n] = 0;
		for(Pair p : adj[n]) {
			if(p.l < best[p.a]) {
				best[p.a] = p.l;
				par[p.a] = n;
			}
		}
		long ans = 0;
		for(int asdf = 0; asdf < n; asdf++) {
			long besta = Long.MAX_VALUE;
			int besti = -1;
			for(int i = 0; i < n; i++) 
				if(best[i] < besta && !visited[i]) {
					besta = best[i];
					besti = i;
				}
			visited[besti] = true;
			if(par[besti] == n) a.add(besti);
			else {
				b.add(par[besti]);
				b.add(besti);
			}
			ans += best[besti];
			for(Pair p : adj[besti]) {
				if(p.l < best[p.a] && !visited[p.a]) {
					best[p.a] = p.l;
					par[p.a] = besti;
				}
			}
		}
		out.println(ans);
		out.println(a.size());
		for(int i = 0; i < a.size(); i++) out.print(a.get(i) +1+ " ");
		out.println();
		out.println(b.size()/2);
		for(int i = 0; i < b.size(); i+=2) out.println(b.get(i)+1 + " " + (b.get(i+1)+1));
 
///
		out.flush(); 
	}
	class Pair {
		int a;
		long l;
		public Pair(int a, long l) {
			this.a = a;
			this.l = l;
		}
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