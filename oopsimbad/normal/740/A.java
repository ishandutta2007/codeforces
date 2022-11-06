import java.io.*;
import java.text.*;
import java.util.*;

public class A {
	public static void main(String[] args) throws Exception {
		new A().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		long n = f.nextLong(), a = f.nextLong(), b = f.nextLong(), c = f.nextLong();
		n %= 4;
		switch(4 - (int) n) {
		case 4: System.out.println(0); break;
		case 1: System.out.println(Math.min(a,Math.min(b+c ,c * 3))); break;
		case 2: System.out.println(Math.min(a*2, Math.min(b, c*2)));break;
		case 3: System.out.println(Math.min(a*3, Math.min(b+a, c)));break;
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

    }
}