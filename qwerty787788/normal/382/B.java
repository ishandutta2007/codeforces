import java.io.*;
import java.util.*;

public class CF {

	HashMap<Long, Long> lastMove = new HashMap<>();
	HashMap<Long, Long> wasDiff = new HashMap<>();

	long getAns(long a, long b, long w, long x, long c, long nowMove) {
//		System.err.println(a+" " + b + " " + w + " " + x + " " + c + " " + nowMove);
		wasDiff.put(nowMove, c - a);
		if (c<=a)
			return nowMove;
		Long lastMoveWithSameB = lastMove.get(b);
		if (lastMoveWithSameB != null) {
			long wasD = wasDiff.get(lastMoveWithSameB);
			long changed = wasD - (c - a);
			long canDoMore = (c - a - 1) / changed;
			if (canDoMore > 0) {
				nowMove += canDoMore * (nowMove - lastMoveWithSameB);
				c -= canDoMore * changed;
			}
		}
		lastMove.put(b, nowMove);
		if (b >= x) {
			b = b - x;
		} else {
			a--;
			b = w - (x - b);
		}
		c--;
		nowMove++;
		return getAns(a, b, w, x, c, nowMove);
	}

	void solve() {
		out.println(getAns(in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), in.nextInt(), 0));
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
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
}