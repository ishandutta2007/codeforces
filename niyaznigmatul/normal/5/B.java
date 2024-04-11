import java.io.*;
import java.util.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new Thread(new B()).start();
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
			// br = new BufferedReader(new FileReader("b.in"));
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

	void solve() throws IOException {
		ArrayList<String> a = new ArrayList<String>();
		int len = 0;
		while (true) {
			String s = br.readLine();
			if (s == null) {
				break;
			}
			a.add(s);
			len = Math.max(len, s.length());
		}
		int kol = 0;
		ArrayList<String> ans = new ArrayList<String>();
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < len + 2; i++) {
			sb.append("*");
		}
		ans.add(sb.toString());
		for (int i = 0; i < a.size(); i++) {
			int dif = len - a.get(i).length();
			sb.setLength(0);
			sb.append("*");
			if (dif % 2 != 0) {
				if (kol == 0) {
					for (int j = 0; j < dif / 2; j++) {
						sb.append(" ");
					}
					sb.append(a.get(i));
					for (int j = 0; j < dif / 2 + 1; j++) {
						sb.append(" ");
					}
					sb.append("*");
					ans.add(sb.toString());
				} else {
					for (int j = 0; j < dif / 2 + 1; j++) {
						sb.append(" ");
					}
					sb.append(a.get(i));
					for (int j = 0; j < dif / 2; j++) {
						sb.append(" ");
					}
					sb.append("*");
					ans.add(sb.toString());
				}
				kol ^= 1;
			} else {
				sb.setLength(0);
				sb.append("*");
				for (int j = 0; j < dif / 2; j++) {
					sb.append(" ");
				}
				sb.append(a.get(i));
				for (int j = 0; j < dif / 2; j++) {
					sb.append(" ");
				}
				sb.append("*");
				ans.add(sb.toString());
			}
		}
		sb.setLength(0);
		for (int i = 0; i < len + 2; i++) {
			sb.append("*");
		}
		ans.add(sb.toString());
		for (String s : ans) {
			out.println(s);
		}
	}
}