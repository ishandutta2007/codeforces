import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final int MAX = 5003;

	class Obj implements Comparable<Obj> {
		int minValue;
		int left;
		double[] pr;

		public Obj(int minValue, int left) {
			super();
			this.minValue = minValue;
			this.left = left;
		}

		@Override
		public int compareTo(Obj o) {
			if (left == o.left)
				return Integer.compare(minValue, o.minValue);
			return Integer.compare(left, o.left);
		}

		@Override
		public String toString() {
			return "Obj [minValue=" + minValue + ", left=" + left + ", pr="
					+ Arrays.toString(pr) + "]";
		}

	}

	class Q implements Comparable<Q> {
		int left, right;
		double pr;

		public Q(int left, int right, double pr) {
			super();
			this.left = left;
			this.right = right;
			this.pr = pr;
		}

		@Override
		public int compareTo(Q o) {
			return Integer.compare(right - left, o.right - o.left);
		}

		@Override
		public String toString() {
			return "Q [left=" + left + ", right=" + right + ", pr=" + pr + "]";
		}

	}

	void solve() {
		int n = in.nextInt();
		int q = in.nextInt();
		int[] a = new int[n];
		TreeSet<Obj> all = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
			all.add(new Obj(a[i], i));
		}
		Q[] qu = new Q[q + 1];
		for (int i = 0; i < q; i++) {
			qu[i] = new Q(in.nextInt() - 1, in.nextInt() - 1, in.nextDouble());
		}
		qu[q] = new Q(0, n - 1, 0.0);
		Arrays.sort(qu);
		for (Q curQ : qu) {
			ArrayList<Obj> inside = new ArrayList<>();
			int minVal = -1;
			while (true) {
				Obj o = all.higher(new Obj(-1, curQ.left));
				if (o == null) {
					break;
				}
				if (o.left <= curQ.right) {
					if (o.pr == null) {
						minVal = Math.max(minVal, o.minValue);
					} else {
						inside.add(o);
					}
					all.remove(o);
				} else {
					break;
				}
			}
			for (Obj o : inside) {
				minVal = Math.max(minVal, o.minValue);
			}
			Obj newObj = new Obj(minVal, curQ.left);
			newObj.pr = new double[MAX];
			double[] curSub = new double[inside.size()];
			double cursum = 0;
			for (int i = MAX - 1; i > 0; i--) {
				double prNot = 1.0;
				for (int j = 0; j < inside.size(); j++) {
					int need = minVal + i;
					int id = need - inside.get(j).minValue;
					if (id >= 0 && id < MAX) {
						double curP = inside.get(j).pr[id] + curSub[j];
						curSub[j] = curP;
						prNot *= 1 - curP;
					}
				}
				newObj.pr[i] = 1 - prNot - cursum;
				cursum += newObj.pr[i];
			}
			double sum = 1;
			for (int i = 1; i < MAX; i++) {
				sum -= newObj.pr[i];
			}
			newObj.pr[0] = sum;
			for (int i = MAX - 1; i > 0; i--) {
				newObj.pr[i] += newObj.pr[i - 1] * curQ.pr;
				newObj.pr[i - 1] = newObj.pr[i - 1] * (1 - curQ.pr);
			}
			all.add(newObj);
		}
		Obj o = all.first();
		double result = 0;
		for (int i = 0; i < MAX; i++) {
			result += o.pr[i] * (o.minValue + i);
		}
		out.println(result);
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