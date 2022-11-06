import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		char[] c = f.next().toCharArray();
		int n = c.length;
		int[][] nx = new int[n][26];
		Arrays.fill(nx[n-1], n);
		nx[n-1][c[n-1]-'a'] = n-1;
		for(int i = n-2; i >= 0; i--) {
			for(int j = 0; j < 26; j++)
				nx[i][j] = nx[i+1][j];
			nx[i][c[i]-'a'] = i;
		}
		int q = f.nextInt();
		while(q-->0) {
			int l = f.nextInt()-1, r = f.nextInt()-1;
			if(l == r) {
				out.println("Yes");
				continue;
			}
			int cnt = 0;
			for(int i = 0; i < 26; i++)
				if(nx[l][i] <= r) cnt++;
			out.println(cnt >= 2 && c[l] != c[r] || cnt >= 3 ? "Yes" : "No");
		}
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