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
		int[] par = new int[n];
		int[] ccnt = new int[n];
		int[] sz = new int[n];
		Arrays.fill(par, -1);
		for(int i = 0; i < n-1; i++) {
			int p = f.nextInt()-1;
			par[i+1] = p;
			ccnt[p]++;
		}
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>();
		for(int i = 0; i < n; i++)
			if(ccnt[i] == 0) {
				sz[i] = 1;
				if(par[i] != -1) {
					sz[par[i]] += sz[i];
					ccnt[par[i]]--;
				}
				pq.add(new Pair(i,sz[i]));
			}
		int total = 0;
		int maxsize = 0;
		for(int i = 1; i <= n; i++) {
			while(total < i) {
				Pair p = pq.poll();
				maxsize = Math.max(p.b, maxsize);
				total++;
				if(par[p.a] != -1 && ccnt[par[p.a]] == 0) {
					ccnt[par[p.a]] = -123;
					if(par[par[p.a]] != -1) {
						sz[par[par[p.a]]] += sz[par[p.a]];
						ccnt[par[par[p.a]]]--;
					}
					pq.add(new Pair(par[p.a],sz[par[p.a]]));
				}
			}
			out.print(maxsize + " ");
		}
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			return Integer.compare(b, p.b);
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