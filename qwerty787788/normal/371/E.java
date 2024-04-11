import java.io.*;
import java.util.*;

public class CF {

	class Metro implements Comparable<Metro> {
		int pos;
		int id;

		Metro(int pos, int id) {
			this.pos = pos;
			this.id = id;
		}

		@Override
		public int compareTo(Metro o) {
			return Integer.compare(pos, o.pos);
		}
	}

	void solve() {
		int n = in.nextInt();
		Metro[] a = new Metro[n];
		for (int i = 0; i < n; i++)
			a[i] = new Metro(in.nextInt(), i);
		Arrays.sort(a);
		int k = in.nextInt();
		long curCnt = 0;
		long curSumToLast = 0;
		long curSumFromFirst = 0;
		int last = 0;
		long curSum = 0;
		for (int i = 0; i < k; i++) {
			// add I
			curSumToLast += (a[i].pos - last) * 1L * curCnt;
			curSumFromFirst += a[i].pos - a[0].pos;
			curSum += curSumToLast;
			last = a[i].pos;
			curCnt++;
		}
		long best = curSum;
		int bestFrom = 0;
		for (int i = k; i < n; i++) {
			// add I
			curSumToLast += (a[i].pos - last) * 1L * curCnt;
			curSum += curSumToLast;
			curSumFromFirst += a[i].pos - a[i - k].pos;
			last = a[i].pos;
			curCnt++;
			// remove i - k
			curSum -= curSumFromFirst;
			curCnt--;
			curSumFromFirst -= curCnt * (a[i - k + 1].pos - a[i - k].pos);
			curSumToLast -= a[i].pos - a[i - k].pos;
			// update answer
			if (curSum < best) {
				best = curSum;
				bestFrom = i - k + 1;
			}
		}
		for (int i = 0; i < k; i++) {
			out.print((a[bestFrom + i].id + 1) + " ");
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