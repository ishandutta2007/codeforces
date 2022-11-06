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
		int n = f.nextInt(), m = (n+1)/2;
		long[] arr = new long[m];
		for(int i = 0; i < m; i++) arr[i] = f.nextLong();
		long x = f.nextLong();
		if(x >= 0) {
			long sum = 0;
			for(long l : arr) sum += l;
			if(sum + (n-m)*x <= 0) out.println(-1);
			else out.println(n);
		} else {
			for(int i = m-2; i >= 0; i--)
				arr[i] += arr[i+1];
			long min = n;
			boolean b = false;
			for(int i = 0; i < m; i++) {
				min = Math.min(min, m-i+(arr[i]-1)/-x);
				if(min + i >= n) {
					out.println(min);
					b = true;
					break;
				}
			}
			if(!b) out.println(-1);
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