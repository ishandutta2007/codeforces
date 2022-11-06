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
        char[] s = f.next().toCharArray(), t = f.next().toCharArray();
        int n = s.length, m = t.length;
        int[] arr = new int[n];
        for(int i = 0; i < n; i++) arr[i] = f.nextInt()-1;
        int l = 0, r = n;
        while(l < r) {
            int md = (l+r)/2;
            boolean[] skip = new boolean[n];
            for(int i = 0; i < md; i++) skip[arr[i]] = true;
            int j = 0;
            for(int i = 0; i < n && j < m; i++) {
                if(skip[i]) continue;
                if(s[i] == t[j]) j++;
            }
            if(j == m) l = md+1;
            else r = md;
        }
        out.println(l-1);
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