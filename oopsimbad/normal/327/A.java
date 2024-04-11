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
		int[] arr = new int[n];
		int total = 0, bestsum = 0, cursum = 0;
		for(int i = 0; i < n; i++) {
			total += arr[i] = f.nextInt();
			if(arr[i] == 1) cursum--;
			else cursum++;
			if(cursum > bestsum) bestsum = cursum;
			if(cursum < 0) cursum = 0;
		}
		if(bestsum == 0) System.out.println(total-1);
		else System.out.println(total +  bestsum);
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

    }
}