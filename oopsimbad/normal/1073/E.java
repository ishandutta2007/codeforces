import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final int MOD = 998_244_353;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		long l = f.nextLong()-1, r = f.nextLong();
		int K = f.nextInt();
		//(i,j,k) = sum of all vals that have i digits and j uniques, with digits according to bitmap k 
		long[][][] sum = new long[19][K+1][1 << 10];
		long[][][] cnt = new long[19][K+1][1 << 10];
		
		long[] pow10 = new long[19];
		pow10[0] = 1;
		for(int i = 1; i < 19; i++) 
			pow10[i] = pow10[i-1] * 10 % MOD;
		for(int i = 0; i < 10; i++) {
			cnt[1][1][1 << i] = 1;
			sum[1][1][1 << i] = i;
		}
		cnt[0][0][0] = 1;
		
		for(int i = 2; i < 19; i++) {
			for(int j = 1; j <= K; j++) {
				for(int k = 0; k < 1 << 10; k++) {
					for(int a = 0; a < 10; a++) {
						if((k & (1 << a)) == 0) continue;
						sum[i][j][k] += (sum[i-1][j-1][k ^ (1<<a)] + (cnt[i-1][j-1][k ^ (1<<a)] * a % MOD) * pow10[i-1] % MOD) % MOD;
						sum[i][j][k] %= MOD;
						cnt[i][j][k] += cnt[i-1][j-1][k ^ (1<<a)];
						cnt[i][j][k] %= MOD;
						
						sum[i][j][k] += (sum[i-1][j][k] + (cnt[i-1][j][k] * a % MOD) * pow10[i-1] % MOD) % MOD;
						sum[i][j][k] %= MOD;
						cnt[i][j][k] += cnt[i-1][j][k];
						cnt[i][j][k] %= MOD;
					}
				}
			}
		}
		long ans = 0;
		if(r >= 10) {
			char[] num = (""+r).toCharArray();
			long prefix = 0;
			int bitmap = 0;
			for(int i = num.length; i > 0; i--) {
				for(int d = i == num.length ? 1 : 0; d < num[num.length-i]-'0'; d++) {
					/*
					System.out.println("thing for d");
					System.out.println((prefix + d * pow10[i-1] % MOD));
					//*/
					for(int j = 0; j < 1 << 10; j++) {
						if(Integer.bitCount(j | bitmap | 1 << d) <= K) {
							ans += (sum[i-1][Integer.bitCount(j)][j] + 
									(prefix + d * pow10[i-1] % MOD) % MOD
									* cnt[i-1][Integer.bitCount(j)][j] % MOD) % MOD;
							ans %= MOD;
							/*
							if(cnt[i-1][Integer.bitCount(j)][j] != 0) {
								System.out.printf("%08d%n",Integer.parseInt(Integer.toBinaryString(j)));
							System.out.println((sum[i-1][Integer.bitCount(j)][j]));
							System.out.println(((
									(prefix + d * pow10[i-1] % MOD) % MOD
									* cnt[i-1][Integer.bitCount(j)][j] % MOD) % MOD));
							}
							//*/
						}
					}
				}
				prefix = (prefix + pow10[i-1]*(num[num.length-i]-'0') % MOD) % MOD;
				bitmap |= 1 << (num[num.length-i]-'0');
				//System.out.println(ans);
			}
			for(int i = num.length-1; i > 0; i--)
				for(int j = 0; j < 1024; j++) {
					if(Integer.bitCount(j) <= K) {
						if((j & 1) == 1)
							ans = (ans + sum[i][Integer.bitCount(j)][j] - sum[i-1][Integer.bitCount(j)-1][j^1] - sum[i-1][Integer.bitCount(j)][j] + MOD) % MOD;
						else ans = (ans + sum[i][Integer.bitCount(j)][j]) % MOD;
					}
				}
			if(Integer.bitCount(bitmap) <= K)
				ans = (ans+r%MOD)%MOD;
		} else ans = (ans + r*(r+1)/2) % MOD;
		//System.out.println(ans);
		if(l >= 10) {

			char[] num = (""+l).toCharArray();
			long prefix = 0;
			int bitmap = 0;
			for(int i = num.length; i > 0; i--) {
				for(int d = i == num.length ? 1 : 0; d < num[num.length-i]-'0'; d++) {
					/*
					System.out.println("thing for d");
					System.out.println((prefix + d * pow10[i-1] % MOD));
					//*/
					for(int j = 0; j < 1 << 10; j++) {
						if(Integer.bitCount(j | bitmap | 1 << d) <= K) {
							ans -= (sum[i-1][Integer.bitCount(j)][j] + 
									(prefix + d * pow10[i-1] % MOD) % MOD
									* cnt[i-1][Integer.bitCount(j)][j] % MOD) % MOD;
							ans += MOD;
							ans %= MOD;
							/*
							if(cnt[i-1][Integer.bitCount(j)][j] != 0) {
								System.out.printf("%08d%n",Integer.parseInt(Integer.toBinaryString(j)));
							System.out.println((sum[i-1][Integer.bitCount(j)][j]));
							System.out.println(((
									(prefix + d * pow10[i-1] % MOD) % MOD
									* cnt[i-1][Integer.bitCount(j)][j] % MOD) % MOD));
							}
							//*/
						}
					}
				}
				prefix = (prefix + pow10[i-1]*(num[num.length-i]-'0') % MOD) % MOD;
				bitmap |= 1 << (num[num.length-i]-'0');
				//System.out.println(ans);
			}
			for(int i = num.length-1; i > 0; i--)
				for(int j = 0; j < 1024; j++) {
					if(Integer.bitCount(j) <= K) {
						if((j & 1) == 1)
							ans = (ans - (sum[i][Integer.bitCount(j)][j] - sum[i-1][Integer.bitCount(j)-1][j^1] - sum[i-1][Integer.bitCount(j)][j] + MOD) % MOD + MOD) % MOD;
						else ans = (ans - sum[i][Integer.bitCount(j)][j] + MOD) % MOD;
					}
				}
			if(Integer.bitCount(bitmap) <= K)
				ans = (ans-l%MOD+MOD)%MOD;
		} else ans = (ans - l*(l+1)/2 + MOD) % MOD;

		out.println(ans);
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