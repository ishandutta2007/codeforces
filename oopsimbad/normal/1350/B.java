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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt();
			int[] arr = new int[n+1];
			int[] cnt = new int[n+1];
			int ans = 0;
			for(int i = 1; i <= n; i++) {
				arr[i] = f.nextInt();
				cnt[i] = 1;
				for(int j = 1; j <= Math.sqrt(i); j++) {
					if(i%j != 0) continue;
					if(arr[j] < arr[i]) cnt[i] = Math.max(cnt[i], cnt[j]+1);
					if(arr[i/j] < arr[i]) cnt[i] = Math.max(cnt[i], cnt[i/j]+1);
				}
				ans = Math.max(ans, cnt[i]);
			}
			out.println(ans);
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