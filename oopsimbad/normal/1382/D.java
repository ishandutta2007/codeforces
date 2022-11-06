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
		int t = f.nextInt();
		while(t-->0) {
			int n = f.nextInt();
			int prev = f.nextInt();
			int cnt = 1;
			ArrayList<Integer> al = new ArrayList<>();
			for(int i = 1; i < 2*n; i++) {
				int a = f.nextInt();
				if(a < prev) cnt++;
				else {
					al.add(cnt);
					cnt = 1;
					prev = a;
				}
			}
			al.add(cnt);
			boolean[][] poss = new boolean[al.size()+1][n+1];
			poss[0][0] = true;
			for(int i = 0; i < al.size(); i++) {
				for(int j = 0; j <= n; j++) {
					poss[i+1][j] |= poss[i][j];
					if(j >= al.get(i)) poss[i+1][j] |= poss[i][j-al.get(i)];
				}
			}
			out.println(poss[al.size()][n] ? "YES" : "NO");
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