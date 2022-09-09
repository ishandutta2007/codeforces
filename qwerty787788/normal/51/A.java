import java.io.*;
import java.util.*;

public class CF {

	int[] rotate(int[] a) {
		int[] res = new int[a.length];
		for (int i = 0; i < res.length; i++)
			res[i] = a[(i + 1) % res.length];
		return res;
	}

	boolean less(int[] a, int[] b) {
		for (int i = 0; i < a.length; i++) {
			if (a[i] < b[i])
				return true;
			if (a[i] > b[i])
				return false;
		}
		return false;
	}

	class Amulet {
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + Arrays.hashCode(b);
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Amulet other = (Amulet) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (!Arrays.equals(b, other.b))
				return false;
			return true;
		}

		int[] b;

		Amulet() {
			String s1 = in.next();
			String s2 = in.next();
			int[] a = { s1.charAt(0), s1.charAt(1), s2.charAt(1), s2.charAt(0) };
			b = a;
			for (int i = 0; i < 3; i++) {
				a = rotate(a);
				if (less(a, b))
					b = a;
			}
		}

		private CF getOuterType() {
			return CF.this;
		}
	}

	void solve() {
		HashSet<Amulet> hs = new HashSet<>();
		int n = in.nextInt();
		for (int i = 0; i < n; i++) {
			hs.add(new Amulet());
			if (i != n - 1)
				in.next();
		}
		out.println(hs.size());
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