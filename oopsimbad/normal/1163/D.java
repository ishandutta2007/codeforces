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
        char[] c = f.next().toCharArray();
        char[] s = f.next().toCharArray();
        char[] t = f.next().toCharArray();
        int[] sk = getKMP(s), tk = getKMP(t);
        int n = c.length, sn = s.length, tn = t.length;
        int[][][] dp = new int[n+1][sn][tn];
        for(int i = 0; i <= n; i++) 
            for(int j = 0; j < sn; j++)
                Arrays.fill(dp[i][j], -987654321);
        HashSet<Character> hs = new HashSet<>();
        dp[0][0][0] = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < sn; j++)
                for(int k = 0; k < tn; k++) {
                    hs.clear();
                    hs.add(s[j]);
                    hs.add(t[k]);
                    if(c[i] != '*')
                        hs.clear();
                    hs.add(c[i]);
                    for(char cc : hs) {
                        int val = 0;
                        int nj = j, nk = k;
                        while(nj != 0 && s[nj] != cc) nj = sk[nj-1];
                        if(s[nj] == cc) {
                            if(nj == sn-1) {
                                nj = sk[nj];
                                val++;
                            } else nj++;
                        } 
                        while(nk != 0 && t[nk] != cc) nk = tk[nk-1];
                        if(t[nk] == cc) {
                            if(nk == tn-1) {
                                nk = tk[nk];
                                val--;
                            } else nk++;
                        } 
                        dp[i+1][nj][nk] = Math.max(dp[i+1][nj][nk], dp[i][j][k] + val);
                    }
                }
        int ans = -987654321;
        for(int i = 0; i < sn; i++)
            for(int j = 0; j < tn; j++)
                ans = Math.max(ans,dp[n][i][j]);
        out.println(ans);
        out.flush();
	}
    int[] getKMP(char[] c) {
        int[] kmp = new int[c.length];
        for(int i = 1; i < c.length; i++) {
            int v = kmp[i-1];
            while(v != 0 && c[v] != c[i]) v = kmp[v-1];
            if(c[v] == c[i]) kmp[i] = v+1;
            else kmp[i] = v;
        }
        return kmp;
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