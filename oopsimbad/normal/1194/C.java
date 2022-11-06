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
		int asdf = f.nextInt();
		while(asdf-->0) {
			char[] a = f.next().toCharArray();
			char[] b = f.next().toCharArray();
			char[] c = f.next().toCharArray();
			int p = 0;
			int[] cnt = new int[26];
			for(char cc : c) cnt[cc-'a']--;
			for(int i = 0; i < b.length; i++) {
				if(p != a.length && a[p] == b[i]) p++;
				else cnt[b[i]-'a']++;
			}
			boolean bb = p == a.length;
			for(int i : cnt) bb &= i <= 0;
			out.println(bb ? "YES" : "NO");
		}
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