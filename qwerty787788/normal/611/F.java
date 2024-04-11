import java.io.*;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	final int MAX = (int) (5e5 + 100);

	void solve() {
		int n = in.nextInt();
		int h = in.nextInt();
		int w = in.nextInt();
		char[] a = in.next().toCharArray();
		String dir = "UDLR";
		int[] dh = new int[] { 1, -1, 0, 0 };
		int[] dw = new int[] { 0, 0, -1, 1 };
		int[] prefH = new int[n + 1];
		int[] prefW = new int[n + 1];
		int curH = 0, curW = 0;
		for (int i = 0; i < n; i++) {
			int d = dir.indexOf(a[i]);
			curH += dh[d];
			curW += dw[d];
			prefH[i + 1] = curH;
			prefW[i + 1] = curW;
		}
		ArrayList<Integer>[] posH = new ArrayList[MAX * 2 + 1];
		ArrayList<Integer>[] posW = new ArrayList[MAX * 2 + 1];
		for (int i = 0; i <= n; i++) {
			curH = prefH[i] + MAX;
			curW = prefW[i] + MAX;
			if (posH[curH] == null) {
				posH[curH] = new ArrayList<>();
			}
			if (posW[curW] == null) {
				posW[curW] = new ArrayList<>();
			}
			posH[curH].add(i);
			posW[curW].add(i);
		}
		final int mod = (int) 1e9 + 7;
		long totalS = 0;
		long res = 0;
		int sPos = 0;
		int sizeH = 1, sizeW = 1;
		curH = 0;
		curW = 0;
		long curLen = 0;
		while (totalS < h * 1L * w) {
			long nextEvent = Long.MAX_VALUE;
			{
				long nextUp = getNextEvent(-curH - 1, sPos, posH, prefH);
				if (nextUp < nextEvent) {
					nextEvent = nextUp;
				}
			}
			{
				long nextDown = getNextEvent(sizeH - curH, sPos, posH, prefH);
				if (nextDown < nextEvent) {
					nextEvent = nextDown;
				}
			}
			{
				long nextLeft = getNextEvent(-curW - 1, sPos, posW, prefW);
				if (nextLeft < nextEvent) {
					nextEvent = nextLeft;
				}
			}
			{
				long nextRight = getNextEvent(sizeW - curW, sPos, posW, prefW);
				if (nextRight < nextEvent) {
					nextEvent = nextRight;
				}
			}
			if (nextEvent == Long.MAX_VALUE) {
				out.println(-1);
				return;
			}
			int[] dd = getDiff(prefH, prefW, sPos, nextEvent);
			sPos = (int) ((sPos + nextEvent) % n);
			curLen = (curLen + nextEvent) % mod;
			curH += dd[0];
			curW += dd[1];
			if (curH < 0 || curH == sizeH) {
				curH = Math.max(0, curH);
				sizeH++;
				long sq = w - sizeW + 1;
				res = (res + sq * 1L * curLen) % mod;
				totalS += sq;
			}
			if (curW < 0 || curW == sizeW) {
				curW = Math.max(curW, 0);
				sizeW++;
				long sq = h - sizeH + 1;
				res = (res + sq * 1L * curLen) % mod;
				totalS += sq;
			}
			if (sizeH > h || sizeW > w) {
				break;
			}
		}
		if (totalS != h * 1L * w) {
			throw new AssertionError();
		}
		out.println(res % mod);
	}

	int[] getDiff(int[] prefH, int[] prefW, int pos, long len) {
		int n = prefH.length - 1;
		int[] res = new int[2];
		int add = (int) Math.min(len, n - pos);
		len -= add;
		res[0] += prefH[pos + add] - prefH[pos];
		res[1] += prefW[pos + add] - prefW[pos];
		pos += add;
		if (pos == n) {
			pos = 0;
			int total = (int) (len / n);
			res[0] += prefH[n] * total;
			res[1] += prefW[n] * total;
			len %= n;
		}
		res[0] += prefH[(int) len];
		res[1] += prefW[(int) len];
		return res;
	}

	long getNextEvent(int needDX, int curSPos, ArrayList<Integer>[] pos,
			int[] pref) {
		{
			int need = pref[curSPos] + needDX + MAX;
			if (need >= 0 && need < pos.length) {
				ArrayList<Integer> all = pos[need];
				if (all != null) {
					int left = -1, right = all.size();
					while (right - left > 1) {
						int mid = (left + right) / 2;
						if (all.get(mid) >= curSPos) {
							right = mid;
						} else {
							left = mid;
						}
					}
					if (right != all.size()) {
						return all.get(right) - curSPos;
					}
				}
			}
		}
		int shift = pref[pref.length - 1] - pref[curSPos];
		int n = pref.length - 1;
		long dLen = n - curSPos;
		needDX -= shift;
		{
			int need = needDX + MAX;
			if (need >= 0 && need < pos.length && pos[need] != null) {
				ArrayList<Integer> all = pos[need];
				if (all.size() != 0) {
					return dLen + all.get(0);
				}
			}
		}
		int dxForAll = pref[n];
		if (dxForAll <= 0 && needDX > 0) {
			return Long.MAX_VALUE;
		}
		if (dxForAll >= 0 && needDX < 0) {
			return Long.MAX_VALUE;
		}
		while (true) {
			dLen += n;
			needDX -= dxForAll;
			int need = needDX + MAX;
			if (need >= 0 && need < pos.length && pos[need] != null) {
				ArrayList<Integer> all = pos[need];
				if (all.size() != 0) {
					return dLen + all.get(0);
				}
			}
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
		new CF().runIO();
	}
}