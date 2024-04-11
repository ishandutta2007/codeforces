import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	class Obj {
		int length;
		int value;

		public Obj(int length, int value) {
			super();
			this.length = length;
			this.value = value;
		}

		@Override
		public String toString() {
			return "Obj [length=" + length + ", value=" + value + "]";
		}

		
	}

	void solve() {
		String s = in.next();
		int n = in.nextInt();
		Obj[] cur = new Obj[10];
		for (int i = 0; i < 10; i++) {
			cur[i] = new Obj(10, i);
		}
		final int MOD = (int) 1e9 + 7;
		String[] x = new String[n];
		for (int i = 0; i < n; i++) {
			x[i] = in.next();
		}
		for (int i = n - 1; i >= 0; i--) {
			String current = x[i];
			int what = current.charAt(0) - '0';
			int len = 1;
			int val = 0;
			for (int j = 3; j < current.length(); j++) {
				int now = current.charAt(j) - '0';
				Obj nowWhat = cur[now];
				val = (int) ((val * 1L * nowWhat.length + nowWhat.value) % MOD);
				len = (int) ((len * 1L * nowWhat.length) % MOD);
			}
			cur[what].value = val;
			cur[what].length = len;
		}
		int result = 0;
		for (int i = 0; i < s.length(); i++) {
			int number = s.charAt(i) - '0';
			result = (int) ((result * 1L * cur[number].length + cur[number].value) % MOD);
		}
		out.println(result);
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}

	public static void main(String[] args) {
		new CF().runIO();
	}
}