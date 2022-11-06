import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	char[] carr;
	LinkedList<Integer>[] adj;
	LinkedList<Integer> ll;
	boolean works;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int en = f.nextInt();
		carr = f.next().toCharArray();
		adj = (LinkedList<Integer>[]) new LinkedList[n];
		for(int i = 0; i < n; i++)
			adj[i] = new LinkedList<Integer>();
		int[] indeg = new int[n];
		works = true;
		ll = new LinkedList<Integer>();
		for(int i = 0; i < en; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b);
			indeg[b]++;
		}
		visited = new int[n];
		for(int i = 0; i < n; i++)
			if(visited[i] == 0 && indeg[i] == 0) toposort(i);
		if(!works || ll.size() != n) {
			out.println(-1);
		}
		else {
			int max = 0;
			int[][] dp = new int[n][26];
			for(int i : ll) {
				max = Math.max(max, ++dp[i][carr[i]-'a']);
				for(int j : adj[i])
					for(int k = 0; k < 26; k++)
						dp[j][k] = Math.max(dp[j][k], dp[i][k]);
			}
			out.println(max);
		}
		out.flush();
	}
	int[] visited;
	public void toposort(int cur) {
		if(visited[cur] == 1) works = false;
		else if(visited[cur] == 0) {
			visited[cur] = 1;
			for(int i : adj[cur]) toposort(i);
			ll.addFirst(cur);
			visited[cur] = 2;
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