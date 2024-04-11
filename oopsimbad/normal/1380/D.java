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
		int n = f.nextInt(), m = f.nextInt();
		long x = f.nextLong(), k = f.nextLong(), y = f.nextLong();
		int[] a = new int[n];
		for(int i = 0; i < n; i++) a[i] = f.nextInt();
		int prev = 0, pi = 0;
		long ans = 0;
		int i = 0;
		for(int asdf = 0; asdf < m; asdf++) {
			int tar = f.nextInt();
			boolean found = false;
			while(i < n && a[i] != tar) {
				if(a[i] > tar && a[i] > prev) found = true;
				i++;
			}
			if(i == n) {
				ans = -1;
				break;
			}
			if(i-pi < k && found) {
				ans = -1;
				break;
			}
			long len = found ? k : 0;
			if(y*k > x) len = (i-pi)/k*k;
			ans += len/k*x+(i-pi-len)*y;
			prev = tar;
			pi = i+1;
			i++;
		}
		if(ans != -1) {
			boolean found = false;
			while(i < n) {
				if(a[i] > prev) found = true;
				i++;
			}
			if(i-pi < k && found) {
				ans = -1;
			} else {
				long len = found ? k : 0;
				if(y*k > x) len = (i-pi)/k*k;
				ans += len/k*x+(i-pi-len)*y;
			}
		}
		out.println(ans);
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