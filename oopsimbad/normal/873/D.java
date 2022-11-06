import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	PrintWriter out;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		out = new PrintWriter(System.out);
		
		
		int n = f.nextInt(), k = f.nextInt();
		
		if((k & 1) == 0 || k > 2*n-1) {
			out.println(-1);
			out.flush();
			return;
		}
		recur(n,0,k);
 		out.flush();
	}
	public void recur(int len, int start, int k) {
		if(k == 1) {
			for(int i = 0; i < len; i++) out.print(i + start + 1 + " ");
		} else if(k == 2*len-1) {
			for(int i = len-1; i >= 0; i--) out.print(i + start + 1 + " ");
		} else {
			k--;
			int a = Math.min(k-1, 2*((len+1)/2) - 1);
			
			recur(len/2,start+(len+1)/2,k-a);
			
			recur((len+1)/2,start,a);
		}
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