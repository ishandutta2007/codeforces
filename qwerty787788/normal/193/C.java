import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	public void solve() throws IOException {
		long x1 = in.nextInt();
		long x2 = in.nextInt();
		long x3 = in.nextInt();
		long x4 = in.nextInt();
		long x5 = in.nextInt();
		long x6 = in.nextInt();
		for (long x = 0; x <= 1000000; x++) {
			boolean ok = true;
			if ((x1 + x4 - x2) % 2 != 0) ok = false;
			long t1 = (x1 + x4 - x2) / 2;
			if (t1 < 0 || t1 > x1) ok = false;
			if ((x2 + x4 - x1) % 2 != 0) ok = false;
			long t2 = (x2 + x4 - x1) / 2;
			if (t2 < 0) ok = false;
			
			
			long tmp = -x3 + x1 + t2 - x5 + t2 + x + x;
			if ((tmp % 2) != 0) ok = false;
			long l3 = tmp / 2;
			if (l3 < 0 || l3 > t2) ok = false;
			tmp = -x3 +x1+t2+x-x6+x+t1;
			if ((tmp % 2) != 0) ok = false;
			long l1 = tmp / 2;
			if (l1 < 0 || l1 > t1) ok = false;
			long l2 = l3 - l1 + x5 - x - t2;
			if (l2 < 0 || l2 > (x1 - t1)) ok = false;
			if (!ok) continue;
			int len = (int)(x1 + t2 + x);
			char s1[] = new char[len];
			for (int i = 0; i < len; i++)
				s1[i] = 'a';
			char s2[] = new char[len];
			for (int i = 0; i < x1; i++)
				s2[i] = 'b';
			for (int i = (int)x1; i < len; i++)
				s2[i] = 'a';
			char s3[] = new char[len];
			for (int i = 0; i < t1; i++)
				s3[i] = 'a';
			for (int i = (int)t1; i < x1; i++)
				s3[i] = 'b';
			for (int i = (int)x1; i < x1 + t2; i++)
				s3[i] = 'b';
			for (int i = (int)(x1 + t2); i < len; i++)
				s3[i] = 'a';
			char s4[] = new char[len];
			for (int i = 0; i < l1; i++)
				s4[i] = 'a';
			for (int i = (int)l1; i < t1; i++)
				s4[i] = 'b';
			for (int i = (int)t1; i < t1 + l2; i++)
				s4[i] = 'a';
			for (int i = (int)(t1 + l2); i < x1; i++)
				s4[i] = 'b';
			for (int i = (int)x1; i < x1 + l3; i++)
				s4[i] = 'a';
			for (int i = (int)(x1 + l3); i < len; i++)
				s4[i] = 'b';
			int nowx1 = 0, nowx2 = 0, nowx3 = 0, nowx4 = 0, nowx5 = 0, nowx6 = 0;
			for (int j = 0; j < len; j++)
				if (s1[j] != s2[j]) nowx1++;
			for (int j = 0; j < len; j++)
				if (s1[j] != s3[j]) nowx2++;
			for (int j = 0; j < len; j++)
				if (s1[j] != s4[j]) nowx3++;
			for (int j = 0; j < len; j++)
				if (s2[j] != s3[j]) nowx4++;
			for (int j = 0; j < len; j++)
				if (s2[j] != s4[j]) nowx5++;
			for (int j = 0; j < len; j++)
				if (s3[j] != s4[j]) nowx6++;
			if (nowx1 != x1) ok = false;
			if (nowx2 != x2) ok = false;
			if (nowx3 != x3) ok = false;
			if (nowx4 != x4) ok = false;
			if (nowx5 != x5) ok = false;
			if (nowx6 != x6) ok = false;
			if (ok) {
			out.println(len);
			out.println(s1);
			out.println(s2);
			out.println(s3);
			out.println(s4);
			return;
			}
		}
		out.println(-1);
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