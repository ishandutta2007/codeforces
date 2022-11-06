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
		int[][] cnt = new int[26][26];
		int n = f.nextInt();
		while(n-->0) {
			char[] c = f.next().toCharArray();
			char a = 0, b = 0;
			boolean asdf = false;
			for(char cc : c) {
				if(a == cc || b == cc) continue;
				if(a == 0) a = cc;
				else if(b == 0) b = cc;
				else {
					asdf = true;
					break;
				}
			}
			if(asdf) continue;
			if(b == 0) 
				for(int i =0; i < 26; i++) {
					cnt[a-'a'][i] += c.length;
					if(i != a-'a') cnt[i][a-'a'] += c.length;
				}
			else {
				cnt[a-'a'][b-'a'] += c.length;
				cnt[b-'a'][a-'a'] += c.length;
			}
		}
		int best = 0;
		for(int i = 0; i < 26; i++)
			for(int j = 0; j < 26; j++)
				best = Math.max(best, cnt[i][j]);
		out.println(best);
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