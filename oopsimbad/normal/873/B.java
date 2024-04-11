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
		char[] arr = f.next().toCharArray();
		int sum = 0;
		int[] best = new int[2*n+1];
		Arrays.fill(best, -1);
		best[n] = 0;
		int bestlen = 0;
		for(int i = 0; i < arr.length; i++) {
			sum += arr[i] == '1' ? 1 : -1;
			if(best[sum+n] == -1) best[sum+n] = i+1;
			if(best[sum+n] != -1)
				bestlen = Math.max(bestlen, i-best[sum+n]+1);
		}
		out.println(bestlen);
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