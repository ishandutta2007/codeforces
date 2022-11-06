import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		char[] c = f.reader.readLine().toCharArray();
		boolean b = true;
		int i = 0;
		while(i < c.length-2) {
			while(i < c.length-2 && c[i] == 'W' && c[i+1] == 'U' && c[i+2] == 'B') i += 3;
			if(i >= c.length) {
				System.out.println();
				return;
			}
			if(!b) System.out.print(" ");
			else b = false;
			while(i < c.length-2 && !(c[i] == 'W' && c[i+1] == 'U' && c[i+2] == 'B')) {
				System.out.print(c[i]);
				i++;
			}
		}
		while(i < c.length) System.out.print(c[i++]);
		System.out.println();
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