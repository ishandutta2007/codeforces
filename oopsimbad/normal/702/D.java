import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		long d = f.nextLong(), k = f.nextLong(), a = f.nextLong(), b = f.nextLong(), t = f.nextLong();
		if(d <= k) {
			out.println(Math.min(a, b) * d);
		}
		else {
			if(k*b > k*a+t) {
				long time = d/k*(k*a+t);
				d %= k;
				time += Math.min(d*b-t, d*a);
				out.println(time);
			}
			else if(a < b) {
				out.println(a*k + (d-k) * b);
			}
			else {
				out.println(d*b);
			}
		}
		out.flush();
		out.close();
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