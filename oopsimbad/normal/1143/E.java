import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class E {
	public static void main(String[] args) throws Exception {
		new E().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt(), q = f.nextInt();
		int[] map = new int[n];
		for(int i = 0; i < n; i++) map[f.nextInt()-1] = i;
		int[] arr = new int[m];
		int[] prev = new int[n];
		Arrays.fill(prev, m);
		int[][] aft = new int[m+1][20];
		for(int i = 0; i < m; i++)
			arr[i] = map[f.nextInt()-1];
		for(int i = m-1; i >= 0; i--) {
			aft[i][0] = prev[(arr[i]+1)%n];
			prev[arr[i]] = i;
		}
		Arrays.fill(aft[m], m);
		ans = new int[m];
		for(int i = m-1; i >= 0; i--) {
			for(int j = 1; j < 20; j++)
				aft[i][j] = aft[aft[i][j-1]][j-1];
			int j = i;
			int v = n-1;
			for(int b = 19; b >= 0; b--)
				if(v >= (1 << b)) {
					j = aft[j][b];
					v -= 1 << b;
				}
			ans[i] = j;
		}
		seg = new int[4*m];
		init(0, 0, m);
		while(q-->0) {
			int l = f.nextInt()-1, r = f.nextInt();
			out.print(query(0, 0, m, l, r) < r ? 1 : 0);
		}
		out.println();
		out.flush();
	}
	int[] ans;
	int[] seg;
	public void init(int i, int l, int r) {
		if(l == r-1) seg[i] = ans[l];
		else {
			int m = (l+r)/2;
			init(2*i+1,l,m);
			init(2*i+2,m,r);
			seg[i] = Math.min(seg[2*i+1], seg[2*i+2]);
		}
	}
	public int query(int i, int l, int r, int ql, int qr) {
		if(ql < l) ql = l;
		if(qr > r) qr = r;
		if(ql >= r || qr <= l) return 2147483647;
		if(ql == l && qr == r) return seg[i];
		int m = (l+r)/2;
		return Math.min(query(2*i+1, l, m, ql, qr), query(2*i+2, m, r, ql, qr));
	}
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() { reader = new BufferedReader(new InputStreamReader(System.in), 32768);
			tokenizer = null;
		}
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public double nextDouble() {
			return Double.parseDouble(next());
		}
		public String nextLine() {
			try {
				return reader.readLine();
			} catch(IOException e) {
				throw new RuntimeException(e);
			}
		}
	}
}