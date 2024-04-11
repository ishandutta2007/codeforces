import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class CF {

	MyScanner in;
	PrintWriter out;

	long gcd(long x, long y) {
		return x == 0 ? y : gcd(y % x, x);
	}

	class Rational {
		BigInteger x, y;

		Rational(long x, long y) {
			this.x = BigInteger.valueOf(x);
			this.y = BigInteger.valueOf(y);
			BigInteger g = this.x.gcd(this.y);
			this.x = this.x.divide(g);
			this.y = this.y.divide(g);
		}
		
		public Rational(BigInteger x, BigInteger y) {
			this.x = x;
			this.y = y;
			BigInteger g = this.x.gcd(this.y);
			this.x = this.x.divide(g);
			this.y = this.y.divide(g);
		}
	}
	
	Rational sum(Rational x, Rational y) {
		return new Rational(x.x .multiply(y.y).add(y.x .multiply(x.y)), x.y.multiply(y.y)); 
	}

	void solve() {
		int n = in.nextInt();
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		Random rnd = new Random(123);
		for (int i = 1; i < n; i++) {
			int x = rnd.nextInt(i);
			int tmp = a[x];
			a[x] = a[i];
			a[i] = tmp;
		}
		Arrays.sort(a);
		long up = 0;
		long sum = 0;
		for (int i = 0; i < n; i++) {
			up += a[i] * 1L * i - sum;
			sum += a[i];
		}
		up *= 2;
		long down = n;
		long g = gcd(up, down);
		up /= g;
		down /= g;
		Rational a1 = new Rational(up, down);
		long ss = 0;
		for (int i = 0; i <n ; i++) {
			ss += a[i];
		}
		Rational a2 = new Rational(ss, n);
		Rational res = sum(a2, a1);
		out.println(res.x + " " + res.y);
	}

	void run() {
		try {
			in = new MyScanner();
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	class MyScanner {
		BufferedReader in;
		StringTokenizer st;

		public MyScanner() {
			in = new BufferedReader(new InputStreamReader(System.in));

		}

		String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(in.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}
	}

	public static void main(String[] args) {
		new CF().run();
	}
}