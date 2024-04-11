import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {
	FastScanner in;
	PrintWriter out;

	int time;
	ArrayList<Integer>[] g2;
	int[] tIn, tOut;

	void go(int v, int p) {
		tIn[v] = time++;
		for (int to : g2[v]) {
			if (to != p) {
				go(to, v);
			}
		}
		tOut[v] = time - 1;
	}

	boolean isAnc(int x, int y) {
		return tIn[x] <= tIn[y] && tOut[x] >= tIn[y];
	}

	void solve() {
		long START = System.currentTimeMillis();
		final int MOD = (int) 1e9 + 7;
		final long MOD2 = MOD * 1L * MOD;
		final int MAX = (int) 1e5 * 2 + 10;
		BigInteger M = BigInteger.valueOf(MOD);
		int[] inv = new int[MAX];
		for (int i = 1; i < MAX; i++) {
			inv[i] = BigInteger.valueOf(i).modInverse(M).intValue();
		}
		int vv = in.nextInt();
		int q = in.nextInt();

		int[] qType = new int[q];
		int[] qA = new int[q];
		int[] qB = new int[q];
		g2 = new ArrayList[q + 1];
		for (int i = 0; i < q + 1; i++) {
			g2[i] = new ArrayList<>();
		}
		int cc = 1;
		int type1 = 0, type2 = 0;
		for (int i = 0; i < q; i++) {
			qType[i] = in.nextInt();
			if (qType[i] == 1) {
				type1++;
				qA[i] = in.nextInt();
				qB[i] = in.nextInt();
				g2[qA[i] - 1].add(cc);
				cc++;
			} else {
				type2++;
				qA[i] = in.nextInt();
			}
		}
		double coef = (type1 + 0.0) / (type1 + type2);
		final int SQRT = coef > 0.8 ? 1000 : 1000;
		tIn = new int[cc];
		tOut = new int[cc];
		time = 0;
		go(0, -1);
		int n = q + 1;
		int[] v = new int[n];
		v[0] = vv;
		int curN = 1;
		int[] p = new int[n];
		int[][] g = new int[cc][];
		for (int i = 0; i < cc; i++) {
			g[i] = new int[g2[i].size()];
			for (int j = 0; j < g[i].length; j++) {
				g[i][j] = g2[i].get(j);
			}
		}
		int[] gSz = new int[cc];
		int[] lastValue = new int[n];
		lastValue[0] = vv;
		int[] add = new int[n];
		p[0] = -1;
		int[] realValue = new int[n];
		boolean[] alive = new boolean[n];
		int[] mulCnt = new int[n];
		mulCnt[0] = 1;
		boolean[] inter = new boolean[n];
		int[] qInter = new int[n];
		int interSz = 0;
		for (int i = 0; i < q; i++) {
			if (i % SQRT == 0) {
				for (int j = 0; j < curN; j++) {
					lastValue[j] = v[j];
				}
				getRealValues(0, g, gSz, MOD, lastValue, inv,
						realValue, curN);
				for (int j = 0; j < curN; j++) {
					add[j] = 0;
					lastValue[j] = realValue[j];
					alive[j] = true;
					mulCnt[j] = 1;
					if (j != 0) {
						mulCnt[j] = (int) (mulCnt[p[j]] * 1L * (1 + gSz[p[j]]) % MOD);
					}
					inter[j] = false;
				}
				interSz = 0;
				int curNTmp = curN;
				for (int j = i; j < Math.min(q, i + SQRT); j++) {
					if (qType[j] == 1) {
						int par = qA[j] - 1;
						p[curNTmp] = par;
						if (alive[par]) {
							if (!inter[par]) {
								inter[par] = true;
								qInter[interSz++] = par;
							}
						}
						curNTmp++;
					} else {
						int ver = qA[j] - 1;
						if (alive[ver] && !inter[ver]) {
							inter[ver] = true;
							qInter[interSz++] = ver;
						}
					}
				}
			}
			if (qType[i] == 1) {
				v[curN] = qB[i];
				lastValue[curN] = v[curN];
				gSz[p[curN]]++;
				int par = p[curN];
				if (alive[par]) {
					int oldSz = gSz[par];
					long tmpMUL = inv[oldSz] * 1L * (oldSz + 1) % MOD;
					for (int id = 0; id < interSz; id++) {
						int ver = qInter[id];
						if (isAnc(par, ver) && par != ver) {
							mulCnt[ver] = (int) (mulCnt[ver] * tmpMUL % MOD);
						}
					}
				}
				curN++;
				{
					realValue[curN - 1] = lastValue[curN - 1];
					if (!alive[par]) {
						int was = realValue[par];
						long tmp = realValue[par] * 1L * inv[gSz[par]] % MOD
								* (gSz[par] + 1);
						tmp += (gSz[par] + 1) * 1L * qB[i];
						realValue[par] = (int) (tmp % MOD);
						int diff = realValue[par] - was;
						if (diff < 0) {
							diff += MOD;
						}
						par = p[par];
						while (true) {
							diff = (int) (diff * 1L * (1 + gSz[par]) % MOD);
							realValue[par] += diff;
							if (realValue[par] >= MOD) {
								realValue[par] -= MOD;
							}
							if (alive[par]) {
								add[par] = (add[par] + diff);
								if (add[par] >= MOD) {
									add[par] -= MOD;
								}
								break;
							}
							par = p[par];
						}
					} else {
						long tmp = (lastValue[par] + add[par]) * 1L
								* inv[gSz[par]] % MOD * (1 + gSz[par]);
						tmp += qB[i] * 1L * (1 + gSz[par]);
						add[par] = (int) (tmp % MOD - lastValue[par]);
						if (add[par] < 0) {
							add[par] += MOD;
						}
					}
				}

			} else {
				int ver = qA[i] - 1;
				if (!alive[ver]) {
					out.println(realValue[ver]);
				} else {
					long result = lastValue[ver];
					int inver = BigInteger.valueOf(mulCnt[ver]).modInverse(M)
							.intValue();
					for (int id = 0; id < interSz; id++) {
						int vvv = qInter[id];
						if (isAnc(ver, vvv)) {
							long curAdd = (add[vvv] * 1L * mulCnt[vvv] % MOD
									* 1L * inver);
							result += curAdd;
							if (result >= MOD2) {
								result -= MOD2;
							}
						}
					}
					out.println(result % MOD);
				}
			}
		}
		System.err.println(System.currentTimeMillis() - START);
	}

	void getRealValues(int par, int[][] g, int[] gSz, 
			int MOD, int[] lastValue, int[] inv, int[] realValue, int curN) {
		for (int ver = curN - 1; ver >= 0; ver--) {
			int size = gSz[ver] + 1;
			long old = lastValue[ver] * 1L * size;
			for (int j = 0; j < gSz[ver]; j++) {
				int to = g[ver][j];
				old += realValue[to] * 1L * size;
			}
			realValue[ver] = (int) (old % MOD);
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("test.in"));
			out = new PrintWriter(new File("CF.out"));

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