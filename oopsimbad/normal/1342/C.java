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
			int a = f.nextInt(), b = f.nextInt(), q = f.nextInt();
			int[] psum = new int[a*b+1];
			for(int i = 0; i < a*b; i++) {
				if(i%a%b!=i%b%a) psum[i+1] = 1;
				psum[i+1] += psum[i];
			}
			while(q-->0) {
				long l = f.nextLong(), r = f.nextLong();
				long amt = r/a/b-l/a/b;
				l %= a*b;
				r %= a*b;
				out.print(amt*psum[a*b]+psum[(int) r+1]-psum[(int) l]+" ");
			}
			out.println();
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