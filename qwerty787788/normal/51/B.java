import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		StringBuilder sb = new StringBuilder();
		while (true) {
			String s = in.next();
			if (s == null)
				break;
			sb.append(s);
		}
		String s = sb.toString();
		ArrayList<Integer> res = new ArrayList<>();
		int MAX = 5000;
		int[] cnt = new int[MAX];
		int count = 0;
		for (int i = 0; i < s.length(); i++) {
			if (i + 6 <= s.length() && s.substring(i, i + 6).equals("<table")) {
				count++;
				cnt[count - 1] = 0;
			}
			if (i + 2 <= s.length() && s.substring(i, i + 2).equals("td")) {
				cnt[count - 1]++;
			}
			if (i + 6 <= s.length() && s.substring(i, i + 6).equals("/table")) {
				res.add(cnt[count - 1] / 2);
				count--;
			}
		}
		Collections.sort(res);
		for (int i = 0; i < res.size(); i++) {
			out.print(res.get(i) + " ");
		}
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