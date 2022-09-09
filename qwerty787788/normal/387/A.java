import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		String[] s1 = in.next().split(":");
		String[] s2 = in.next().split(":");
		int h = Integer.parseInt(s1[0]) - Integer.parseInt(s2[0]);
		int min = Integer.parseInt(s1[1]) - Integer.parseInt(s2[1]);
		if (min < 0) {
			min += 60;
			h--;
		}
		if (h < 0)
			h += 24;
		String hh = Integer.toString(h);
		if (hh.length() == 1)
			hh = "0" + hh;
		String mm = Integer.toString(min);
		if (mm.length() == 1)
			mm = "0" + mm;
		out.println(hh + ":" + mm);
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