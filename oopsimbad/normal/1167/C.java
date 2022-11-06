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
		p = new int[n]; s = new int[n];
		for(int i = 0; i < n; i++) {
			p[i] = i; s[i] = 1;
		}
		while(m-->0) {
			int k = f.nextInt();
			if(k == 0) continue;
			int a = f.nextInt()-1;
			while(k-->1) {
				int b = f.nextInt()-1;
				union(a,b);
				a = b;
			}
		}
		for(int i = 0; i < n; i++)
			out.print(s[find(i)] + " ");
 		out.flush();
	}
	int[] p, s;
	public int find(int x) {
		if(p[x] == x) return x;
		return p[x] = find(p[x]);
	}
	public void union(int x, int y) {
		x = find(x); y = find(y);
		if(x == y) return;
		if(s[x] <= s[y]) {
			p[x] = y;
			s[y] += s[x];
		} else {
			p[y] = x;
			s[x] += s[y];
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