import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {
	public static void main(String[] args) {
		new C().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	int cur;

	Node root;

	class Node {
		Node l, r;

	}

	char[] c = new char[1001];
	int cc;

	void go(Node v, int len) {
		if (cur < 0) {
			return;
		}
		if (len == a[cur]) {
			if (hm.containsKey(len)) {
				hm.get(len).add(new String(c, 0, len));
			} else {
				ArrayList<String> t = new ArrayList<String>();
				t.add(new String(c, 0, len));
				hm.put(len, t);
			}
			cur--;
			return;
		}
		while (true) {
			if (v.l == null) {
				v.l = new Node();
				c[cc++] = '0';
				go(v.l, len + 1);
				cc--;
			} else if (v.r == null) {
				v.r = new Node();
				c[cc++] = '1';
				go(v.r, len + 1);
				cc--;
			} else {
				return;
			}
			if (cur < 0) {
				return;
			}
			if (a[cur] <= len) {
				return;
			}
		}
	}

	HashMap<Integer, ArrayList<String>> hm;
	int[] a;

	void solve() {
		int n = nextInt();
		a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		hm = new HashMap<Integer, ArrayList<String>>();
		int[] b = a.clone();
		Arrays.sort(a);
		cur = a.length - 1;
		cc = 0;
		root = new Node();
		go(root, 0);
		ArrayList<String> ans = new ArrayList<String>();
		for (int i = 0; i < b.length; i++) {
			ArrayList<String> t = hm.get(b[i]);
			if (t == null || t.isEmpty()) {
				out.println("NO");
				return;
			}
			ans.add(t.get(t.size() - 1));
			t.remove(t.size() - 1);
		}
		out.println("YES");
		for (String s : ans) {
			out.println(s);
		}
	}
}