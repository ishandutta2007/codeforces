import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class C {
	FastScanner in;
	PrintWriter out;

	void solve() {
		int n = in.nextInt();
		HashMap<String, ArrayList<String>> hm = new HashMap<>();
		HashSet<String> was = new HashSet<>();
		for (int i = 0; i < n; i++) {
			String s = in.next();
			if (was.contains(s)) {
				continue;
			}
			was.add(s);
			int pos = s.indexOf("/", 7);
			if (pos == -1) {
				pos = s.length();
			}
			String hostname = s.substring(0, pos);
			String path = s.substring(pos);
			ArrayList<String> get = hm.get(hostname);
			if (get == null) {
				get = new ArrayList<>();
				hm.put(hostname, get);
			}
			get.add(path);
		}
		Random rnd = new Random();
		long mod = BigInteger.valueOf((long) (1e15 + rnd.nextInt((int) 1e8)))
				.nextProbablePrime().longValue();
		HashMap<Long, ArrayList<String>> result = new HashMap<>();
		int res = 0;
		for (Map.Entry<String, ArrayList<String>> entry : hm.entrySet()) {
			Collections.sort(entry.getValue());
			long hash = 0;
			for (String s : entry.getValue()) {
				for (Character c : s.toCharArray()) {
					hash = (hash * 239 + c) % mod;
				}
				hash = (hash * 239 + 123) % mod;
			}
			ArrayList<String> get = result.get(hash);
			if (get == null) {
				get = new ArrayList<>();
				result.put(hash, get);
			}
			get.add(entry.getKey());
			if (get.size() == 2) {
				res++;
			}
		}
		out.println(res);
		for (Map.Entry<Long, ArrayList<String>> entry : result.entrySet()) {
			if (entry.getValue().size() > 1) {
				for (String s : entry.getValue()) {
					out.print(s + " ");
				}
				out.println();
				res--;
			}
		}
		if (res != 0) {
			throw new AssertionError();
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
		new C().runIO();
	}
}