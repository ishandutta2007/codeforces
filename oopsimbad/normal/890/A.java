import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws Exception {
		new A().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int[] arr = new int[6];
		int total = 0;
		for(int i = 0; i < 6; i++) {
			total += arr[i] = f.nextInt();
		}
		for(int i = 0; i < 1<<6; i++) {
			int tempsum = 0;
			int cnt = 0;
			for(int j = 0, b = 1; b < 1 << 6; j++, b<<=1) {
				if((b & i) > 0) {
					cnt++;
					tempsum += arr[j];
				}
			}
			if(cnt != 3) continue;
			if(tempsum*2 == total) {
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
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