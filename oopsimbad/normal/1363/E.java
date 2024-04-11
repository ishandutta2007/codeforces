import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	int[] cnt0;
	int[] cnt1;
	int[] c;
	LinkedList<Integer> adj[];
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		adj = new LinkedList[n];
		c = new int[n]; cnt0 = new int[n]; cnt1 = new int[n];
		for(int i = 0; i < n; i++) {
			adj[i] = new LinkedList<>();
			c[i] = f.nextInt();
			int a = f.nextInt(), b = f.nextInt();
			if(a == 0 && b == 1) cnt0[i]++;
			else if(b == 0 && a == 1) cnt1[i]++;
		}
		for(int i = 0; i < n-1; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		long ans = dfs(0, -1, Long.MAX_VALUE);
		if(cnt0[0] + cnt1[0] != 0) out.println(-1);
		else out.println(2*ans);
		out.flush();
	}
	public long dfs(int i, int p, long cost) {
		cost = Math.min(cost, c[i]);
		long ans = 0;
		for(int j : adj[i])
			if(j != p) {
				ans += dfs(j,i,cost);
				cnt0[i] += cnt0[j];
				cnt1[i] += cnt1[j];
			}
		long min = Math.min(cnt0[i], cnt1[i]);
		cnt0[i] -= min; cnt1[i] -= min;
		return ans + cost*min;
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