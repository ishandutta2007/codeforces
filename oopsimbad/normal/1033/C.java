import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		//int n = 100_000;
		int[] arr = new int[n];
		boolean[] dp = new boolean[n];
		int[] map = new int[n];
		for(int i= 0 ;i < n; i++) map[(arr[i] = f.nextInt())-1] = i;
			//map[(arr[i] = n-i) - 1] = i;
		for(int i = n; i > 0; i--) {
			int j = map[i-1] % i;
			for(; j < n; j += i) {
				if(arr[j] <= i) continue;
				if(!dp[j]) {
					dp[map[i-1]] = true;
					break;
				}
			}
		}
		for(boolean b : dp)
			out.print(b ? "A" : "B");
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