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
		int n = f.nextInt(); long x = f.nextLong();
		long[] arr = new long[2*n];
		for(int i = 0; i < n; i++)
			arr[i] = arr[i+n] = f.nextLong();
		int l = 0;
		long sum = 0;
		long ans = 0;
		long cur = 0;
		for(int i = 0; i < arr.length; i++) {
			sum += arr[i];
			cur += (arr[i]+1)*arr[i]/2;
			while(sum > x) {
				cur -= (arr[l]+1)*arr[l]/2;
				sum -= arr[l++];
			}
			long add = 0;
			if(l != 0) {
				long v = x-sum;
				add = arr[l-1]*(arr[l-1]+1)/2-(arr[l-1]-v)*(arr[l-1]+1-v)/2;
			}
			ans = Math.max(ans, cur+add);
		}
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