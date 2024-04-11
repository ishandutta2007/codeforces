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
		int n = f.nextInt(), q = f.nextInt();
		int max = f.nextInt();
		int[][] initq = new int[n-1][2];
		int[] arr = new int[n-1];
		for(int i = 0; i < n-1; i++) {
			int a = f.nextInt();
			initq[i][0] = max;
			initq[i][1] = a;
			if(max < a) {
				max ^= a;
				a ^= max;
				max ^= a;
			}
			arr[i] = a;
		}
		while(q-->0) {
			long l = f.nextLong()-1;
			if(l < n-1)
				out.printf("%d %d%n", initq[(int) l][0], initq[(int) l][1]);
			else {
				int i = (int) (l % (n-1));
				out.printf("%d %d%n", max, arr[i]);
			}
		}
///
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