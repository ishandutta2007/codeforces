import java.io.*;
import java.util.*;
import java.math.*;

public class D implements Runnable {

	static Random rand = new Random();

	static class Node {
		Node l;
		Node r;
		int y;
		int x;
		long sum;

		public Node(int x) {
			y = rand.nextInt();
			this.x = x;
			sum = x;
		}

	}

	Node[] split(Node v, int x) {
		if (v == null) {
			return new Node[2];
		}
		Node[] ret;
		if (v.x <= x) {
			ret = split(v.r, x);
			v.r = ret[0];
			ret[0] = v;
		} else {
			ret = split(v.l, x);
			v.l = ret[1];
			ret[1] = v;
		}
		updateSum(ret[0]);
		updateSum(ret[1]);
		return ret;
	}

	Node merge(Node l, Node r) {
		if (l == null) {
			return r;
		}
		if (r == null) {
			return l;
		}
		Node ret;
		if (r.y > l.y) {
			ret = l;
			l.r = merge(l.r, r);
		} else {
			ret = r;
			r.l = merge(l, r.l);
		}
		updateSum(ret);
		return ret;
	}

	static long getSum(Node v) {
		return v == null ? 0 : v.sum;
	}

	static void updateSum(Node v) {
		if (v == null) {
			return;
		}
		v.sum = getSum(v.l) + getSum(v.r) + v.x;
	}

	void solve() {
		int n = nextInt();
		Node[] nodes = new Node[5];
		Node[] nodes2 = new Node[5];
		for (int i = 0; i < n; i++) {
			String op = nextToken();
			if (op.equals("sum")) {
				out.println(getSum(nodes[2]));
			} else if (op.equals("add")) {
				int x = nextInt();
				for (int j = 0; j < 5; j++) {
					Node[] t = split(nodes[j], x);
					nodes[j] = t[0];
					nodes2[j] = t[1];
				}
				int max = -1;
				int best = 0;
				for (int j = 0; j < 5; j++) {
					int e = getMax(nodes[j]);
					if (e > best) {
						best = e;
						max = j;
					}
				}
				max = (max + 1) % 5;
				nodes[max] = merge(nodes[max], new Node(x));
				for (int j = 0; j < 5; j++) {
					nodes[(j + 1) % 5] = merge(nodes[(j + 1) % 5], nodes2[j]);
				}
			} else {
				int x = nextInt();
				for (int j = 0; j < 5; j++) {
					Node[] t = split(nodes[j], x);
					nodes[j] = t[0];
					nodes2[j] = t[1];
				}
				int max = -1;
				int best = 0;
				for (int j = 0; j < 5; j++) {
					int e = getMax(nodes[j]);
					if (e > best) {
						best = e;
						max = j;
					}
				}
				nodes[max] = split(nodes[max], x - 1)[0];
				for (int j = 0; j < 5; j++) {
					nodes[(j + 4) % 5] = merge(nodes[(j + 4) % 5], nodes2[j]);
				}
			}
		}
	}

	static int getMax(Node v) {
		return v == null ? Integer.MIN_VALUE : v.r == null ? v.x : getMax(v.r);
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

	class FastScanner extends BufferedReader {
		StringTokenizer st;
		boolean eof;
		String buf;
		String curLine;
		boolean createST;

		public FastScanner(String fileName) throws FileNotFoundException {
			this(fileName, true);
		}

		public FastScanner(String fileName, boolean createST)
				throws FileNotFoundException {
			super(new FileReader(fileName));
			this.createST = createST;
			nextToken();
		}

		public FastScanner(InputStream stream) {
			this(stream, true);
		}

		public FastScanner(InputStream stream, boolean createST) {
			super(new InputStreamReader(stream));
			this.createST = createST;
			nextToken();
		}

		String nextLine() {
			String ret = curLine;
			if (createST) {
				st = null;
			}
			nextToken();
			return ret;
		}

		String nextToken() {
			if (!createST) {
				try {
					curLine = readLine();
				} catch (Exception e) {
					eof = true;
				}
				return null;
			}
			while (st == null || !st.hasMoreTokens()) {
				try {
					curLine = readLine();
					st = new StringTokenizer(curLine);
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

		public void close() {
			try {
				buf = null;
				st = null;
				curLine = null;
				super.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	public static void main(String[] args) {
		new D().run();
	}
}