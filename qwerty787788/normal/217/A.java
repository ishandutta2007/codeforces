import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;	

	int n;
	int[] x;
	int[] y;
	int[] color;
	void dfs (int v, int c) {
		color[v] = c;
		for (int i = 0; i < n; i++)
			if (x[i] == x[v] || y[i] == y[v])
				if (color[i] == 0)
					dfs(i, c);
	}
	
	public void solve() throws IOException {
		n = in.nextInt();
		x = new int[n];
		y = new int[n];
		color = new int[n];
		for (int i= 0; i < n; i++) {
			x[i] = in.nextInt();
			y[i] = in.nextInt();
		}
		int numColors = 0;
		for (int i = 0; i < n; i++)
			if (color[i] == 0)
				dfs(i, ++numColors);
		out.println(numColors - 1);
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

		String nextLine() {
			String s = null;
			try {
				s = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return s;
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
		
		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					String s = br.readLine();
					if (s == null)
						return false;
					st = new StringTokenizer(s);
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.hasMoreTokens();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}