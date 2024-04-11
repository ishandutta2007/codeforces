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
		
		long b = f.nextLong(), d = f.nextLong(), s = f.nextLong();
		long max = Math.max(b, Math.max(d, s))-1;
		out.println(Math.max(max-b, 0) + Math.max(max-d, 0) + Math.max(max-s, 0));
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

    }
}