import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	static class Node {
		Node l;
		Node r;
		int x;
		boolean isLeaf;
		long sum;
		int max;
		int min;
		int path;

		public Node(int x) {
			sum = max = min = this.x = x;
			isLeaf = true;
		}
	}

	static void setChild(Node v, Node c) {
		if (v == null || c == null) {
			return;
		}
		v.isLeaf = false;
		if (v.x < c.x) {
			v.r = c;
		} else {
			v.l = c;
		}
	}

	static void countMinMax(Node v) {
		if (v.isLeaf) {
			return;
		}
		countMinMax(v.r);
		countMinMax(v.l);
		v.max = v.r.max;
		v.min = v.l.min;
	}

	static void countSum(Node v, long gotSum, int path) {
		if (v.isLeaf) {
			v.sum = gotSum;
			v.path = path;
			return;
		}
		countSum(v.l, gotSum + v.r.min, path + 1);
		countSum(v.r, v.l.max + gotSum, path + 1);
	}

	void solve() {
		int n = nextInt();
		Node[] nodes = new Node[n];
		int[] parents = new int[n];
		Map<Integer, Node> where = new HashMap<Integer, Node>();
		NavigableSet<Integer> what = new TreeSet<Integer>();
		for (int i = 0; i < n; i++) {
			parents[i] = nextInt();
			nodes[i] = new Node(nextInt());
			where.put(nodes[i].x, nodes[i]);
			what.add(nodes[i].x);
		}
		Node root = null;
		for (int i = 0; i < n; i++) {
			if (parents[i] == -1) {
				root = nodes[i];
				continue;
			}
			setChild(nodes[parents[i] - 1], nodes[i]);
		}
		countMinMax(root);
		countSum(root, 0, 0);
		int k = nextInt();
		for (int i = 0; i < k; i++) {
			int x = nextInt();
			Integer left = what.floor(x);
			Integer right = what.ceiling(x);
			if (left != null && where.get(left).isLeaf) {
				Node node = where.get(left);
				out.println(node.sum * 1. / node.path);
			} else {
				Node node = where.get(right);
				out.println(node.sum * 1. / node.path);
			}
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
		new C().run();
	}
}