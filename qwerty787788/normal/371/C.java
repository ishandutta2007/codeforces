import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		String s = in.next();
		int nb = in.nextInt();
		int ns = in.nextInt();
		int nc = in.nextInt();
		int pb = in.nextInt();
		int ps = in.nextInt();
		int pc = in.nextInt();
		long r = in.nextLong();
		long left = 0, right = (long) 1e15;
		int needB = 0, needS = 0, needC = 0;
		for (int i = 0; i < s.length(); i++) {
			char c = s.charAt(i);
			if (c == 'B')
				needB++;
			if (c == 'S')
				needS++;
			if (c == 'C')
				needC++;
		}
		while (right - left > 1) {
			long med = (left + right) / 2;
			long cost = 0;
			long moreS = Math.max(0, med * needS - ns);
			long moreC = Math.max(0, med * needC - nc);
			long moreB = Math.max(0, med * needB - nb);
			cost += moreS * ps + moreC * pc + moreB * pb;
			if (cost <= r) {
				left = med;
			} else {
				right = med;
			}
		}
		out.println(left);
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