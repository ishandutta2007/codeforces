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
			char[] c = f.next().toCharArray();
			int[] cnt = new int[3];
			for(char cc : c)
				if(cc == 'R') cnt[0]++;
				else if(cc == 'P') cnt[1]++;
				else cnt[2]++;
			char ans = 0;
			if(cnt[0] > cnt[1] && cnt[0] > cnt[2]) ans = 'P';
			else if(cnt[1] > cnt[2]) ans = 'S';
			else ans = 'R';
			for(int i = 0; i < c.length; i++) out.print(ans);
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