import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	int n1, n2, n3, n4, d;
	
	
	public void solve() throws IOException {
		n1 = in.nextInt();
		n2 = in.nextInt();
		n3 = in.nextInt();
		n4 = in.nextInt();
		d = in.nextInt();
		int a[] = new int[d];
		int x = n1 - 1;
		while (x < d) {
			a[x] = 1;
			x += n1;
		}
		x = n2 - 1;
		while (x < d) {
			a[x] = 1;
			x += n2;
		}
		x = n3 - 1;
		while (x < d) {
			a[x] = 1;
			x += n3;
		}
		x = n4 - 1;
		while (x < d) {
			a[x] = 1;
			x += n4;
		}
		int ans = 0;
		for (int i=0; i < d; i++) {
			if (a[i] == 1) {
				ans++;
			}
		}
		out.println(ans);
	}

	public void run() {
		try {
			//in = new FastScanner(new File("input.txt"));
			//out = new PrintWriter(new File("output.txt"));
			
			  in = new FastScanner(System.in); out = new
			  PrintWriter(System.out);
			 
			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

//		FastScanner(File f) {
//			try {
//				br = new BufferedReader(new FileReader(f));
//			} catch (FileNotFoundException e) {
//				e.printStackTrace();
//			}
//		}

		
		  FastScanner(InputStream f) { br = new BufferedReader(new
		  InputStreamReader(f)); }
		 

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