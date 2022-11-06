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
		///
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt(), k = f.nextInt()+1;
			long ans = Long.MAX_VALUE;
			for(int s = 0; s <= 9; s++) {
				long _9 = 0;
				long _10 = 10;
				for(int a = 0;; a++) {
					int sum = 0;
					for(int b = 0; b < k; b++) {
						if(s+b >= 10) sum += 1 + (s+b)%10;
						else sum += a*9 + s+b;
					}
					if(sum > n || sum < 0) break;
					if(sum == n) {
						ans = Math.min(ans, _9*10+s);
						break;
					}
					if((n - sum) % k == 0) {
						sum = (n - sum) / k;
						long pref = 0;
						long t = 1;
						while(sum > 8) {
							int d = Math.min(9, sum-8);
							pref += d * t;
							t *= 10;
							sum -= d;
						}
						if(sum != 0) pref = pref * 10 + sum;
						ans = Math.min(ans, pref*_10+_9*10+s);
					}
					_10 *= 10;
					_9 = _9*10+9;
				}
			}
			out.println(ans == Long.MAX_VALUE ? -1 : ans);
		}
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