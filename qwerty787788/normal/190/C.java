import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	int N;
	ArrayList<String> ans;
	ArrayList<String> a;
	
	int get(int from) {
		if (from >= a.size()) return -1;
		if (a.get(from).equals("int")) {
			ans.add("int");
			return from + 1;
		} else {
			ans.add("pair<");
			int x = get(from + 1);
			ans.add(",");
			if (x == -1) return -1;
			x = get(x);
			ans.add(">");
			if (x == -1) return -1;
			return x;
		}
	}

	public void solve() throws IOException {
		N = in.nextInt();
		ans = new ArrayList<String>();
		a = new ArrayList<String>();
		while (true) {
			String s = in.next();
			if (s == null) break;
			a.add(s);
		}
		if (get(0) != a.size()) out.println("Error occurred"); else
			for (int i = 0; i < ans.size(); i++)
				out.print(ans.get(i));
	}

	public void run() {
		try {
			//in = new FastScanner(new File("input.txt"));
			//out = new PrintWriter(new File("output.txt"));

			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null) return s;
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		String nextLine() {
			try {
				return br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return null;
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}