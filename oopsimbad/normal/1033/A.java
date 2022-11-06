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
		f.next();
		int c = f.nextInt(), d = f.nextInt(), a = f.nextInt(), b = f.nextInt(), e =f.nextInt(), g = f.nextInt();
		if(c - d == a - b || c - d == e - g || c + d == a + b || c + d == e + g) System.out.println("NO");
		else if(a <= c && c <= e || e <= c && c <= a) {
			System.out.println("NO");
		} else if(b <= d && d <= g || g <= d && d <= b) {
			System.out.println("NO");
		} else System.out.println("YES");
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