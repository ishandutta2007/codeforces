import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt();
			int[] arr = new int[n];
			int[] a = new int[n], b = new int[n];
			for(int i = 0; i < n; i++) {
				arr[i] = f.nextInt();
				a[i] = arr[i]-i;
				b[i] = arr[i]-(n-i-1);
			}
			for(int i = 1; i < n; i++)
				a[i] = Math.min(a[i], a[i-1]);
			for(int i = n-2; i >= 0; i--)
				b[i] = Math.min(b[i], b[i+1]);
			boolean ans = false;
			for(int i = 0; i < n; i++)
				ans |= a[i] >= 0 && b[i] >= 0;
			out.println(ans ? "Yes" : "No");
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