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
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = f.nextInt();
		String s = f.next();
		if(s.length() == 1)
			for(int i = 0; i < n; i++) {
				if(i != 0) out.print(s);
				out.print(arr[i]);
			}
		else if(!s.contains("*")) {
			for(int i = 0; i < n; i++) {
				if(i != 0) out.print("+");
				out.print(arr[i]);
			}
		} else if(!s.contains("+")) {
			boolean stop = false;
			for(int i = 0; i < n; i++) {
				if(!stop && i != 0 && arr[i] == 0) out.print("-");
				else if(i != 0) out.print("*");
				out.print(arr[i]);
			}
		} else {
			int l = 0, r = 0;
			long[] prod = new long[n];
			long[] dp = new long[n];
			int[] prev = new int[n];
			boolean[] plus1 = new boolean[n];
			StringBuilder sb = new StringBuilder();
			while(r < n) {
				while(r < n && arr[r] != 0) r++;
				if(arr[l] == 0) {
					sb.append("0+");
					l = ++r;
					continue;
				}
				prod[l] = arr[l];
				boolean skip = false;
				for(int i = l+1; i < r; i++) {
					prod[i] = arr[i] * prod[i-1];
					if(prod[i] >= 10000000000L) skip = true;
				}
				if(skip) {
					for(int i = l; i < r && arr[i] == 1; i++)
						plus1[i] = true;
					for(int i = r-1; i >= l && arr[i] == 1; i--)
						plus1[i] = true;
						for(int i = l; i < r; i++) {
							if(i != l) 
								sb.append(plus1[i] || plus1[i-1] ? "+" : "*");
							sb.append(arr[i]);
					}
				} else {
					dp[l] = arr[l];
					prev[l] = l-1;
					for(int i = l+1; i < r; i++) {
						if(arr[i] == 1) {
							dp[i] = dp[i-1]+arr[i];
							prev[i] = i;
						} else {
							dp[i] = dp[i-1]+arr[i];
							prev[i] = i;
							for(int j = l-1; j < i; j++) {
								if((j == l-1 ? 0 : dp[j]) + prod[i]/(j == l-1 ? 1 : prod[j]) > dp[i]) {
									dp[i] = (j == l-1 ? 0 : dp[j]) + prod[i]/(j == l-1 ? 1 : prod[j]);
									prev[i] = j;
								}
							}
						}
					}
					int cur = r-1;
					StringBuilder tmp = new StringBuilder();
					while(cur >= l) {
						int nx = prev[cur];
						tmp.append(arr[cur--]);
						while(cur > nx) {
							tmp.append("*");
							tmp.append(arr[cur--]);
						}
						if(cur != l-1) tmp.append("+");
					}
					sb.append(tmp.reverse());
				}
				if(r != n) sb.append("+0");
				sb.append("+");
				l = ++r;
			}
			out.println(sb.substring(0, sb.length()-1));
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