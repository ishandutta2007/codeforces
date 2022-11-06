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
		long x1 = f.nextLong();
		long y1 = f.nextLong();
		long x2 = f.nextLong();
		long y2 = f.nextLong();
		int n = f.nextInt();
		char[] c = f.next().toCharArray();
		int[] xs = new int[n+1], ys = new int[n+1];
		for(int i = 0; i < n; i++) {
			xs[i+1] = xs[i];
			ys[i+1] = ys[i];
			if(c[i] == 'U') ys[i+1]++;
			if(c[i] == 'D') ys[i+1]--;
			if(c[i] == 'L') xs[i+1]--;
			if(c[i] == 'R') xs[i+1]++;
		}
		long l = 0, r = 1;
		while(r < 1L << 60) {
			long x3 = x1 + r/n * xs[n] + xs[(int) (r%n)]; 
			long y3 = y1 + r/n * ys[n] + ys[(int) (r%n)];
			if(dist(x3,y3,x2,y2) <= r) break;
			r = 2*r;
		}
		if(r == 1L << 60) out.println(-1);
		else {
			while(l < r) {
				long m = (l+r)/2;
				long x3 = x1 + m/n * xs[n] + xs[(int) (m%n)]; 
				long y3 = y1 + m/n * ys[n] + ys[(int) (m%n)];
				if(dist(x3,y3,x2,y2) <= m) r = m;
				else l = m+1;
			}
			out.println(l);
		}
		out.flush();
	}
	public long dist(long x1, long y1, long x2, long y2) {
		return Math.abs(x1-x2) + Math.abs(y1-y2);
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