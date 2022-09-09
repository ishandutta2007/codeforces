import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

	long mod = (long) 1e9 + 7;
	long[][] c;
	int MAX = 55;
	long div2 = BigInteger.valueOf(2).modInverse(BigInteger.valueOf(mod))
			.longValue();

	void prec() {
		c = new long[MAX][MAX];
		for (int i = 0; i < MAX; i++) {
			c[i][0] = 1;
			if (i != 0)
				for (int j = 1; j < MAX; j++)
					c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}

	long getAns(int n, int k) {
		if (k > n)
			return 0;
		long[][][] dp = new long[n + 1][n + 1][n + 1];
		// dp[num of vert][max without root][max with root]
		dp[0][0][0] = 1;
		dp[1][0][0] = 1;
		for (int numV = 2; numV <= n; numV++)
			for (int num1 = 0; num1 <= numV; num1++)
				for (int without1 = 0; without1 <= n; without1++)
					for (int with1 = without1; with1 <= Math.min(n, without1 + 1); with1++)
						if (dp[num1][without1][with1] != 0) {
							int num2 = numV - num1 - 1;
							if (num2 < 0)
								continue;
							for (int without2 = 0; without2 <= n; without2++)
								for (int with2 = without2; with2 <= Math.min(n, without2 + 1); with2++)
									if (dp[num2][without2][with2] != 0) {
										int newWithout = with1 + with2;
										int newWith = newWithout;
										if (num1 > 0)
											newWith = Math.max(newWith, without1 + 1 + with2);
										if (num2 > 0)
											newWith = Math.max(newWith, with1 + 1 + without2);
										if (newWith <= n) {
											long count = dp[num1][without1][with1] * dp[num2][without2][with2];
											count %= mod;
											count *= numV;
											count %= mod;
											count *= c[numV - 1][num1];
											count %= mod;
											count *= div2;
											count %= mod;
											dp[numV][newWithout][newWith] += count;
											dp[numV][newWithout][newWith] %= mod;
										}
									}
						}

		long res = 0;
		for (int i = 0; i <= Math.min(n, k); i++)
			res = (res + dp[n][i][k]) % mod;
		return (res * BigInteger.valueOf(n).modInverse(BigInteger.valueOf(mod)).longValue()) % mod;
	}

	void solve() {
		prec();
		out.println(getAns(in.nextInt(), in.nextInt()));
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