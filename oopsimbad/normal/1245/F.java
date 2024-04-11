import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner fs = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int asdf = fs.nextInt();
		while(asdf-->0) {
			long[][][][][] dp = new long[33][2][2][2][2];
			int l = fs.nextInt(), r = fs.nextInt();
			dp[32][1][1][1][1] = 1;
			for(int bit = 31; bit >= 0; bit--) {
				int a = (l & 1 << bit) == 0 ? 0 : 1;
				int b = (r & 1 << bit) == 0 ? 0 : 1;
				for(int c = 0; c < 2; c++)
					for(int d = 0; d < 2; d++)
						for(int e = 0; e < 2; e++)
							for(int f = 0; f < 2; f++)
								for(int g = 0; g < 2; g++)
									for(int h = 0; h < 2; h++) {
										if(c == 1 && g < a) continue;
										if(d == 1 && h < a) continue;
										if(e == 1 && g > b) continue;
										if(f == 1 && h > b) continue;
										if(g == h && h == 1) continue;
										int nc = c == 1 && g == a ? 1 : 0;
										int nd = d == 1 && h == a ? 1 : 0;
										int ne = e == 1 && g == b ? 1 : 0;
										int nf = f == 1 && h == b ? 1 : 0;
										dp[bit][nc][nd][ne][nf] += dp[bit+1][c][d][e][f];
									}
			}
			long sum = 0;
			for(int a = 0; a < 2; a++)
				for(int b = 0; b < 2; b++)
					for(int c = 0; c < 2; c++)
						for(int d = 0; d < 2; d++)
							sum += dp[0][a][b][c][d];
			out.println(sum);
		}
///
		out.flush(); 
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