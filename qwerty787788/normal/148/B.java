import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	double vp, vd, t, f, c;
	
	double nextMove(double pos) {
		pos += vp * (pos / vd + f);
		pos = dogn(pos);
		return pos;
	}
	
	double dogn(double pos) {
		return pos + vp * pos / (vd - vp);
	}
	
	public void solve() throws IOException {
		vp = in.nextInt();
		vd = in.nextInt();
		t = in.nextInt();
		f = in.nextInt();
		c = in.nextInt();
		double nowPos = dogn(t * vp);
		int need = 0;
		if (vp >= vd || nowPos >= c) {
			out.println(0);
			return;
		}
		while(true) {
			need++;
			nowPos = nextMove(nowPos);
			if (nowPos >= c) {
				out.println(need);
				return;
			}
		}
	}

	public void run() {
		try {
//			in = new FastScanner(new File("input.txt"));
//			out = new PrintWriter(new File("output.txt"));
			
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