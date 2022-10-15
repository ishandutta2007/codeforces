import java.io.*;
import java.util.*;
import java.math.*;

public class C implements Runnable {

	ArrayList<HashMap<String, Integer>> array;
	ArrayList<Integer> files;
	ArrayList<Integer> folders;

	void solve() {
		array = new ArrayList<HashMap<String, Integer>>();
		files = new ArrayList<Integer>();
		folders = new ArrayList<Integer>();
		array.add(new HashMap<String, Integer>());
		files.add(0);
		folders.add(0);
		HashSet<Integer> foldersSet = new HashSet<Integer>();
		while (!sc.isEOF()) {
			String[] t = nextToken().split("\\Q\\\\E");
			HashMap<String, Integer> set = array.get(0);
			for (int i = 0; i < t.length; i++) {
				if (!set.containsKey(t[i])) {
					set.put(t[i], array.size());
					array.add(new HashMap<String, Integer>());
					files.add(i == t.length - 1 ? 1 : 0);
					folders.add(i == t.length - 1 ? 0 : 1);
				}
				int p = set.get(t[i]);
				set = array.get(p);
				if (i != t.length - 1 && i != 0) {
					foldersSet.add(p);
				}
			}
		}
		for (int i = files.size() - 1; i >= 0; i--) {
			HashMap<String, Integer> set = array.get(i);
			for (String e : set.keySet()) {
				int p = files.get(set.get(e));
				files.set(i, files.get(i) + p);
			}
		}
		for (int i = folders.size() - 1; i >= 0; i--) {
			HashMap<String, Integer> set = array.get(i);
			for (String e : set.keySet()) {
				int p = folders.get(set.get(e));
				folders.set(i, folders.get(i) + p);
			}
		}
		int ans1 = 0;
		int ans2 = 0;
		for (int i : foldersSet) {
			ans2 = Math.max(ans2, files.get(i));
			ans1 = Math.max(ans1, folders.get(i) - 1);
		}
		out.println(ans1 + " " + ans2);
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