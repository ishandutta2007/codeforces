import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		int n = f.nextInt(), m = f.nextInt(), k = f.nextInt();
		int[][] mat = new int[m][n];
		int[][] sums = new int[m][n];
		int[] ocnts = new int[m];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				sums[j][i] = ocnts[j] += mat[j][i] = f.nextInt();
		long score = 0, change = 0;
		for(int i = 0; i < m; i++) {
			int best = 0;
			int bestocnt = 0;
			for(int j = 0; j < n; j++) {
				int dist = Math.min(k-1, n-j-1);
				if(dist+j >= n || mat[i][j] == 0) continue;
				int a = sums[i][j+dist] - sums[i][j] + 1;
				if(a > best) {
					best = a;
					bestocnt = sums[i][j]-1;
				}
			}
			score += best;
			change += bestocnt;
		}
		out.println(score + " " + change);
		out.flush();
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

    }
}