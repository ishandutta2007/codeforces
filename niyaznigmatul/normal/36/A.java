import java.io.*;
import java.util.*;
import java.math.*;

public class A {

	public static void main(String[] args) {
		new A().run();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "-1";
			}
		}
		return st.nextToken();
	}

	void run() {
		Locale.setDefault(Locale.US);
		try {
			br = new BufferedReader(new FileReader("input.txt"));
			out = new PrintWriter("output.txt");
			solve();
			out.close();
			br.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
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

	BigInteger nextBigInteger() {
		return new BigInteger(nextToken());
	}

	void solve() {
		nextToken();
		char[] c = nextToken().toCharArray();
		ArrayList<Integer> ans = new ArrayList<Integer>();
		for (int i = 0; i < c.length; i++) {
			if (c[i] == '1') {
				ans.add(i);
			}
		}
		int last = -1;
		for (int i = 1; i < ans.size(); i++) {
			int cur = ans.get(i) - ans.get(i - 1);
			if (last != -1 && last != cur) {
				out.println("NO");
				return;
			}
			last = cur;
		}
		out.println("YES");
	}
}