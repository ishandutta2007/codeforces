import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	int[] par, sz;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int r = f.nextInt(), c = f.nextInt();
		par = new int[r+c]; sz = new int[r+c];
		for(int i = 0; i < r+c; i++) {
			par[i] = i;
			sz[i] = 1;
		}
		char[][] input = new char[r][c];
		for(int i = 0; i < r; i++) {
			input[i] = f.next().toCharArray();
			for(int j = 0; j < c; j++)
				if(input[i][j] == '=')
					merge(i, r+j);
		}
		LinkedList<Integer>[] adj = new LinkedList[r+c];
		for(int i = 0; i < r+c; i++)
			adj[i] = new LinkedList<>();
		int[] cnts = new int[r+c];
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++) {
				int a = find(i), b = find(r+j);
				if(input[i][j] == '>') {
					adj[a].add(b);
					cnts[b]++;
				}
				else if(input[i][j] == '<') {
					adj[b].add(a);
					cnts[a]++;
				}
			}
		int[] vals = new int[r+c];
		for(int i = 0; i < r+c; i++)
			vals[i] = 1000000;
		LinkedList<Integer> ll = new LinkedList<Integer>();
		for(int i = 0; i < r+c; i++)
			if(cnts[i] == 0)
				ll.add(i);
		while(!ll.isEmpty()) {
			int i = ll.poll();
			for(int j : adj[i]) {
				vals[j] = vals[i]-1;
				if(--cnts[j] == 0)
					ll.add(j);
			}
		}
		int min = 1000000;
		for(int i = 0; i < r+c; i++)
			min = Math.min(min, vals[i] = vals[find(i)]);
		boolean works = true;
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
				if(input[i][j] == '>')
					works &= works && vals[find(i)] > vals[find(r+j)];
				else if(input[i][j] == '<')
					works &= works && vals[find(i)] < vals[find(r+j)];
		if(works) {
			out.println("Yes");
			for(int i = 0; i < r; i++)
				out.print(vals[i] - min + 1 + " ");
			out.println();
			for(int i = 0; i < c; i++)
				out.print(vals[r+i] - min + 1 + " ");
			out.println();
		} else out.println("No");
		out.flush();
	}
	public void merge(int x, int y) {
		x = find(x); y = find(y);
		if(sz[x] < sz[y])
			par[x] = y;
		else par[y] = x;
	}
	public int find(int x) {
		if(par[x] == x) return x;
		return par[x] = find(par[x]);
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