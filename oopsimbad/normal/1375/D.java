import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt();
			int[] arr = new int[n];
			for(int i = 0; i < n; i++) arr[i] = f.nextInt();
			int[] cnt = new int[n+1];
			for(int i = 0; i < n; i++) cnt[arr[i]]++;
			ArrayList<Integer> moves = new ArrayList<>();
			boolean[] good = new boolean[n];
			for(int i = 0; i < n; i++) {
				if(good[i]) continue;
				moves.add(i);
				int a = arr[i];
				int nc = 0;
				while(nc <= n && cnt[nc] != 0) nc++;
				cnt[a]--;
				arr[i] = nc;
				cnt[nc]++;
				while(a <= i && !good[a] && cnt[a] == 0) {
					good[a] = true;
					moves.add(a);
					int t = arr[a];
					arr[a] = a;
					cnt[a]++;
					a = t;
					cnt[t]--;
				}
			}
			out.println(moves.size());
			for(int i : moves) out.print(i + 1 + " ");
			out.println();
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