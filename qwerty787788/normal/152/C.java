import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	long mod = (int)1e9 + 7;
	
	public void solve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		String[] s = new String[n];
		for (int i = 0; i < n; i++) {
			s[i] = in.next();
		}
		long ans = 1;
		for (int i = 0; i < m; i++) {
			HashSet<Character> hs = new HashSet<Character>();
			long su = 0;
			for (int j = 0; j < n; j++) {
				if (!hs.contains(s[j].charAt(i))) {
					char add = s[j].charAt(i);
					hs.add(add);
					su++;
				}
			}
			ans = (ans * su) % mod;
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

		//FastScanner(File f) {
		//	try {
	//			br = new BufferedReader(new FileReader(f));
	//		} catch (FileNotFoundException e) {
	//			e.printStackTrace();
	//		}
	//	}

		
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