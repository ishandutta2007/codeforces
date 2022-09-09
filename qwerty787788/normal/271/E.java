import java.io.*;
import java.util.*;

public class CF271 {
	FastScanner in;
	PrintWriter out;

	int gcd(int x, int y) {
		return x == 0 ? y : gcd(y % x, x);
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++)
			a[i] = in.nextInt() - 1;
		int g = a[0];
		for (int i = 1; i < n; i++)
			g = gcd(g, a[i]);
		while (g % 2 == 0)
			g /= 2;
		ArrayList<Integer> primes = new ArrayList<Integer>();
		int it = 3;
		while (it * it <= g) {
			while (g % it == 0) {
				primes.add(it);
				g /= it;
			}
			it++;
		}
		if (g != 1)
			primes.add(g);
		long ans = 0;
		HashSet<Integer> was = new HashSet<Integer>();
		for (int st = 0; st < (1 << primes.size()); st++) {
			int dif = 1;
			for (int i = 0; i < primes.size(); i++)
				if (((1 << i) & st) != 0)
					dif *= primes.get(i);
			if (was.contains(dif))
				continue;
			was.add(dif);
			while (dif < m) {
				ans += m - dif;
				dif *= 2;
			}
		}
		out.println(ans);
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
	}

	public static void main(String[] args) {
		new CF271().runIO();
	}
}