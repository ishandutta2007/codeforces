import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt(), m = f.nextInt(), k = f.nextInt();
			k = Math.min(k, m-1);
			int q = m-k-1;
			int[] arr = new int[n];
			for(int i = 0; i < n; i++) arr[i] = f.nextInt();
			int ans = 0;
			for(int s = 0; s <= k; s++) {
				int e = n-1-(k-s);
				int best = 2147483647;
				for(int i = 0; i <= q; i++) {
					int e2 = e-(q-i);
					best = Math.min(best, Math.max(arr[s+i], arr[e2]));
				}
				ans = Math.max(ans, best);
			}
			out.println(ans);
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