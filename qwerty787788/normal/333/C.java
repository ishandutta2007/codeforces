import java.io.*;
import java.util.*;

public class CF {

	void realSolve() throws IOException {
		int k = in.nextInt();
		int n = in.nextInt();
		//long st = System.currentTimeMillis();
		TreeSet<Integer>[] all = new TreeSet[10000];
		for (int x = 0; x <= 9999; x++) {
			int[] val = new int[4];
			val[3] = x % 10;
			val[2] = (x / 10) % 10;
			val[1] = (x / 100) % 10;
			val[0] = (x / 1000) % 10;
			TreeSet<Integer>[][] can = new TreeSet[4][4];
			for (int i = 0; i < 4; i++)
				for (int j = i; j < 4; j++) {
					can[i][j] = new TreeSet<>();
					int value = 0;
					for (int kk = i; kk <= j; kk++)
						value = value * 10 + val[kk];
					can[i][j].add(value);
					can[i][j].add(-value);
				}
			for (int len = 2; len <= 4; len++)
				for (int i = 0; i < 4; i++)
					if (i + len <= 4)
						for (int fPartLen = 1; fPartLen < len; fPartLen++) {
							for (int xx : can[i][i + fPartLen - 1])
								for (int yy : can[i + fPartLen][i + len - 1]) {
									can[i][i + len - 1].add(xx + yy);
									can[i][i + len - 1].add(xx * yy);
								}
						}
			all[x] = can[0][3];
		}
		for (int first = 0; first <= 9999; first++) {
HashSet<Integer> ok = new HashSet<>();
			for (int val : all[first]) {
				int diff = Math.abs(k - val);
if (diff <= 9999 && !ok.contains(diff)) {
out.printf("%04d%04d\n", first, diff);
ok.add(diff);
n--;
}
if (n == 0)
break;
			}
			if (n == 0)
				break;
		}
		//System.err.println(System.currentTimeMillis() - st);
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

		realSolve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}