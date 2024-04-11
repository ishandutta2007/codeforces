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
		int n = f.nextInt(), m = f.nextInt();
		int[] a = new int[n];
		int[] b = new int[m];
		for(int i = 0; i < n; i++) a[n-i-1] = f.nextInt();
		for(int i = 0; i < m; i++) b[m-i-1] = f.nextInt();
		long MOD = 998_244_353;
		long ans = 1;
		int st = 0;
		int end = 0;
		while(st < n && a[st] > b[0]) st++;
		if(st == n || a[st] != b[0]) ans = 0;
		end = st;
		while(end < n && a[end] >= b[0]) end++;
		for(int j = 1; ans != 0 && j < m; j++) {
			int i = st+1;
			while(i < n && a[i] > b[j]) i++;
			if(i == n || a[i] != b[j]) ans = 0;
			ans = ans * (Math.min(end, i)-st) % MOD;
			st = i;
			end = i;
			while(end < n && a[end] >= b[j]) end++;
		}
		if(end < n) out.println(0);
		else out.println(ans);
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