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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt(), k = f.nextInt()-2;
			int[] arr = new int[n];
			boolean[] b = new boolean[n];
			int sum = 0;
			int best = -1;
			int ans = 0;
			for(int i = 0; i < n; i++)
				arr[i] = f.nextInt();
			for(int i = 1; i < n; i++) {
				if(i >= k && b[i-k]) sum--;
				if(i != n-1 && arr[i-1] < arr[i] && arr[i] > arr[i+1]) {
					b[i] = true;
					sum++;
				}
				if(sum > best && i >= k) {
					best = sum;
					ans = i-k+1;
				}
			}
			out.println(best+1+ " " +ans);
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