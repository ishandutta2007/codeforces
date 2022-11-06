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
		///
		int n = f.nextInt(), q = f.nextInt();
		int sz = 256;
		int[] arr = new int[n];
		int[][] orig = new int[(n-1)/sz+1][sz];
		int[] szs = new int[(n-1)/sz+1];
		int[][] val = new int[(n-1)/sz+1][sz];
		int[][][] id = new int[(n-1)/sz+1][][];
		Arrays.fill(val[val.length-1], -1);
		for(int i = 0; i < n; i++) {
			arr[i] = f.nextInt()-1;
			val[arr[i]/sz][szs[arr[i]/sz]] = arr[i];
			orig[arr[i]/sz][szs[arr[i]/sz]] = ++cnt;
			szs[arr[i]/sz]++;
		}
		for(int i = 0; i < sz; i++)
			if(val[val.length-1][i] == -1) val[val.length-1][i] = (val.length-1)*sz+i;
		add1 = new ArrayList<>(22000000); add2 = new ArrayList<>(2200000);
		aux = new int[9][2][][];
		aux2 = new int[9][4][];
		for(int i = 0; i <= 8; i++) {
			aux[i][0] = new int[(1 << i)+1][(1 << i)+1];
			aux[i][1] = new int[(1 << i)+1][(1 << i)+1];
			aux2[i][0] = new int[(1 << i)];
			aux2[i][1] = new int[(1 << i)];
			aux2[i][2] = new int[(1 << i)];
			aux2[i][3] = new int[(1 << i)];
		}
		for(int i = 0; i < id.length; i++) {
			id[i] = new int[sz+1][sz+1];
			aux2[8][0] = val[i];
			aux2[8][1] = orig[i];
			gen(i*sz, 8, 0);
			for(int a = 0; a <= sz; a++)
				for(int b = a+1; b <= sz; b++) id[i][a][b] = aux[8][0][a][b];
		}
		if(n % 256 != 0) for(int i = n-n/sz*sz; i < sz; i++) orig[orig.length-1][i] = 2147483647;
		int[] ans = new int[q];
		for(int i = 0; i < q; i++) {
			int l = f.nextInt(), r = f.nextInt()+1;
			for(int b = 0; b < orig.length; b++) {
				int s = 0, e = 0;
				{
					int lo = 0, hi = sz;
					while(lo < hi) {
						int m = (lo+hi)/2;
						if(orig[b][m] < l) lo = m+1;
						else hi = m;
					}
					s = lo;
				}
				{
					int lo = 0, hi = sz;
					while(lo < hi) {
						int m = (lo+hi)/2;
						if(orig[b][m] < r) lo = m+1;
						else hi = m;
					}
					e = lo;
				}
				ans[i] = add(ans[i], id[b][s][e]);
			}
		}
		out.println(cnt);
		for(int i = 0; i < add1.size(); i++) { out.println(add1.get(i) + " " + add2.get(i)); }
		for(int i : ans) out.print(i + " ");
		out.println();
///
		out.flush();
	}
	ArrayList<Integer> add1, add2;
	int cnt;
	int[][][][] aux;
	int[][][] aux2;
	public void gen(int st, int lvl1, int lvl2) {
		int n = 1 << lvl1;
		if(n == 1) {
			aux[lvl1][lvl2][0][1] = aux2[lvl1][2*lvl2+1][0];
			return;
		}
		int bb = 0, cc = 0;
		for(int i = 0; i < n; i++) {
			if(aux2[lvl1][2*lvl2][i] < st + n/2) {
				aux2[lvl1-1][0][bb] = aux2[lvl1][2*lvl2][i];
				aux2[lvl1-1][1][bb] = aux2[lvl1][2*lvl2+1][i];
				bb++;
			} else {
				aux2[lvl1-1][2][cc] = aux2[lvl1][2*lvl2][i];
				aux2[lvl1-1][3][cc] = aux2[lvl1][2*lvl2+1][i];
				cc++;
			}
		}
		gen(st, lvl1-1, 0);
		gen(st+n/2, lvl1-1, 1);
		int[][] u = aux[lvl1-1][0];
		int[][] v = aux[lvl1-1][1];
		int[][] res = aux[lvl1][lvl2];
		int bs = 0, cs = 0;
		for(int i = 0; i < n; i++) {
			int be = bs, ce = cs;
			for(int j = i; j < n; j++) {
				if(aux2[lvl1][2*lvl2][j] < st+n/2) be++;
				else ce++;
				res[i][j+1] = add(u[bs][be],v[cs][ce]);
			}
			if(aux2[lvl1][2*lvl2][i] < st+n/2) bs++;
			else cs++;
		}
	}
	public int add(int u, int v) {
		if(u*v == 0) return u+v;
		add1.add(u); add2.add(v);
		return ++cnt;
	}
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