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
		long[] arr = new long[n];
		long total = 0;
		for(int i = 0; i < n; i++)
			total += arr[i] = f.nextLong();
		long[] sum1 = new long[n], sum2 = new long[n];
		sum1[0] = arr[0];
		for(int i = 1; i < n; i++) {
			sum1[i] = sum1[i-1];
			sum2[i] = sum2[i-1];
			if(i % 2 == 0) sum1[i] += arr[i];
			else sum2[i] += arr[i];
		}
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			if(2*((i == 0 ? 0 : sum1[i-1]) + sum2[n-1] - sum2[i]) == total - arr[i]) cnt++;
		}
		out.println(cnt);
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