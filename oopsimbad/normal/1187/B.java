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
		int n = f.nextInt();
		int[][] cnt = new int[n][26];
		char[] c = f.next().toCharArray();
		for(int i = 0; i < n; i++) {
			cnt[i][c[i]-'a'] = 1;
			if(i != 0) for(int j =0 ; j < 26; j++)
				cnt[i][j] += cnt[i-1][j];
		}
		int m = f.nextInt();
		for(int i = 0; i < m; i++) {
			int[] cnt2 = new int[26];
			char[] c2 = f.next().toCharArray();
			for(char cc : c2) cnt2[cc-'a']++;
			int l = 0, r = n;
			while(l < r) {
				int mid = (l+r)/2;
				boolean k = true;
				for(int a = 0; a < 26; a++)
					if(cnt[mid][a] < cnt2[a]) k = false;
				if(k) r = mid;
				else l = mid+1;
			}
			out.println(r+1);
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