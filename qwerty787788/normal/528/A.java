import java.io.*;
import java.util.*;

public class CF_A {
	FastScanner in;
	PrintWriter out;

	int go(int pos, TreeMap<Integer, Integer> cnt, TreeSet<Integer> all) {
		int low = all.lower(pos);
		int hi = all.higher(pos);
		Integer count = cnt.get(hi - low);
		count--;
		if (count == 0) {
			cnt.remove(hi - low);
		} else {
			cnt.put(hi - low, count);
		}
		all.add(pos);
		{
			Integer cc = cnt.get(hi - pos);
			if (cc == null) {
				cc = 0;
			}
			cc++;
			cnt.put(hi - pos, cc);
		}
		{
			Integer cc = cnt.get(pos - low);
			if (cc == null) {
				cc = 0;
			}
			cc++;
			cnt.put(pos - low, cc);
		}
		return cnt.lowerKey(Integer.MAX_VALUE);
	}

	void solve() {
		int w = in.nextInt();
		int h = in.nextInt();
		int n = in.nextInt();
		int[] ans = new int[2];
		ans[0] = w;
		ans[1] = h;
		TreeMap<Integer, Integer> cntH = new TreeMap<>();
		TreeMap<Integer, Integer> cntW = new TreeMap<>();
		TreeSet<Integer> allH = new TreeSet<>();
		TreeSet<Integer> allW = new TreeSet<>();
		allH.add(0);
		allH.add(h);
		allW.add(0);
		allW.add(w);
		cntH.put(h, 1);
		cntW.put(w, 1);
		for (int i = 0; i < n; i++) {
			if (in.next().charAt(0) == 'H') {
				ans[1] = go(in.nextInt(), cntH, allH);
			} else {
				ans[0] = go(in.nextInt(), cntW, allW);
			}
			out.println(ans[0] * 1L * ans[1]);
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("object.in"));
			out = new PrintWriter(new File("object.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
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
		new CF_A().runIO();
	}
}