import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final int MAXVAL = 500000;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int m = f.nextInt(), k = f.nextInt(), n = f.nextInt(), s = f.nextInt();
		int l = 0, r = 0;
		int[] arr = new int[m];
		for(int i = 0; i < m; i++) arr[i] = f.nextInt()-1;
		boolean found = false;
		int[] cnts = new int[MAXVAL];
		int[] curcnts = new int[MAXVAL];
		for(int i = 0; i < s; i++)
			cnts[f.nextInt()-1]++;
		boolean works = true;
		for(int i = 0; i < MAXVAL; i++) {
			while(r < m && curcnts[i] < cnts[i])
				curcnts[arr[r++]]++;
			works = works && curcnts[i] >= cnts[i];
		}
		if(!works) {
			out.println(-1);
			out.flush();
			return;
		}
		if(m - Math.max(0, l - (l/k*k + k - s)) - Math.max(0,r- (l/k*k + k)) >= n*k) {
			found = true;
			out.println(Math.max(0, l - (l/k*k + k - s)) + Math.max(0,r- (l/k*k + k)));
			int cnt = Math.max(0, l - (l/k*k + k - s)) + Math.max(0,r-l - k);
			for(int i = l/k*k + k - s; i < l && cnt > 0; i++) {
				out.print(i + 1 + " ");
				cnt--;
			}
			curcnts = new int[MAXVAL];
			for(int i = l; i < r && cnt > 0; i++)
				if(++curcnts[arr[i]] > cnts[arr[i]]) {
					out.print(i + 1 + " ");
					cnt--;
				}
		}
		while(l < m && !found) {
			int val = arr[l++];
			curcnts[val]--;
			while(r < m && curcnts[val] < cnts[val])
				curcnts[arr[r++]]++;
			if(m - Math.max(0, l - (l/k*k + k - s)) - Math.max(0,r- (l/k*k + k)) >= n*k) {
				found = true;
				out.println(Math.max(0, l - (l/k*k + k - s)) + Math.max(0,r- (l/k*k + k)));
				int cnt = Math.max(0, l - (l/k*k + k - s)) + Math.max(0,r-l - k);
				for(int i = l/k*k + k - s; i < l && cnt > 0; i++) {
					out.print(i + 1 + " ");
					cnt--;
				}
				curcnts = new int[MAXVAL];
				for(int i = l; i < r && cnt > 0; i++)
					if(++curcnts[arr[i]] > cnts[arr[i]]) {
						out.print(i + 1 + " ");
						cnt--;
					}
			}
			if(curcnts[val] < cnts[val]) break;
		}
		if(!found) out.println(-1);
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