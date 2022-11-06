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
		String[] arr = "Anka Chapay Cleo Troll Dracul Snowy Hexadecimal".split(" ");
		HashMap<String,Integer> hm = new HashMap<>();
		for(int i = 0; i < 7; i++) hm.put(arr[i], i);
		mat = new boolean[7][7];
		int asdf = f.nextInt();
		while(asdf-->0) {
			int a = hm.get(f.next()); f.next();
			int b = hm.get(f.next());
			mat[a][b] = true;
		}
		a = f.nextInt(); b=  f.nextInt(); c= f.nextInt();
		best1 = 2147483647;
		recur(0, new int[7]);
		out.println(best1 + " " + best2);
		out.flush();
	}
///
	boolean[][] mat;
	int a, b, c;
	int best1, best2;
	public void recur(int i, int[] arr) {
		if(i == 7) {
			int A = 0, B = 0, C = 0, D = 0;
			for(int q = 0; q < 7; q++) {
				for(int p = 0; p < 7; p++) 
					if(mat[q][p] && arr[q] == arr[p]) D++;
				if(arr[q] == 1) A++;
				if(arr[q] == 2) B++;
				if(arr[q] == 3) C++;
			}
			if(A*B*C == 0) return;
			int z = Math.max(a/A, Math.max(c/C, b/B))-Math.min(a/A, Math.min(c/C, b/B));
			if(z < best1 || z == best1 && D > best2) {
				best1 = z;
				best2 = D;
			}
		} else {
			arr[i] = 1;
			recur(i+1, arr);
			arr[i] = 2;
			recur(i+1, arr);
			arr[i] = 3;
			recur(i+1, arr);
			arr[i] = 0;
		}
	}
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