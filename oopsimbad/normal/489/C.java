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
		
		int m = f.nextInt(), s = f.nextInt();
		if(s == 0 && m > 1 || m*9 < s) {
			out.println("-1 -1");
			out.flush();
			return;
		}
		int[] digits = new int[m];
		int i = m-1;
		int ts = s;
		while(ts > 1 && i > 0) {
			if(ts > 9) {
				digits[i] = 9;
				ts -= 9;
			} else {
				digits[i] = ts-1;
				ts = 1;
			}
			i--;
		}
		digits[0] = ts;
		
		for(i = 0; i < m; i++) out.print(digits[i]);
		out.print(' ');
		

		digits = new int[m];
		ts = s;
		for(i = 0; i < m; i++) {
			if(ts < 10) {
				digits[i] = ts;
				break;
			}
			digits[i] = 9;
			ts -= 9;
		}

		for(i = 0; i < m; i++) out.print(digits[i]);
		out.println();
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