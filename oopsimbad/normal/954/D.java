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
		int n = f.nextInt(), m = f.nextInt(), s = f.nextInt()-1, t = f.nextInt()-1;
		long[][] dists = new long[n][2];
		TreeSet<Integer>[] adj = new TreeSet[n];
		for(int i = 0; i < n; i++) {
			adj[i] = new TreeSet<Integer>();
			Arrays.fill(dists[i], 2147483647);
		}
		for(int i = 0; i < m; i++) {
			int a = f.nextInt()-1;
			int b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		{
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(s);
			q.add(0);
			while(!q.isEmpty()) {
				int a = q.poll();
				int d = q.poll();
				if(dists[a][0] != 2147483647) continue;
				dists[a][0] = d;
				for(int i : adj[a]) {
					q.add(i);
					q.add(d+1);
				}
			}
		}
		{
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(t);
			q.add(0);
			while(!q.isEmpty()) {
				int a = q.poll();
				int d = q.poll();
				if(dists[a][1] != 2147483647) continue;
				dists[a][1] = d;
				for(int i : adj[a]) {
					q.add(i);
					q.add(d+1);
				}
			}
		}
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < n; j++) {
				if(adj[i].contains(j)) continue;
				else if(i != j && dists[i][0]+dists[j][1]+1 >= dists[s][1] && dists[i][1]+dists[j][0]+1 >= dists[s][1]) {
					cnt++;
				}
			}
		}
		out.println(cnt/2);
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