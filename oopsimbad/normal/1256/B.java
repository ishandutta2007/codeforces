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
			int n = f.nextInt();
			int[] arr = new int[n];
			boolean[] used = new boolean[n-1];
			for(int i = 0; i < n; i++)
				arr[i] = f.nextInt();
			for(int a = 0; a < n-1; a++) {
				int best = n+1;
				int besti = -1;
				for(int i = 0; i < n-1; i++)
					if(!used[i] && arr[i+1] < arr[i] && arr[i+1] < best) {
						best = arr[i+1];
						besti = i;
					}
				if(besti == -1) break;
				arr[besti] ^= arr[besti+1];
				arr[besti+1] ^= arr[besti];
				arr[besti] ^= arr[besti+1];
				used[besti] = true;
			}
			for(int i : arr) out.print(i + " ");
			out.println();
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