import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		long low = 0, n = f.nextLong(), k = f.nextLong();
		long high = n;
		while(low < high) {
			long mid = (low+high)/2;
			long total = mid;
			long div = k;
			while(mid >= div) {
				total += mid/div;
				div *= k;
			}
			if(total >= n) {
				high = mid;
			} else low = mid+1;
		}
		out.println(low);
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