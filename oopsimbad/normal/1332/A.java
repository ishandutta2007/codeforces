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
		int t = f.nextInt();
		while(t-->0) {
			int a = f.nextInt();
			int b = f.nextInt();
			int c = f.nextInt();
			int d = f.nextInt();
			int x = f.nextInt();
			int y = f.nextInt();
			int x1 = f.nextInt();
			int y1 = f.nextInt();
			int x2 = f.nextInt();
			int y2 = f.nextInt();
			int minw = b-a;
			int minh = d-c;
			boolean bb = true;
			if(!(x1 <= x+minw && x+minw <= x2)) bb = false; 
			if(!(y1 <= y+minh && y+minh <= y2)) bb = false;
			if(minw == 0 && (a != 0 || b != 0) && x1 == x && x == x2) bb = false;
			if(minh == 0 && (c != 0 || d != 0) && y1 == y && y == y2) bb = false;

			out.println(bb ? "Yes" : "No");
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
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }
    }
}