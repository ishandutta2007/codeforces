import java.io.*;
import java.util.*;

public class CF {

	int[] pos, l;
	int n;

	class O implements Comparable<O> {
		int pos, l;

		public O(int pos, int l) {
			super();
			this.pos = pos;
			this.l = l;
		}

		@Override
		public int compareTo(O o) {
			return Integer.compare(pos, o.pos);
		}

		@Override
		public String toString() {
			return "O [pos=" + pos + ", l=" + l + "]";
		}

	}

	class Pair {
		int firstFree, lastPos;

		public Pair(int firstFree, int lastPos) {
			super();
			this.firstFree = firstFree;
			this.lastPos = lastPos;
		}

		@Override
		public String toString() {
			return "Pair [firstFree=" + firstFree + ", lastPos=" + lastPos
					+ "]";
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + firstFree;
			result = prime * result + lastPos;
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
			Pair other = (Pair) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (firstFree != other.firstFree)
				return false;
			if (lastPos != other.lastPos)
				return false;
			return true;
		}

		private CF getOuterType() {
			return CF.this;
		}

	}

	HashMap<Pair, Integer> answers = new HashMap<>();

	int getAns(Pair p) {
		if (p.firstFree == n) {
			return 0;
		}
		if (answers.containsKey(p)) {
			return answers.get(p);
		}
		int best = 0;
		for (int i = p.firstFree; i < n; i++) {
			int curAns = a[i].pos - Math.max(a[i].pos - a[i].l, p.lastPos);
			int curRight = a[i].pos;
			int fFree = n;
			for (int j = 0; j < n; j++) {
				if (j == i) {
					continue;
				}
				if (a[j].pos <= p.lastPos) {
					continue;
				}
				if (a[j].pos <= curRight) {
					curAns += Math.max(0, a[j].pos + a[j].l - curRight);
					curRight = Math.max(curRight, a[j].pos + a[j].l);
				} else {
					fFree = j;
					break;
				}
			}
			curAns += getAns(new Pair(fFree, curRight));
			best = Math.max(best, curAns);
		}
		{
			int curAns = 0;
			int curRight = p.lastPos;
			for (int j = 0; j < n; j++) {
				if (a[j].pos <= p.lastPos) {
					continue;
				}
				curAns += Math.max(0,
						a[j].pos + a[j].l - Math.max(curRight, a[j].pos));
				curRight = Math.max(curRight, a[j].pos + a[j].l);
			}
			best = Math.max(best, curAns);
		}
		{
			int i = p.firstFree;
			int curAns = Math.max(0,
					a[i].pos + a[i].l - Math.max(a[i].pos, p.lastPos));
			int curRight = a[i].pos + a[i].l;
			int fFree = n;
			for (int j = 0; j < n; j++) {
				if (j == i) {
					continue;
				}
				if (a[j].pos <= p.lastPos) {
					continue;
				}
				if (a[j].pos <= curRight) {
					curAns += Math.max(0, a[j].pos + a[j].l - curRight);
					curRight = Math.max(curRight, a[j].pos + a[j].l);
				} else {
					fFree = j;
					break;
				}
			}
			curAns += getAns(new Pair(fFree, curRight));
			best = Math.max(best, curAns);
		}
		answers.put(p, best);
		return best;
	}

	O[] a;

	void solve() {
		for (int it = 0; it < 1; it++) {
			// System.err.println("iter = " + it);
			solve123(it);
		}
	}

	Random rnd = new Random(213);

	class Segment {
		int fr, to;

		public Segment(int fr, int to) {
			super();
			this.fr = fr;
			this.to = to;
		}

	}

	int getSum(ArrayList<Segment> all) {
		Collections.sort(all, new Comparator<Segment>() {

			@Override
			public int compare(Segment o1, Segment o2) {
				return Integer.compare(o1.fr, o2.fr);
			}
		});
		int last = Integer.MIN_VALUE;
		int res = 0;
		for (Segment s : all) {
			if (s.fr < last) {
				s.fr = last;
			}
			res += Math.max(0, s.to - s.fr);
			last = Math.max(last, s.to);
		}
		return res;
	}

	void solve123(int it) {
		n = in.nextInt();
		pos = new int[n];
		l = new int[n];
		for (int i = 0; i < n; i++) {
			pos[i] = in.nextInt();
			l[i] = in.nextInt();
			boolean ok = true;
			for (int j = 0; j < i; j++) {
				if (pos[j] == pos[i]) {
					ok = false;
				}
			}
			if (!ok) {
				i--;
			}
		}
		a = new O[n];
		for (int i = 0; i < n; i++) {
			a[i] = new O(pos[i], l[i]);
		}
		Arrays.sort(a);
		answers = new HashMap<>();
		int ans = getAns(new Pair(0, Integer.MIN_VALUE));
		out.println(ans);
		// int cor = 0;
		// for (int st = 0; st < 1 << n; st++) {
		// ArrayList<Segment> all = new ArrayList<>();
		// for (int i = 0; i < n; i++) {
		// if (((1 << i) & st) != 0) {
		// all.add(new Segment(a[i].pos - a[i].l, a[i].pos));
		// } else {
		// all.add(new Segment(a[i].pos, a[i].pos + a[i].l));
		// }
		// }
		// cor = Math.max(cor, getSum(all));
		// }
		// if (cor != ans) {
		// System.err.println("correct = " + cor);
		// System.err.println("my = " + ans);
		// for (int i = 0; i < n; i++) {
		// System.err.println(a[i].pos + " " + a[i].l);
		// }
		// throw new AssertionError();
		// }
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			return null;
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}