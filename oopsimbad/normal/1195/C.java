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
		int n = f.nextInt();
		int[] a = new int[n], b = new int[n];
		long aa = 0, bb = 0;
		for(int i = 0; i < n;i++) a[i] = f.nextInt();
		for(int i = 0; i < n;i++) b[i] = f.nextInt();
		for(int i = 0; i < n;i++) {
			long aaa = a[i]+bb;
			long bbb = b[i]+aa;
			aa = Math.max(aa,aaa);
			bb = Math.max(bb,bbb);
		}
		out.println(Math.max(aa,bb));
///
		out.flush(); 
	}
///
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