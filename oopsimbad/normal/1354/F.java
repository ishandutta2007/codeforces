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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt(), k = f.nextInt();
			Pair[] arr = new Pair[n];
			for(int i = 0; i < n; i++) arr[i] = new Pair(f.nextInt(), f.nextInt(),i);
			Arrays.sort(arr);
			boolean[][] use = new boolean[n+1][k+1];
			int[][] dp = new int[n+1][k+1];
			for(int[] i : dp) Arrays.fill(i, -2147483648);
			dp[0][0] = 0;
			for(int i = 0; i < n; i++)
				for(int j = 0; j <= k; j++) {
					if(dp[i+1][j] < dp[i][j]+(k-1)*(arr[i].b)) {
						dp[i+1][j] = dp[i][j]+(k-1)*(arr[i].b);
						use[i+1][j] = false;
					}
					if(j != k && dp[i+1][j+1] < dp[i][j]+j*arr[i].b+arr[i].a) {
						dp[i+1][j+1] = dp[i][j]+j*arr[i].b+arr[i].a;
						use[i+1][j+1] = true;
					}
				}
			int j = k;
			boolean[] del = new boolean[n];
			for(int i = n; i > 0; i--) {
				if(use[i][j])
					j--;
				else del[i-1] = true;
			}
			out.println(2*n-k);
			int last = -1;
			for(int i = 0; i < n; i++)
				if(!del[i]) {
					if(last != -1) out.print(last + " ");
					last = arr[i].i+1;
				}
			for(int i = 0; i < n; i++)
				if(del[i]) out.print(arr[i].i+1+" " + -(arr[i].i+1) + " ");
			out.println(last);
		}
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b, i;
		public Pair(int a, int b, int i) {
			this.a = a;
			this.b = b;
			this.i = i;
		}
		public int compareTo(Pair p) {
			return Integer.compare(b, p.b);
		}
		public String toString() {
			return a + "," + b;
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