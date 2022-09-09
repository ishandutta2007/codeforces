import java.io.*;
import java.util.*;

public class CF {

	class V implements Comparable<V>{
		int x, y;

		V(int x, int y) {
			this.x = x;
			this.y = y;
		}

		@Override
		public int compareTo(V o) {
			if (x == o.x)
				return Integer.compare(y, o.y);
			return Integer.compare(x, o.x);
		}
	}
	
	class Seg {
		int fr, to;
		
		Seg(int fr, int to) {
			this.fr = fr;
			this.to = to;
		}

		@Override
		public String toString() {
			return "Seg [fr=" + fr + ", to=" + to + "]";
		}
		
		
	}

	void solve() {
		int n = in.nextInt();
		int m = in.nextInt();
		V[] a = new V[m];
		for (int i = 0; i < m; i++) {
			a[i] = new V(in.nextInt(), in.nextInt());
		}
		Arrays.sort(a);
		ArrayList<Seg> can = new ArrayList<>();
		can.add(new Seg(1, 1));
		int iter = 0;
		int lastX = 0;
		while (true) {
			if (can.size() == 0) {
				out.println(-1);
				return;
			}
			int nextX = lastX + 1;
			if (nextX == n + 1) {
				if (can.get(can.size() - 1).to == n) {
					out.println(n * 2 - 2);
				} else {
					out.println(-1);
				}
				return;
			}
			ArrayList<Integer> nowFail = new ArrayList<>();
			nowFail.add(0);
			while (iter < m && a[iter].x == nextX) {
				nowFail.add(a[iter].y);
				iter++;
			}
			nowFail.add(n + 1);
			if (nowFail.size() == 2) {
				int from = can.get(0).fr;
				can.clear();
				can.add(new Seg(from, n));
				lastX = (iter < m ? a[iter].x - 1 : n);
			} else {
				int nowIter = 0;
				ArrayList<Seg> newCan = new ArrayList<>();
				for (int i = 0; i < nowFail.size() - 1; i++) {
					int okFrom = nowFail.get(i) + 1;
					int okTo = nowFail.get(i + 1) - 1;
					while (nowIter != can.size() && can.get(nowIter).to < okFrom)
						nowIter++;
					if (nowIter != can.size()) {
						okFrom = Math.max(okFrom, can.get(nowIter).fr);
					} else {
						okTo = -1;
					}
					if (okTo < okFrom)
						continue;
					newCan.add(new Seg(okFrom, okTo));
				}
				can = newCan;
				lastX = nextX;
			}
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