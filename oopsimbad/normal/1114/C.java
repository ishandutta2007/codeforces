import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final int MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		long n = f.nextLong(), b = f.nextLong();
		long lim = (long) Math.ceil(Math.sqrt(b));
		long ans = Long.MAX_VALUE;
		for(int i = 2; i <= b && i <= lim; i++) {
			int cnt = 0;
			while(b % i == 0) {
				cnt++;
				b /= i;
			}
			if(cnt == 0) continue;
			long ocnt = 0;
			long pow = i;
			while(pow <= n) {
				ocnt += n / pow;
				if(n/i < pow) break;
				pow *= i;
			}
			ans = Math.min(ans,  ocnt/cnt);
		}
		if(b != 1) {
			int cnt = 1;
			long ocnt = 0;
			long pow = b;
			while(pow <= n) {
				ocnt += n / pow;
				if(n/b < pow) break;
				pow *= b;
			}
			ans = Math.min(ans,  ocnt/cnt);
		}
		out.println(ans);
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