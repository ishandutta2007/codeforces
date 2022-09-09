import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;
	
	long f(int a, int b, int c) {
		if (a == 1)
			return b * c;
		return f(a - 1, b, c) + b + c - 1;
	}
	
	public void solve() throws IOException {
		int a = in.nextInt();
		int b = in.nextInt();
		int c = in.nextInt();
		long ans = f(a, b, c);
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

		String nextLine() {
			String s = null;
			try {
				s = br.readLine();
			} catch(IOException e) {
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