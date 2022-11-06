import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	LinkedList<Integer> c[];
	int[] par;
	PrintWriter out;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		out = new PrintWriter(System.out);
		int n = f.nextInt();
		c = new LinkedList[2*n-1];
		par = new int[2*n - 1];
		for(int i = 0; i < 2*n - 1; i++) {
			c[i] = new LinkedList<Integer>();
			par[i] = i;
		}
		for(int i = n; i < 2*n-1; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			c[i].add(a = find(a));
			c[i].add(b = find(b));
			par[a] = par[b] = i;
		}
		recur(2*n-2);
		out.flush();
	}
	public int find(int x) {
		if(par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	public void recur(int i) {
		if(i <= par.length/2) out.print(i + 1 + " ");
		else {
			for(int j : c[i])
				recur(j);
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