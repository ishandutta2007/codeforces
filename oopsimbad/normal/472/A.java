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
		boolean[] prime = new boolean[1000001];
		for(int i = 1; i < prime.length; i++) {
			prime[i] = true;
			for(int j = 2; prime[i] && j <= Math.sqrt(i); j++) 
				prime[i] = i % j != 0;
		}
		int n = f.nextInt();
		for(int i = 4; i < n; i++) {
			if(!prime[i] && !prime[n-i]) {
				out.println(i + " " + (n-i));
				break;
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

    }
}