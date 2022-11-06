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
		int n = f.nextInt(), m = f.nextInt();
		String s1 = f.next();
		String s2 = f.next();
		if(!s1.contains("*")) {
			out.println(s1.equals(s2) ? "YES" : "NO");
			out.flush();
			return;
		}
		char[] c1 = s1.toCharArray();
		char[] c2 = s2.toCharArray();
		int i = 0;
		for(; i < n && i < m; i++)
			if(c1[i] == '*') break;
			else if(c1[i] != c2[i]) {
				out.println("NO");
				out.flush();
				return;
			}
		for(int j = 0; j < n && j < m; j++)
			if(c1[n-1-j] == '*') break;
			else if(c1[n-1-j] != c2[m-1-j]) {
				out.println("NO");
				out.flush();
				return;
			}
		if(n > m+1) {
			out.println("NO");
			out.flush();
			return;
		}
		out.println("YES");
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