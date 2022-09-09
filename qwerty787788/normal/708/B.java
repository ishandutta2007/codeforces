import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final String imp = "Impossible";

	void solve() {
		long a00 = in.nextLong(), a01 = in.nextLong(), a10 = in.nextLong(), a11 = in
				.nextLong();
		long[] need = new long[] { a00, a01, a10, a11 };
		long sum = a00 + a01 + a10 + a11;
		long cnt0 = 0;
		while (cnt0 * (cnt0 - 1) / 2 < a00) {
			cnt0++;
		}
		long cnt1 = 0;
		while (cnt1 * (cnt1 - 1) / 2 < a11) {
			cnt1++;
		}
		long len = 1;
		while (len * (len - 1) / 2 < sum) {
			len++;
		}
		if (cnt0 * (cnt0 - 1) / 2 != a00 || cnt1 * (cnt1 - 1) / 2 != a11
				|| len * (len - 1) / 2 != sum) {
			out.println(imp);
			return;
		}
		if (a00 == 0 && a01 == 0 && a10 == 0 && a11 == 0) {
			out.println("0");
			return;
		}
		if (a00 == 0 && cnt0 + cnt1 < len) {
			cnt0++;
		}
		if (a11 == 0 && cnt0 + cnt1 < len) {
			cnt1++;
		}
		if (cnt0 < 0 || cnt0 > len || cnt1 < 0 || cnt1 > len) {
			out.println(imp);
			return;
		}
		char[] res = new char[(int) len];
		for (int cnt1Left = 0; cnt1Left <= cnt1; cnt1Left++) {
			long minC10 = cnt1Left * cnt0;
			long maxC10 = (cnt1Left + 1) * cnt0;
			if (minC10 > a10 || maxC10 < a10) {
				continue;
			}
			long maxC01 = cnt0 * (cnt1 - cnt1Left);
			long minC01 = cnt0 * (cnt1 - cnt1Left - 1);
			if (minC01 > a01 || maxC01 < a01) {
				continue;
			}
			Arrays.fill(res, '1');
			int now0 = (int) (cnt0 - (a10 - minC10));
			for (int j = 0; j < now0; j++) {
				res[cnt1Left + j] = '0';
			}
			for (int j = now0; j < cnt0; j++) {
				res[cnt1Left + j + 1] = '0';
			}
			if (Arrays.equals(calc(res), need)) {
				for (int i = 0; i < res.length; i++) {
					out.print(res[i]);
				}
				out.println();
				return;
			}
			out.println(imp);
			return;
		}
		out.println(imp);

	}

	long[] calc(char[] a) {
		long[] res = new long[4];
		// a00, a01, a10, a11
		long cnt0 = 0, cnt1 = 0;
		for (int i = 0; i < a.length; i++) {
			if (a[i] == '0') {
				res[0] += cnt0;
				res[2] += cnt1;
				cnt0++;
			} else {
				res[1] += cnt0;
				res[3] += cnt1;
				cnt1++;
			}
		}
		return res;
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
		new CF().runIO();
	}
}