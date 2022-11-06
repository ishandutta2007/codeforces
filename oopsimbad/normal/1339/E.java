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
		int[][] vals = {{0,0,0},{1,2,3},{2,3,1},{3,1,2}};
		while(asdf-->0) {
			long n = f.nextLong()-1;
			int ind = (int) (n%3);
			n /= 3;
			if(n == 0) out.println(ind+1);
			else {
				long cur = ind+1;
				long pre = 0;
				int i = 0;
				while(pre + (1L << 2L*i) <= n)
					pre += (1L << 2L*i++);
				n -= pre;
				i--;
				while(i >= 0) {
					int v = (int) ((n >> (2L*i))%4);
					cur = (cur << 2) + vals[v][ind];
					n -= (long) v << 2L*i;
					i--;
				}
				out.println(cur);
			}
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