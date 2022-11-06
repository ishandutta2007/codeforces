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
		int m = f.nextInt();
		long[] cnt = new long[m];
		long ans = 0;
		if(n >= m) {
			for(long i = 1; i <= m; i++)
				cnt[(int) ((i*i) % m)]++;
			for(int i = 0; i < m; i++)
				cnt[i] *= n/m;
		}
		for(long i = n/m*m+1; i <= n; i++)
			cnt[(int) ((i*i) % m)]++;
		ans = cnt[0] * cnt[0];
		for(int i = 1; i < m/2; i++)
			ans += cnt[i] * cnt[m-i] * 2;
		if(m % 2 == 0)
			ans += cnt[m/2] * cnt[m/2];
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