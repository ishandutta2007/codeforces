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
			int n = f.nextInt();
			int[] arr = new int[n];
			int[] map = new int[n];
			for(int i = 0; i < n; i++)
				map[arr[i] = f.nextInt()-1] = i;
			boolean ok = true;
			boolean[] b = new boolean[n];
			int i = map[0];
			for(int a = 0; a < n; a++) {
				b[i] = true;
				if(i != n-1 && arr[i]+1 == arr[i+1])
					i++;
				else {
					if(i != n-1) ok &= b[i+1];
					if(a != n-1) i = map[arr[i]+1];
				}
			}
			out.println(ok ? "yes" : "no");
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