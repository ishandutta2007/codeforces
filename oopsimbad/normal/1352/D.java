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
			int n= f.nextInt();
			int[] arr = new int[n];
			for(int i = 0; i < arr.length; i++)
				arr[i] = f.nextInt();
			int l = 0, r = arr.length-1;
			int a = 0, b = 0;
			int c = 0, d = 0;
			int t = 0;
			for(; l <= r; t++) {
				if(t%2 == 0) {
					c = 0;
					while(c <= d && l <= r)
						c += arr[l++];
					a += c;	
				} else {
					d = 0;
					while(d <= c && l <= r)
						d += arr[r--];
					b += d;
				}
			}
			out.println(t + " " + a + " " + b);
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