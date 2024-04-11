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
		int[] div = new int[n+1];
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(int i = 2; i <= n; i++) {
			if(div[i] != 0) continue;
			for(int j = i; j <= n; j += i)
				if(div[j] == 0) div[j] = i;
		}
		for(int i = 2; i <= n; i++)
			pq.add(i/div[i]);
		int ans = 1;
		for(int i = 1; i < n; i++) {
			ans = Math.max(ans,pq.poll());
			out.print(ans + " ");
		}
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