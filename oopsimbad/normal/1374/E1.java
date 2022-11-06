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
		ArrayList<Integer> _00 = new ArrayList<>();
		ArrayList<Integer> _01 = new ArrayList<>();
		ArrayList<Integer> _10 = new ArrayList<>();
		ArrayList<Integer> _11 = new ArrayList<>();
		for(int i = 0; i < n; i++) {
			int t = f.nextInt(), a = f.nextInt(), b = f.nextInt();
			if(a == 0 && b == 0) _00.add(t);
			if(a == 1 && b == 0) _10.add(t);
			if(a == 0 && b == 1) _01.add(t);
			if(a == 1 && b == 1) _11.add(t);
		}
		Collections.sort(_11);
		Collections.sort(_01);
		Collections.sort(_10);
		if(Math.min(_10.size(),_01.size()) + _11.size() < k) {
			out.println(-1);
			out.flush();
			return;
		}
		int ans = 2147483647;
		int cur = 0;
		for(int i : _11) cur += i;
		for(int i = 0; i < k-_11.size(); i++)
			cur += _01.get(i)+_10.get(i);
		ans = cur;
		for(int c = _11.size()-1; c >= 0; c--) {
			cur -= _11.get(c);
			if(c < k) {
				if(k-c-1 >= Math.min(_01.size(), _10.size())) break;
				cur += _01.get(k-c-1)+_10.get(k-c-1);
			}
			ans = Math.min(ans, cur);
		}
		out.println(ans);
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