import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class codeforces {
	public static void main(String[] args) throws Exception {
		new codeforces().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		long[] sums = new long[n+1];
		int i = 1;
		long last = 0;
		while(n-->0) {
			if(f.nextInt() == 1) {
				last = f.nextLong();
				sums[i] = last + sums[i-1];
				i++;
			} else {
				int l = 0, h = i-2;
				while(l < h) {
					int m = (l+h)/2;
					double val = (double)(sums[m] + last)/(m+1);
					double val2 = (double)(sums[m+1] + last)/(m+2);
					if(val > val2) l = m+1;
					else h = m;
				}
				System.out.println(last - (double) (sums[l] + last)/(l+1));
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
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }


    }
}