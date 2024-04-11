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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt(), m = f.nextInt();
			int a = f.nextInt()-1, b = f.nextInt()-1, c = f.nextInt()-1;
			Long[] arr = new Long[m];
			for(int i = 0; i < m; i++)
				arr[i] = f.nextLong();
			Arrays.sort(arr);
			long[] psum = new long[m+1];
			for(int i = 0; i < m; i++)
				psum[i+1] = psum[i]+arr[i];
			LinkedList<Integer>[] adj = new LinkedList[n];
			int[][] dist = new int[n][3];
			for(int i = 0; i < n; i++) {
				adj[i] = new LinkedList<>();
				dist[i][0] = dist[i][1] = dist[i][2] = 2147483647;
			}
			for(int i = 0; i < m; i++) {
				int p = f.nextInt()-1;
				int q = f.nextInt()-1;
				adj[p].add(q);
				adj[q].add(p);
			}
			LinkedList<Integer> q = new LinkedList<>();
			{
				dist[a][0] = 0;
				q.add(a);
				while(!q.isEmpty()) {
					int i = q.poll();
					for(int j : adj[i])
						if(dist[j][0] == 2147483647) {
							dist[j][0] = dist[i][0]+1;
							q.add(j);
						}
				}
			}
			{
				dist[b][1] = 0;
				q.add(b);
				while(!q.isEmpty()) {
					int i = q.poll();
					for(int j : adj[i])
						if(dist[j][1] == 2147483647) {
							dist[j][1] = dist[i][1]+1;
							q.add(j);
						}
				}
			}
			{
				dist[c][2] = 0;
				q.add(c);
				while(!q.isEmpty()) {
					int i = q.poll();
					for(int j : adj[i])
						if(dist[j][2] == 2147483647) {
							dist[j][2] = dist[i][2]+1;
							q.add(j);
						}
				}
			}
			long bestans = Long.MAX_VALUE;
			for(int i = 0; i < n; i++)
				if(dist[i][0]+dist[i][1]+dist[i][2] <= m) bestans = Math.min(psum[dist[i][0]+dist[i][1]+dist[i][2]]+psum[dist[i][1]], bestans);
			out.println(bestans);
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