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
		char[] c = f.next().toCharArray();
		out.print("? ");
		for(int i = 0; i < c.length; i++)
			out.print((char) ('a' + i/26/26));
		out.println();
		out.flush();
		out.print("? ");
		for(int i = 0; i < c.length; i++)
			out.print((char) ('a' + i/26%26));
		out.println();
		out.flush();
		out.print("? ");
		for(int i = 0; i < c.length; i++)
			out.print((char) ('a' + i%26));
		out.println();
		out.flush();
		int[] map = new int[c.length];
		char[] a1 = f.next().toCharArray();
		char[] a2 = f.next().toCharArray();
		char[] a3 = f.next().toCharArray();
		for(int i = 0; i < c.length; i++)
			map[(a1[i]-'a')*26*26 + (a2[i]-'a')*26 + a3[i]-'a'] = i;
		out.print("! ");
		for(int i = 0; i < c.length; i++)
			out.print(c[map[i]]);
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
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }
    }
}