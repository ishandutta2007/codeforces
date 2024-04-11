import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	double best, bx, by, bz;
	final double eps = 1e-9;
	int a, b, c;
	long S;
	
	double res(double x, double y, double z) {
		if (x + y + z > S) return -1000000000;
		if (x < 0 || y < 0 || z < 0) return -1000000000;
		double ax = 0, ay = 0, az = 0;
		if (a == 0) ax = 0; else
if (x < eps) return -1000000000;
		if (b == 0) ay = 0; else
if (y < eps) return -1000000000;
		if (c == 0) az = 0; else
if (z < eps) return -1000000000;
		if (a != 0) ax = a * Math.log(x);
		if (b != 0) ay = b * Math.log(y);
		if (c != 0) az = c * Math.log(z);
		return ax + ay + az;
	}
	
	double bbx = 0;
	double bby = 0;
	double bbz = 0;
	
	void trySol(double x, double y, double z) {
		double r1 = res(x, y, z);
		if (r1 > best) {
			best = r1;
			bbx = x;
			bby = y;
			bbz = z;
		}
	}
	
	public void solve() throws IOException {
		S = in.nextInt();
		a = in.nextInt();
		b = in.nextInt();
		c = in.nextInt();
		double x = 0, y = 0, z = 0;
		bbx = 0;
		bby = 0;
		bbz = 0;
		double add = 0.999 * S;
		for (int i = 0; i < 10000; i++) {
			best = res(bbx, bby, bbz);
			for (int k1 = -1; k1 < 2; k1++)
				for (int k2 = -1; k2 < 2; k2++)
					for (int k3 = -1; k3 < 2; k3++)
						//if (k1 + k2 + k2 <= 1)
							trySol(x + add * k1, y + add * k2, z + add * k3);
			
			add *= 0.99;
			x = bbx; y = bby; z = bbz;
		}
		out.print(bbx);
		out.print(" ");
		out.print(bby);
		out.print(" ");
		out.println(bbz);
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
		
		long nextLong() {
			return Long.parseLong(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}