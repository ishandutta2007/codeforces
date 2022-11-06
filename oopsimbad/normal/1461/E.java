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
		long k = f.nextLong(), l = f.nextLong(), r = f.nextLong();
		k -= l;
		r -= l;
		long t = f.nextLong();
		long x = f.nextLong();
		long y = f.nextLong();
		if(x > y) {
			if(k + y <= r) k += y;
			k -= x;
			out.println(k/(x-y) >= t-1 ? "Yes" : "No");
		} else if(x == y) {
			if(k + y <= r) k += y;
			out.println(k-x >= 0 ? "Yes" : "No");
		} else {
			HashSet<Long> seen = new HashSet<>();
			long d = 0;
			boolean bad = false;
			long bot = r-y;
			if(bot < 0) {
				bad = (k+x-1)/x <= t;
			} else {
				if(k < bot) {
					d = (bot-k+(y-x)-1)/(y-x);
					k += d*(y-x);
				} 
				while(true) {
					long days = (k + x-1 - bot)/x; 
					d += days;
					k = k-days*x;
					if(d > t) break;
					if(!seen.add(k)) break;
					if(k < 0) {
						bad = true;
						break;
					}
					k += y;
				}
			}
			out.println(bad ? "No" : "Yes");
		}
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