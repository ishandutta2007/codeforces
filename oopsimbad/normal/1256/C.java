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
		int n = f.nextInt(), m = f.nextInt(), d = f.nextInt()-1;
		int[] arr= new int[m];
		int sum = 0;
		for(int i = 0; i < m; i++) sum += arr[i] = f.nextInt();
		if(sum + (m+1)*d >= n) {
			int[] ans = new int[n];
			int ind = 0;
			for(int i = 0; i < m; i++) {
				int cnt = 0;
				for(int asdf = 0; asdf <= d; asdf++) 
					if(n-ind-asdf >= sum && n-ind-asdf <= sum + (m-i)*d) {
						cnt = asdf;
						break;
					}
				ind += cnt;
				for(int a = 0; a < arr[i]; a++) 
					ans[ind++] = i+1;
				sum -= arr[i];
			}
			out.println("YES");
			for(int i : ans) out.print(i + " ");
		} else out.println("NO");
///
		out.flush(); 
	}
///
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