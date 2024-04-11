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
			char[] c = f.next().toCharArray();
			int n = c.length;
			int[] a = new int[n+1], b = new int[n+1];
			for(int i = 0; i < n; i++)
				a[i+1] = a[i] + (c[i] - '0');
			for(int i = n-1; i >= 0; i--)
				b[i] = b[i+1] + ('1' - c[i]);
			int min = n, max = 0;
			for(int i = 0; i <= n; i++) {
				min = Math.min(min, a[i]+b[i]);
				max = Math.max(max, a[i]+b[i]);
			}
			out.println(Math.min(min, n-max));
		}
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b, i;
		public Pair(int a, int b, int i) {
			this.a = a;
			this.b = b;
			this.i = i;
		}
		public int compareTo(Pair p) {
			return Integer.compare(b, p.b);
		}
		public String toString() {
			return a + "," + b;
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