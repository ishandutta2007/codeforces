import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		long a = in.nextInt();
		long b = in.nextInt();
		long m = in.nextInt();		
		long r = in.nextInt();
		int move = 1;
		int arr[] = new int[(int) m];
		arr[(int) r] = 1;
		while (true) {
			move++;
			r = (a * r + b) % m;
			if (arr[(int) r] == 0) {
				arr[(int) r] = move;
			} else {
				out.println(move - arr[(int) r]);
				return;
			}
		}
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