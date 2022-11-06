import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		int n = f.nextInt();
		int times = f.nextInt();
		char[] c = f.next().toCharArray();
		while(times-->0) {
			char[] d = new char[n];
			d[0] = c[0];
			for(int i = 1; i < c.length; i++) {
				if(c[i] == 'G' && c[i-1] == 'B') {
					d[i-1] = 'G';
					d[i] = 'B';
				} else d[i] = c[i];
			}
			c = d;
		}
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