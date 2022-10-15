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
			// br = new BufferedReader(new FileReader("a.in"));
			out = new PrintWriter(System.out);
			solve();
			out.flush();
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

	String nextLine() {
		String ret = "";
		try {
			ret = br.readLine();
		} catch (Throwable e) {
			eof = true;
			return "";
		}
		return ret;
	}

	void solve() throws IOException {
		HashSet<String> set = new HashSet<String>();
		long ans = 0;
		while (true) {
			String s = br.readLine();
			if (s == null) {
				break;
			}
			if (s.length() == 0) {
				continue;
			}
			if (s.charAt(0) == '+') {
				set.add(s.substring(1));
			} else if (s.charAt(0) == '-') {
				set.remove(s.substring(1));
			} else if (s.indexOf(":") != -1) {
				ans += (long) set.size() * (s.length() - s.indexOf(":") - 1);
			}
		}
		out.println(ans);
	}
}