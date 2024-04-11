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
			char[] a = f.next().toCharArray();
			char[] b = f.next().toCharArray();
			int parity = 0;
			ArrayList<Integer> moves = new ArrayList<>();
			for(int i = 0; i < n; i++) {
				if(i % 2 == 0) {
					if(b[n-i-1] == (a[i/2]^parity))
						moves.add(1);
				} else {
					if(b[n-i-1] == (a[n-i/2-1]^parity))
						moves.add(1);
				}
				moves.add(n-i);
				parity ^= 1;
			}
			out.print(moves.size());
			for(int i  : moves) out.print(" " + i);
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