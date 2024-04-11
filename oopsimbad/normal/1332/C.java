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
		int times = f.nextInt();
		while(times-->0) {
			int n = f.nextInt(), k = f.nextInt();
			int[][] cnt = new int[k][26];
			char[] c = f.next().toCharArray();
			for(int i = 0; i < n; i++) {
				cnt[i%k][c[i]-'a']++;
			}
			int ans = 0;
			for(int i = 0; i < k/2; i++) {
				int tot = 0;
				int max = 0;
				for(int j = 0; j < 26; j++) {
					tot += cnt[i][j] + cnt[k-i-1][j];
					max = Math.max(max, cnt[i][j] + cnt[k-i-1][j]);
				}
				ans += tot-max;
			}
			if(k % 2 == 1) {
				int tot = 0;
				int max = 0;
				for(int j = 0; j < 26; j++) {
					tot += cnt[k/2][j];
					max = Math.max(max, cnt[k/2][j]);
				}
				ans += tot-max;
			}
			out.println(ans);
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