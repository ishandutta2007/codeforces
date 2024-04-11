import java.io.*;
import java.util.*;

public class A implements Runnable {
	public static void main(String[] args) {
		new Thread(new A()).start();
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
				return "0";
			}
		}
		return st.nextToken();
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		} catch (Exception e) {
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

	void solve() {
		int[] a = new int[4];
		for (int i = 0; i < a.length; i++) {
			a[i] = nextInt();
		}
		Arrays.sort(a);
		if (a[0] + a[1] > a[2] || a[1] + a[2] > a[3]) {
			out.println("TRIANGLE");
		} else if (a[0] + a[1] == a[2] || a[1] + a[2] == a[3]) {
			out.println("SEGMENT");
		} else {
			out.println("IMPOSSIBLE");
		}
	}
}