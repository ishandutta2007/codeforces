import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	long MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt();
		int[] t = new int[n], g = new int[n], c = new int[3];
		for(int i = 0; i < n; i++) {
			t[i] = f.nextInt();
			c[g[i] = f.nextInt()-1]++;
		}
		long[][] dp1 = new long[c[0]+1][m+1];
		long[][][] dp2 = new long[c[1]+1][c[2]+1][m+1];
		dp1[0][0] = 1;
		dp2[0][0][0] = 1;
		for(int i = 0; i < n; i++) {
			if(g[i] == 0) {
				for(int j = dp1.length-2; j >= 0; j--)
					for(int k = m-t[i]; k >= 0; k--)
						dp1[j+1][k+t[i]] = (dp1[j+1][k+t[i]] + dp1[j][k]) % MOD;
			} else if(g[i] == 1) {
				for(int j = dp2.length-2; j >= 0; j--)
					for(int k = dp2[j].length-1; k >= 0; k--)
						for(int l = m-t[i]; l >= 0; l--)
							dp2[j+1][k][l+t[i]] = (dp2[j+1][k][l+t[i]] + dp2[j][k][l]) % MOD;
			} else {
				for(int j = dp2.length-1; j >= 0; j--)
					for(int k = dp2[j].length-2; k >= 0; k--)
						for(int l = m-t[i]; l >= 0; l--)
							dp2[j][k+1][l+t[i]] = (dp2[j][k+1][l+t[i]] + dp2[j][k][l]) % MOD;
			}
		}
		long[][][][] combo = new long[c[0]+1][c[1]+1][c[2]+1][3];
		if(c[0] != 0) combo[1][0][0][0] = 1;
		if(c[1] != 0) combo[0][1][0][1] = 1;
		if(c[2] != 0) combo[0][0][1][2] = 1;
		for(int i = 0; i <= c[0]; i++) {
			for(int j = 0; j <= c[1]; j++) {
				for(int k = 0; k <= c[2]; k++) {
					for(int a = 0; a < 3; a++) {
						if(a != 0 && i < c[0]) combo[i+1][j][k][0] = (combo[i+1][j][k][0] + combo[i][j][k][a] * (i+1) % MOD) % MOD;
						if(a != 1 && j < c[1]) combo[i][j+1][k][1] = (combo[i][j+1][k][1] + combo[i][j][k][a] * (j+1) % MOD) % MOD;
						if(a != 2 && k < c[2]) combo[i][j][k+1][2] = (combo[i][j][k+1][2] + combo[i][j][k][a] * (k+1) % MOD) % MOD;
					}	
				}
			}
		}
		long ans = 0;
		for(int s = 0; s <= m; s++) {
			for(int x = 0; x <= c[0]; x++)
				for(int y = 0; y <= c[1]; y++)
					for(int z = 0;z <= c[2]; z++) {
						ans = (ans + dp1[x][s] * dp2[y][z][m-s] % MOD * ((combo[x][y][z][0] + combo[x][y][z][1] + combo[x][y][z][2]) % MOD) % MOD) % MOD;
					}
		}
		/*
		for(int i = 0; i < dp1.length; i++)
			out.println(Arrays.toString(dp1[i]));
		out.println("-----");
		for(int i = 0; i < dp2.length; i++) {
			for(int j = 0; j < dp2[i].length; j++) 
					out.println(Arrays.toString(dp2[i][j]));
				out.println();
			}
		for(int i = 0; i <= c[0]; i++) for(int j = 0; j <= c[1]; j++) for(int k = 0; k <= c[2]; k++) out.printf("%d %d %d: %d%n", i, j, k, combo[i][j][k][0] + combo[i][j][k][1] + combo[i][j][k][2]); */
		out.println(ans);
		///
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
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }
    }
}