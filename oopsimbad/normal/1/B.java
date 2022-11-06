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
		int n = f.nextInt();
		while(n-->0) {
			char[] s = f.next().toCharArray();
			int r = 0;
			int c = 0;
			int ind = 0;
			while(ind < s.length && Character.isLetter(s[ind])) c = c*26+s[ind++] - 'A'+1;
			while(ind < s.length && Character.isDigit(s[ind])) r = r*10 + s[ind++] - '0';
			if(ind != s.length) {
				ind++;
				c = 0;
				while(ind < s.length && Character.isDigit(s[ind])) c = c*10 + s[ind++] - '0';
				StringBuilder sb = new StringBuilder();
				while(c != 0) {
					if(c % 26 == 0) {
						sb.append((char) ('Z'));
						c /= 26;
						c--;
					} else {
						sb.append((char) (c % 26 + 'A' - 1));
						c /= 26;
					}
				}
				out.println(sb.reverse().toString() + r);
			} else out.printf("R%dC%d%n",r,c);
		}
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