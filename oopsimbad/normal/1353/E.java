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
			int n = f.nextInt(), k = f.nextInt();
			int[] _0 = new int[n];
			int[] _1 = new int[n];
			int[] min = new int[n];
			int tot = 0;
			char[] c = f.next().toCharArray();
			for(int i = 0; i < n; i++) {
				if(i >= k) {
					_0[i] = _0[i-k];
					_1[i] = _1[i-k];
					min[i] = min[i-k];
				}
				if(c[i] == '0') _0[i]++;
				else {
					tot++;
					_1[i]++;
				}
				min[i] = Math.min(min[i], _1[i]-_0[i]);
			}
			int best = n;
			for(int i = 0; i < n; i++)
				best = Math.min(best, tot+_0[i]+min[i]-_1[i]);
			out.println(best);
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