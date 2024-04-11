import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt();
		Integer[] b = new Integer[n];
		for (int i = 0; i < n; i++)
			b[i] = a[i];
		Arrays.sort(b);
		HashMap<Integer, Integer> hm = new HashMap<>();
		for (int i = 0; i < n; i++)
			hm.put(b[i], i);
		for (int i = 0; i < n; i++)
			a[i] = hm.get(a[i]);
		int start = -1;
		for (int i = 0; i < n; i++)
			if (a[i] != i) {
				start = i;
				break;
			}
		if (start == -1) {
			out.println("yes");
			out.println("1 1");
			return;
		}
		int end = -1;
		for (int i = 0; i < n; i++)
			if (a[i] == start) {
				end = i;
				break;
			}
		for (int left = start, right = end; left < right; left++, right--) {
			int tmp = a[left];
			a[left] = a[right];
			a[right] = tmp;
		}
		for (int i = 0; i < n; i++)
			if (a[i] != i) {
				out.println("no");
				return;
			}
		out.println("yes");
		out.println((start + 1) + " " + (end + 1));
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