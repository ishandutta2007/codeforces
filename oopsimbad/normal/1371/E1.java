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
		int n = f.nextInt(), p = f.nextInt();
		Integer[] arr = new Integer[n];
		for(int i = 0; i < n; i++) arr[i] = f.nextInt();
		Arrays.sort(arr);
		int l = 0, max = 1000000001;
		while(l < max) {
			int m = (l+max)/2;
			boolean ok = true;
			int i = 0;
			int c = 0;
			int cur = m;
			while(i < n) {
				if(arr[i] <= cur) {
					i++;
					c++;
				} else {
					c -= arr[i]-cur;
					cur = arr[i];
					c++;
					i++;
				}
				if(c <= 0) {
					ok = true;
					break;
				}
				ok &= c < p;
			}
			if(!ok) max = m;
			else l = m+1;
		}
		l = 0; int min = 1000000001;
		while(l < min) {
			int m = (l+min)/2;
			boolean ok = true;
			int i = 0;
			int c = 0;
			int cur = m;
			while(i < n) {
				if(arr[i] <= cur) {
					i++;
					c++;
				} else {
					c -= arr[i]-cur;
					cur = arr[i];
					c++;
					i++;
				}
				if(c <= 0) {
					ok = false;
					break;
				}
			}
			if(ok) min = m;
			else l = m+1;
		}
		out.println(Math.max(max-min, 0));
		for(int i = min; i < max; i++)
			out.print(i + " ");
		out.println();
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