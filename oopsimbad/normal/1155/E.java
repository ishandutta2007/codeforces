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
		long n = 1000003;
		long[][] mat = new long[11][12];
		for(int i = 0; i < 11; i++) {
			mat[i][0] = 1;
			for(int j = 1; j < 11; j++) {
				mat[i][j] = mat[i][j-1] * i % n;
			}
			out.println("? " + i);
			out.flush();
			mat[i][11] = f.nextLong();
		}
		for(int i = 0; i < 10; i++) {
			for(int k = 0; k <= i; k++) {
				long a = mat[k][k], b = mat[i+1][k];
				for(int j = 0; j < 12; j++)
					mat[i+1][j] = ((mat[i+1][j] * a % n - mat[k][j] * b % n) % n + n) % n;
			}
		}
		long[] ans = new long[11];
		for(int i = 10; i >= 0; i--) {
			for(int k = 10; k > i; k--) mat[i][11] = ((mat[i][11] - ans[k] * mat[i][k] % n) % n + n) % n;
			ans[i] = mat[i][11] * modInv(mat[i][i], n) % n;
		}
		long output = -1;
		for(int i = 0; i < n; i++) {
			long cur = 0;
			for(int j = 10; j >= 0; j--)
				cur = (cur * i % n + ans[j]) % n;
			if(cur == 0) {
				output = i;
				break;
			}
		}
		out.println("! " + output);
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