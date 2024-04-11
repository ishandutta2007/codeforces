import java.util.*;
import java.io.*;

public class cf {
	public static void main(String[] args) throws Exception {
		new cf().run();
	}
	public void run() throws Exception {
		FastScanner file = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = file.nextInt();
		int l = 0, h = n/2;
		out.println("? 1");
		out.println("? " + (n/2+1));
		out.flush();
		int s = file.nextInt(), e = file.nextInt();
		if((Math.abs(s-e) & 1) == 1) {
			out.println("! -1");
			out.flush();
			return;
		}
		while(l < h) {
			int m = (l+h)/2;
			out.println("? " + (m+1));
			out.println("? " + (m+n/2+1));
			out.flush();
			int cs = file.nextInt(), ce = file.nextInt();
			if(cs == ce) {
				out.println("! " + (m+1));
				out.flush();
				return;
			}
			if(cs < ce == s < e) l = m+1;
			else h = m;
		}
		out.println("! " + (l+1));
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
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }


    }
}