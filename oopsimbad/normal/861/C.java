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
		char[] c = f.next().toCharArray();
		if(c.length <= 2) {
			out.println(c);
			out.flush();
			return;
		}
		boolean[] cons = new boolean[c.length];
		for(int i = 0; i < c.length; i++) cons[i] = c[i] != 'a' && c[i] != 'e' && c[i] != 'i'  && c[i] != 'o' && c[i] != 'u';
		out.print(c[0]);
		out.print(c[1]);
		int samel = 0;
		int consl = 0;
		if(cons[0] && cons[1]) consl = 2;
		else if(cons[1]) consl = 1;
		if(consl == 2 && c[0] == c[1]) samel = 2;
		else if(cons[1]) samel = 1;
		
		for(int i = 2; i < c.length; i++) {
			if(cons[i]) {
				if(c[i] != c[i-1]) samel = 1;
				else samel++;
				consl++;
			}
			else consl = 0;
			//System.out.println(c[i] + " "+ consl + " " + samel);
			if(consl != samel && consl >= 3) {
				out.print(" ");
				out.print(c[i]);
				consl = 1;
				samel = 1;
			} else {
				out.print(c[i]);
				if(!cons[i]) {
					consl = 0;
					samel = 0;
				}
			}
			
		}
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