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
		int n = f.nextInt();
		int[] factors = new int[100001];
		for(int i = 0; i < n; i++) {
			int m = f.nextInt();
			if(m == 1) continue;
			for(int j = 2; j < Math.sqrt(m); j++) {
				if(m % j == 0) {
					factors[j] ++;
					factors[m/j]++;
				}
			}
			int root = (int) Math.sqrt(m);
			if(root * root == m) factors[root]++;
			factors[m]++;
		}
		System.out.println(min(factors));
		out.flush();
	}

	int min(int[] args) {
		int min = 1;
		for(int i : args) {
			if(i > min) min = i;
		}
		return min;
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