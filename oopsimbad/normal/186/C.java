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
		long val = f.nextLong();
		if(val == 0) {
			System.out.println(1);
			return;
		}
		long up = 1, down = 0;
		long b = 1;
		while(b <= val) b <<= 1;
		b >>= 1;
		for(; b > 0; b >>= 1) {
			long temp = up;
			up = up*up+down*down;
			down = 2*temp*down;
			if((val & b) != 0) {
				temp = up;
				up = 3*temp+down;
				down = 3*down+temp;
			}
			up %= 1000_000007;
			down %= 1000_000007;
		}
		out.println(up);
//		out.println(oops(val));
		out.flush();
	}
	public long oops(long val) {
		long up = 1, down = 0;
		for(int i = 0; i < val; i++) {
			long temp = up;
			up = 3*temp+down;
			down = 3*down+temp;
		}
		return up;
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