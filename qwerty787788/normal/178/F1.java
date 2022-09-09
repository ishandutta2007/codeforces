import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	int N, M;
	int l[][];
	String[] s;
	long ans = 0;
	
	void pr(int st) {
		ArrayList<Integer> tmp = new ArrayList<Integer>();
		for (int i = 0; i < N; i++)
			if ((st & (1 << i)) == (1 << i)) tmp.add(i);
		if (tmp.size() > M) return;
		long newV = 0;
		for (int i = 0; i < tmp.size(); i++)
			for (int j = i + 1; j < tmp.size(); j++)
				newV += l[tmp.get(i)][tmp.get(j)];
		if (newV > ans) ans = newV;
	}
	
	public void solve() throws IOException {
		N = in.nextInt();
		M = in.nextInt();
		s = new String[N];
		l = new int[N][N];
		for (int i = 0; i < N; i++)
			s[i] = in.next();
		for (int i = 0; i < N; i++)
			for (int j = i + 1; j < N; j++) {
				int v = 0;
				for (int k = 0; ; k++) {
					if (k >= s[i].length()) break;
					if (k >= s[j].length()) break;
					if (s[i].charAt(k) == s[j].charAt(k)) v++; else break;
				}
				l[i][j] = v;
				l[j][i] = v;
			}
		for (int st = 0; st < (1 << (N)); st++) {
			pr(st);
		}
		out.println(ans);		
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
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}