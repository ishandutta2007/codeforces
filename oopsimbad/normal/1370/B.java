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
			int n = f.nextInt();
			int o = 0, e = 0;
			ArrayList<Integer> a = new ArrayList<>();
			ArrayList<Integer> b = new ArrayList<>();
			for(int i = 1; i <= 2*n; i++) {
				int c = f.nextInt();
				if(c%2 == 0) {
					e++;
					a.add(i);
				} else {
					o++;
					b.add(i);
				}
			}
			if(o%2 == 1) {
				a.remove(a.size()-1);
				b.remove(b.size()-1);
			} else if(o == 0) {
				a.remove(a.size()-1);
				a.remove(a.size()-1);
			} else {
				b.remove(b.size()-1);
				b.remove(b.size()-1);
			}
			for(int i = 0; i < a.size(); i+=2)
				out.println(a.get(i) + " "+ a.get(i+1));
			for(int i = 0; i < b.size(); i+=2)
				out.println(b.get(i) + " "+ b.get(i+1));
		}
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