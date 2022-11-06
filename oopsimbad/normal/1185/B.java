import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int times = f.nextInt();
        while(times-->0) {
            char[] a = f.next().toCharArray();
            char[] b = f.next().toCharArray();
            int j = 1;
            boolean works = a[0] == b[0];
            for(int i = 1; i < a.length && works; i++) {
                while(j < b.length && b[j] != a[i]) {
                    if(b[j] != a[i-1]) {
                        works = false;
                        break;
                    }
                    j++;
                }
                if(j >= b.length) works = false;
                j++;
            }
            while(j < b.length) works &= b[j++] == a[a.length-1];
            works &= j >= b.length;
            out.println(works ? "YES" : "NO");
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