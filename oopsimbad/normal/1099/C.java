import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		char[] c = f.nextLine().toCharArray();
		int k = f.nextInt();
		int minl = 0;
		boolean b = false;
		int maxl = 0;
		for(int i = 0; i < c.length; i++) {
			if(c[i] == '*') {
				b = true;
				minl--;
			} else if(c[i] == '?') minl--;
			else {
				minl++;
				maxl++;
			}
		}
		if(k < minl || !b && k > maxl) out.println("Impossible");
		else if(b) {
			int add = k-minl;
			boolean done = false;
			for(int i = 0; i < c.length; i++) {
				if(i != c.length-1 && c[i+1] == '*') {
					if(!done) {
						done = true;
						for(int asdf = 0; asdf < add; asdf++)
							out.print(c[i]);
					}
					i++;
				} else if(i != c.length-1 && c[i+1] == '?') {
					i++;
				} else {
					out.print(c[i]);
				}
			}
		} else {
			int add = k-minl;
			for(int i = 0; i < c.length; i++) {
				if(i != c.length-1 && c[i+1] == '?') {
					if(add > 0) {
						add--;
						out.print(c[i]);
					}
					i++;
				} else out.print(c[i]);
			}
			out.println();
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