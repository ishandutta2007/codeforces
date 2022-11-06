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
		int a = f.nextInt(), b = f.nextInt(), c = f.nextInt(), d = f.nextInt();
		long ans = 0;
		for(int z = c; z <= d; z++) {
			int miny = Math.max(b, z-b);
			int maxy = c;
			if(miny > maxy) continue;
			int sv = b-Math.max(a,z+1-miny)+1;
			int ev = b-Math.max(a,z+1-maxy)+1;
			if(ev == b-a+1) {
				ans += (b-a+1L)*(b-a+2L)/2-sv*(sv-1L)/2;
				miny += b-a+1-sv;
				ans += (maxy-miny)*(b-a+1L);
			} else
				ans += ev*(ev+1L)/2-sv*(sv-1L)/2;
		}
		out.println(ans);
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