import java.io.*;
import java.util.*;

public class CF {

	String gen(ArrayList<Character> c) {
		char[] re =new char[c.size()];
		for (int i = 0; i <c.size(); i++)
			re[i] = c.get(i);
		return new String(re);
	}
	
	String[] split(String s) {
		ArrayList<Character> r1 = new ArrayList<>();
		ArrayList<Character> r2 = new ArrayList<>();
		for (int i = 0; i < s.length(); i++)
			if (s.charAt(i) == '|') {
				for (int j = i + 1; j < s.length(); j++) {
					r2.add(s.charAt(j));
				}
				break;
			} else
				r1.add(s.charAt(i));
		return new String[]{gen(r1), gen(r2)};
	}

	void solve() {
		String[] s = split(in.next());
		String s2 = in.next();
		int total = s[0].length() + s[1].length() + s2.length();
		if (total % 2 == 1) {
			out.println("Impossible");
			return;
		}
		int need = total / 2;
		if (s[0].length() > need || s[1].length() > need) {
			out.println("Impossible");
			return;
		}
		int it = 0;
		out.print(s[0]);
		for (int i = 0; i < need - s[0].length(); i++) {
			out.print(s2.charAt(it++));
		}
		out.print("|" + s[1]);
		for (int i = 0; i < need - s[1].length(); i++)
			out.print(s2.charAt(it++));
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