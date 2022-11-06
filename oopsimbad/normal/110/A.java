import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		long l = f.nextLong();
		int cnt = 0;
		while(l > 0) {
			if(l % 10 == 4 || l % 10 == 7) cnt++;
			l /= 10;
		}
		if(cnt == 0) {
			System.out.println("NO");
			return;
		}
		while(cnt > 0) {
			if(cnt % 10 != 4 && cnt % 10 != 7) {
				System.out.println("NO");
				return;
			}
			cnt /= 10;
		}
		System.out.println("YES");
		
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