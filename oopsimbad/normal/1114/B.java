import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final int MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt(), k = f.nextInt();
		int[] arr = new int[n];
		int[] sorted = new int[n];
		for(int i = 0; i < n; i++)
			sorted[i] = arr[i] = f.nextInt();
		if(m*k == n) {
			long total = 0;
			for(int i = 0; i < n; i++)
				total += arr[i];
			out.println(total);
			for(int i = 0; i < k-1; i++)
				out.print((i+1) * m + " ");
			out.flush();
			return;
		}
		Arrays.sort(sorted);
		int maybe = sorted[n-m*k];
		int cnt = m*k;
		long total = 0;
		for(int i = n-1; i >= 0; i--) {
			if(sorted[i] > maybe) {
				total += sorted[i];
				cnt--;
			} else break;
 		}
		out.println(total + cnt * maybe);
		int curcnt = 0;
		for(int i = 0; i < n; i++) {
			if(arr[i] > maybe) curcnt++;
			else if(arr[i] == maybe && cnt > 0) {
				cnt--;
				curcnt++;
			}
			if(curcnt == m && k != 1) {
				out.print(i+1 + " ");
				curcnt = 0;
				k--;
			}
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