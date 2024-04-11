import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	int[][] b;
	int[] a;
	boolean[] used;
	int[] dif;
	int N;
	long sum;
	
	int first(int x) {
		for (int i = 0; i < N * N; i++) {
			if (!used[i] && a[i] == x) return i;
		}
		return -1;
	}
	
	boolean ok() {
		for (int i = 0; i < N; i++) {
			long s = 0;
			for (int j = 0; j < N; j++)
				s += b[i][j];
			if (s != sum) return false;
		}
		for (int i = 0; i < N; i++) {
			long s = 0;
			for (int j = 0; j < N; j++)
				s += b[j][i];
			if (s != sum) return false;
		}
		long s = 0;
		for (int i = 0; i < N; i++) {
			s += b[i][i];
		}
		if (s != sum) return false;
		
		s = 0;
		for (int i = 0; i < N; i++) {
			s += b[N - i - 1][i];
		}
		if (s != sum) return false;
		return true;
	}
	
	boolean rec(int from) {
		if (from == (N - 1) * (N - 1)) {
			for (int i = 0; i < N - 1; i++) {
				long s = 0;
				for (int j = 0; j < N - 1; j++)
					s += b[i][j];
				int f = first((int) (sum - s));
				if (f == -1) return false;
				used[f] = true;
				b[i][N - 1] = (int)(sum - s);
			}
			for (int i = 0; i < N; i++) {
				long s = 0; 
				for (int j = 0; j < N - 1; j++)
					s += b[j][i];
				int f = first((int) (sum - s));
				if (f == -1) return false;
				used[f] = true;
				b[N - 1][i] = (int)(sum - s);
			}
			if (ok()) return true;
			return false;
		}
		int nowX = from % (N - 1);
		int nowY = from / (N - 1);
		for (int i = 0; i < dif.length; i++) {
			int f = first(dif[i]);
			if (f == -1) continue;
			used[f] = true;
			b[nowX][nowY] = a[f];
			if (from + 1 == (N - 1) * (N - 1)) {
				boolean[] used1 = new boolean[N * N];
				for (int k = 0; k < used.length; k++)
					used1[k] = used[k];
				if (rec(from + 1)) return true;
				for (int k = 0; k < used.length; k++)
					used[k] = used1[k];
			} else {
				if (rec(from + 1)) return true;
			}
			used[f] = false;
		}
		return false;
	}
	
	public void solve() throws IOException {
		N = in.nextInt();
		a = new int[N * N];
		used = new boolean[N * N];
		b = new int[N][N];
		sum = 0;
		ArrayList<Integer> tmp = new ArrayList<Integer>();
		for (int i = 0 ; i < N * N; i++) {
			used[i] = false;
			a[i] = in.nextInt();
			sum += a[i];
			boolean newV = true;
			for (int j = 0; j  < i; j++)
				if (a[i] == a[j]) newV = false;
			if (newV) tmp.add((int)a[i]);
		}
		dif = new int[tmp.size()];
		for (int i = 0; i < tmp.size(); i++)
			dif[i] = tmp.get(i);
		sum /= N;
		rec(0);
		out.println(sum);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				out.print(b[i][j]);
				out.print(" ");
			}
			out.println();
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