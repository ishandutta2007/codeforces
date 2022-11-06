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
		char[] c1 = f.nextLine().toCharArray(), c2 = f.nextLine().toCharArray();
		if(c1.length != c2.length) out.println("NO");
		else if(new String(c1).equals(new String(c2))) out.println("YES");
		else {
			int fw = -1;
			boolean b = false;
			for(int i = 0; i < c1.length; i++) {
				if(c1[i] == c2[i]) continue;
				if(fw == -1) fw = i;
				else {
					if(c1[i] != c2[fw] || c2[i] != c1[fw]) break;
					boolean b2 = true;
					for(int j = i+1; j < c1.length; j++) {
						if(c1[j] != c2[j]) {
							b2 = false;
							break;
						} 
					}
					if(b2) {
						b = true;
						out.println("YES");
						break;
					} else break;
				}
			}
			if(!b) out.println("NO");
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