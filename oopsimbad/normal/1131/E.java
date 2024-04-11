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
		int[] pcnt = new int[n], scnt = new int[n];
		boolean[] all = new boolean[n];
		char[] pcr = new char[n], scr = new char[n];
		int[][] cnts = new int[n][26];
		for(int i = 0; i < n; i++) {
			char[] c = f.next().toCharArray();
			pcr[i] = c[0];
			scr[i] = c[c.length-1];
			all[i] = true;
			char cur = c[0];
			int cnt = 0;
			for(int j = 0; j < c.length; j++) {
				if(cur == c[j]) cnt++;
				else {
					cnts[i][cur - 'a'] = Math.max(cnts[i][cur-'a'], cnt);
					cur = c[j];
					cnt = 1;
				}
				if(c[0] != c[j]) all[i] = false;
				if(pcnt[i] == j && c[0] == c[j]) pcnt[i]++;
				if(scnt[i] == j && c[c.length-1] == c[c.length-j-1]) scnt[i]++;
			}
			cnts[i][cur - 'a'] = Math.max(cnts[i][cur - 'a'], cnt);
		}
		int[] cnt = cnts[0];
		for(int i = 1; i < n; i++) {
			int[] ncnt = new int[26];
			for(int j = 0; j < 26; j++) {
				ncnt[j] = Math.max(cnts[i][j], cnt[j] > 0 ? 1 : 0);
				if(cnt[j] != 0 && (j + 'a' == pcr[i] || j + 'a' == scr[i])) {
					if(all[i]) ncnt[j] = Math.max(ncnt[j], (pcnt[i] + 1) * (cnt[j]+1) - 1);
					if(pcr[i] == scr[i] && pcr[i] == j + 'a') ncnt[j] = Math.max(ncnt[j], pcnt[i] + scnt[i] + 1);
					if(pcr[i] == j + 'a') ncnt[j] = Math.max(ncnt[j], pcnt[i] + 1);
					if(scr[i] == j + 'a') ncnt[j] = Math.max(ncnt[j], scnt[i] + 1);
				}
			}
			//System.out.println(Arrays.toString(cnt));
			cnt = ncnt;
		}
		//System.out.println(Arrays.toString(cnt));
		int max = 0;
		for(int i : cnt)
			max = Math.max(i, max);
		out.println(max);
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