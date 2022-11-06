import java.io.*;
import java.text.*;
import java.util.*;

public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		int n = f.nextInt(), m = f.nextInt();
		long[][] sums = new long[n][n];
		for(int i = 0; i < n; i++) {
			int flower = f.nextInt();
			sums[i][i] = flower;
			for(int j = 0; j < i; j++) sums[j][i] = flower + sums[j][i-1];
		}
		long total = 0;
		while(m-->0) {
			long sum = sums[f.nextInt()-1][f.nextInt()-1];
			if(sum > 0) total += sum;
		}
		System.out.println(total);
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

    }
}