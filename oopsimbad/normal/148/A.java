import java.io.*;
import java.text.*;
import java.util.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		int a = f.nextInt(), b = f.nextInt(), c = f.nextInt(), d = f.nextInt(), n = f.nextInt();
		boolean[] arr = new boolean[n+1];
		int cnt = 0;
		for(int i = a; i <= n; i += a) {
			if(!arr[i]) {
				arr[i] = true;
				cnt++;
			}
		}for(int i = b; i <= n; i += b) {
			if(!arr[i]) {
				arr[i] = true;
				cnt++;
			}
		}for(int i = c; i <= n; i += c) {
			if(!arr[i]) {
				arr[i] = true;
				cnt++;
			}
		}for(int i = d; i <= n; i += d) {
			if(!arr[i]) {
				arr[i] = true;
				cnt++;
			}
		}
		System.out.println(cnt);
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