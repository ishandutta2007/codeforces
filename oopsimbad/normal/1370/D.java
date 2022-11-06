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
		int n = f.nextInt(), k = f.nextInt();
		arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = f.nextInt();
		int ans = 2147483647;
		{
			int l = 1, r = 1000000001;
			while(l < r) {
				int m = (l+r)/2;
				if(test1(m,(k+1)/2, k%2 == 0)) r = m;
				else l = m+1;
			}
			ans = Math.min(ans, l);
		}
		{
			int l = 1, r = 1000000001;
			while(l < r) {
				int m = (l+r)/2;
				if(test2(m, k/2, k%2 == 1)) r = m;
				else l = m+1;
			}
			ans = Math.min(ans, l);
		}
		out.println(ans);
///
		out.flush();
	}
	int[] arr;
	public boolean test1(int v, int k, boolean end) {
		int cnt = 0;
		for(int i = 0; i < arr.length-(end ? 1 : 0); i++)
			if(arr[i] <= v) {
				i++;
				cnt++;
			}
		return cnt >= k;
	}
	public boolean test2(int v, int k, boolean end) {
		int cnt = 0;
		for(int i = 1; i < arr.length-(end ? 1 : 0); i++)
			if(arr[i] <= v) {
				i++;
				cnt++;
			}
		return cnt >= k;
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