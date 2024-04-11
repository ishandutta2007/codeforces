import java.io.*;
import java.util.*;

public class CF {

	boolean isGeometric(int[] a) {
		if (a.length == 1)
			return true;
		int first = a[0];
		if (first == 0) {
			for (int j = 1; j < a.length; j++)
				if (a[j] != 0)
					return false;
			return true;
		}
		int mul = a[1], div = a[0];
		for (int j = 1; j < a.length - 1; j++) {
			int from = a[j];
			int to = a[j + 1];
			if (from * mul != to * div)
				return false;
		}
		return true;
	}

	boolean isGeometricWithoutOne(int[] a) {
		if (a.length == 1)
			return true;
		int first = a[0];
		if (first == 0) {
			int cnt = 0;
			for (int j = 1; j < a.length; j++)
				if (a[j] != 0)
					cnt++;
			return cnt <= 1;
		}
		int mul = a[1], div = a[0];
		int cnt = 0;
		for (int j = 1; j < a.length - 1; j++) {
			int from = a[j];
			int to = a[j + 1];
			if (from * mul != to * div) {
				if (cnt == 1)
					return false;
				cnt = 1;
				if (j + 1 == a.length - 1)
					return true;
				to = a[j + 2];
				if (from * mul != to * div)
					return false;
				j++;
			}
		}
		return true;
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		if (isGeometric(a)) {
			out.println(0);
			return;
		}
		if (isGeometricWithoutOne(a)) {
			out.println(1);
			return;
		}
		{
			int[] b = new int[a.length - 1];
			for (int j = 0; j < b.length; j++)
				b[j] = a[j + 1];
			b[0] = a[0];
			if (isGeometric(b)) {
				out.println(1);
				return;
			}
		}
		{
			int[] b = new int[a.length - 1];
			for (int j = 0; j < b.length; j++)
				b[j] = a[j + 1];
			if (isGeometric(b)) {
				out.println(1);
				return;
			}
		}
		out.println(2);
		return;
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