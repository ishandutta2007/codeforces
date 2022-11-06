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
		int n = f.nextInt();
		int[] a = new int[n], b = new int[n];
		int[] s = new int[10000001];
		for(int i = 2; i < s.length; i++) {
			if(s[i] != 0) continue;
			for(int j = i; j < s.length; j += i) s[j] = i;
		}
		for(int asdf = 0; asdf < n; asdf++) {
			a[asdf] = b[asdf] = -1;
			int k = f.nextInt();
			int i = s[k];
			int p = 1;
			int q = k;
			while(q%i == 0) {
				q /= i;
				p *= i;
			}
			if(q != 1) {
				a[asdf] = q;
				b[asdf] = p;
			}
		}
		for(int i = 0; i < n; i++) out.print(a[i] + " ");
		out.println();
		for(int i = 0; i < n; i++) out.print(b[i] + " ");
		out.println();
		out.flush();
///
		out.flush();
	}
///
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