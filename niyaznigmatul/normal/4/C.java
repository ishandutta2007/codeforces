import java.io.*;
import java.util.*;

public class C implements Runnable {
	public static void main(String[] args) {
		new Thread(new C()).start();
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
		int n = nextInt();
		HashMap<String, Integer> h = new HashMap<String, Integer>();
		for (int i = 0; i < n; ++i) {
			String s = nextToken();
			if (h.containsKey(s)) {
				int p = h.get(s);
				out.println(s + p);
				h.put(s, p + 1);
			} else {
				h.put(s, 1);
				out.println("OK");
			}
		}
	}
}