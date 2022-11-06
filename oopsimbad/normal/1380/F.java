import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt();
		arr = new int[n];
		char[] c = f.next().toCharArray();
		for(int i = 0; i < n; i++) arr[i] = c[i]-'0';
		seg00 = new long[4*n];
		seg01 = new long[4*n];
		seg10 = new long[4*n];
		seg11 = new long[4*n];
		dumb = new int[20];
		for(int i = 0; i <= 9; i++)
			for(int j = 0; j <= 9; j++) dumb[i+j]++;
		init(0, 0, n);
		while(m-->0) {
			int a = f.nextInt()-1;
			arr[a] = f.nextInt();
			update(0, 0, n, a);
			update(0, 0, n, a+1);
			out.println(seg00[0]);
		}
		///
		out.flush();
	}
	int[] dumb;
	int[] arr;
	long[] seg00;
	long[] seg01;
	long[] seg10;
	long[] seg11;
	public void init(int i, int l, int r) {
		if(l == r-1) {
			if(l == 0) {
				seg00[i] = arr[0]+1;
				seg01[i] = 1; 
			}
			else {
				seg00[i] = arr[l]+1;
				seg01[i] = 1;
				seg10[i] = get(arr[l]+arr[l-1]*10);
			}
		} else {
			int m = (l+r)/2;
			init(2*i+1, l, m);
			init(2*i+2, m, r);
			mul(i, 2*i+1, 2*i+2);
		}
	}
	public void update(int i, int l, int r, int a) {
		if(a < l || a >= r) return;
		if(l == r-1) {
			if(l == 0)
				seg00[i] = arr[0]+1;
			else {
				seg00[i] = arr[l]+1;
				seg10[i] = get(arr[l]+arr[l-1]*10);
			}
		} else {
			int m = (l+r)/2;
			if(a < m) update(2*i+1, l, m, a);
			else update(2*i+2, m, r, a);
			mul(i, 2*i+1, 2*i+2);
		}
	}
	public int get(int i) {
		if(10 <= i && i < 20) return dumb[i];
		else return 0;
	}
	public void mul(int i, int a, int b) {
		seg00[i] = (seg00[a]*seg00[b]+seg01[a]*seg10[b])%MOD;
		seg01[i] = (seg00[a]*seg01[b]+seg01[a]*seg11[b])%MOD;
		seg10[i] = (seg10[a]*seg00[b]+seg11[a]*seg10[b])%MOD;
		seg11[i] = (seg10[a]*seg01[b]+seg11[a]*seg11[b])%MOD;
	}
	long MOD = 998244353; 
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in), 32768);
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