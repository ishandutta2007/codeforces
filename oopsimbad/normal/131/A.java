import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		char[] c = f.next().toCharArray();
		for(int i = 1; i < c.length; i++) {
			if(Character.isLowerCase(c[i])) {
				System.out.println(c);
				return;
			}
		}
		for(int i = 1; i < c.length; i++) 
			c[i] += 32;
		if(Character.isUpperCase(c[0])) c[0] += 32;
		else c[0] -= 32;
		System.out.println(c);
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