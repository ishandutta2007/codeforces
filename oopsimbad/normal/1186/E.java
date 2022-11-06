import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	int psum[][], n, m;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		n = f.nextInt(); m = f.nextInt(); int q = f.nextInt();
		int[][] mat = new int[n][m];
		psum = new int[n+1][m+1];
		for(int i = 0; i < n; i++) {
			char[] c = f.next().toCharArray();
			for(int j = 0; j < m; j++)
				mat[i][j] = c[j] - '0';
		}
		for(int i = 0; i < n; i++)
			for(int j =0 ; j < m ;j++)
				psum[i+1][j+1] = psum[i+1][j] + psum[i][j+1] - psum[i][j] + mat[i][j];
		while(q-->0) {
			int r1 = f.nextInt(), c1 = f.nextInt(), r2 = f.nextInt(), c2 = f.nextInt();
			r1--; c1--;
			out.println(ans(r2,c2) - ans(r2, c1) - ans(r1, c2) + ans(r1, c1));
		}
///
		out.flush(); 
	}
	public long ans(int r, int c) {
		long ar = r/n/2*2*n, ac = c/m/2*2*m;
		long ans = ar * ac / 2;
		ans += ar * (c-ac) / 2;
		ans += (r-ar) * ac / 2;
		int rr = (int) (r - ar), rc = (int) (c - ac);
		long temp = sum(rr, rc);
		if((Long.bitCount(ar/n) + Long.bitCount(ac/m)) % 2 == 1) temp = (long) rr * rc - temp;
		ans += temp;
		return ans;
	}
	public long sum(int r, int c) {
		long ans = 0;
		boolean inv = false;
		if(r >= n) {
			if(c >= m) {
				ans += psum[n][m];
				inv ^= true;
			}
			if(inv) ans += (long) n * (c % m) - psum[n][c%m];
			else ans += psum[n][c%m];
			r -= n;
			inv ^= true;
			if(inv) ans += (long) r * (c%m) - psum[r][c%m];
			else ans += psum[r][c%m];
			inv ^= true;
			if(c >= m) {
				if(inv) ans += (long) r * m - psum[r][m];
				else ans += psum[r][m];
				c -= m;
			}
		} else {
			if(c >= m) {
				if(inv) ans += (long) r * m - psum[r][m];
				else ans += psum[r][m];
				c -= m;
				inv ^= true;
			}
			if(inv) ans += (long) r * (c%m) - psum[r][c%m];
			else ans += psum[r][c%m];
		}
		return ans;
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