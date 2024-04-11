import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		while(n-->0) {
			long a = f.nextLong(), b = f.nextLong();
			if(Math.abs(a-b) == 1) {
				out.println(isPrime(a+b) ? "YES" : "NO");
			} else if(Math.abs(a+b) == 1) {
				out.println(isPrime(a-b) ? "YES" : "NO");
			} else out.println("NO");
		}
		out.flush();
	}
	public boolean isPrime(long n) {
		for(long l = 2; l <= Math.sqrt(n); l++)
			if(n % l == 0) return false;
		return true;
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