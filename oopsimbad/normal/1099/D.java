import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	LinkedList<Integer>[] adj;
	int[] p;
	int[] sums;
	int[] vals;
	boolean pos;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		adj = new LinkedList[n];
		p = new int[n];
		vals = new int[n];
		for(int i = 0; i < n; i++) adj[i] = new LinkedList<Integer>();
		sums = new int[n];
		for(int i = 1; i < n; i++) {
			adj[p[i] = f.nextInt()-1].add(i);
		}
		for(int i = 0; i < n; i++) sums[i] = f.nextInt();
		vals[0] = sums[0];
		pos = true;
		dfs(0);
		long tot = 0;
		for(int i : vals) tot += i;
		if(pos) out.println(tot);
		else out.println(-1);
		out.flush();
	}
	public void dfs(int i) {
		if(sums[i] == -1) {
			if(adj[i].isEmpty()) {
				return;
			}
			int begin = sums[p[i]];
			int minend = 2147483647;
			for(int j : adj[i])
				minend = Math.min(minend, sums[j]);
			if(minend < begin) pos = false;
			vals[i] = minend - begin;
			for(int j : adj[i]) {
				vals[j] = sums[j] - begin - vals[i];
				dfs(j);
			}
			
		} else for(int j : adj[i])
			dfs(j);
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