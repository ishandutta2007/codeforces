import java.io.*;
import java.util.*;

public class CF {

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		int MAX = (int) 1e7 + 1;
		int[] div = new int[MAX];
		for (int i = 2; i < MAX; i++)
			div[i] = i;
		ArrayList<Integer> primes = new ArrayList<>();
		for (int i = 2; i < MAX; i++)
			if (div[i] == i) {
				primes.add(i);
				for (int j = 2; j * 1L * i < MAX; j++) {
					div[i * j] = i;
				}
			}
		HashMap<Integer, Integer> primesHM = new HashMap<>();
		for (int i = 0; i < primes.size(); i++)
			primesHM.put(primes.get(i), i);
		int tot = primes.size();
		long[] sum = new long[tot];
		for (int i = 0; i < n; i++) {
			int v = in.nextInt();
			while (v != 1) {
				int max = div[v];
				sum[primesHM.get(max)]++;
				while (v % max == 0) {
					v /= max;
				}
			}
		}
		for (int i = 1; i < tot; i++) {
			sum[i] += sum[i - 1];
		}
		int q = in.nextInt();
		for (int i = 0; i < q; i++) {
			long from = in.nextInt();
			long to = in.nextInt();
			int primeFrom = -1, primeTo = -1;
			{
				int l = -1, r = tot;
				while (r - l > 1) {
					int med = (l + r) >> 1;
					if (primes.get(med) >= from) {
						r = med;
					} else {
						l = med;
					}
				}
				primeFrom = r;
			}
			{
				int l = -1, r = tot;
				while (r - l > 1) {
					int med = (l + r) >> 1;
					if (primes.get(med) <= to) {
						l = med;
					} else {
						r = med;
					}
				}
				primeTo = l;
			}
			long result = sum[primeTo]
					- (primeFrom == 0 ? 0 : sum[primeFrom - 1]);
			out.println(result);
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