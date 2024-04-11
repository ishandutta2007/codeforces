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
		while(n-->0) {
			int a = f.nextInt();
			String s = f.next();
			if(a-s.indexOf('8') >= 11 && s.contains("8")) out.println("YES");
			else out.println("NO");
		}
 		out.flush();
	}
	public long modInv(long a, long m) {
		gcd(a, m);
		return (x%m + m) % m;
	}
	long x, y;
	public long gcd(long a, long b) {
		if(a * b == 0) {
			x = 0;
			y = 1;
			return a + b;
		}
		long res = gcd(b%a, a);
		long nx = y - b/a * x;
		long ny = x;
		x = nx;
		y = ny;
		return res;
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