import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	Set<Integer>[] adj;
	boolean[] visited;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int k = f.nextInt();
		char[] s = f.next().toCharArray();
		TreeSet<Character> ts = new TreeSet<Character>();
		for(char c : s)
			ts.add(c);
		if(k > n) {
			out.print(s);
			for(int i = 0; i < k-n; i++)
				out.print(ts.first());
		} else {
			for(int i = k-1; i >= 0; i--) {
				if(s[i] != ts.last()) {
					s[i] = ts.higher(s[i]);
					break;
				} else {
					s[i] = ts.first();
				}
			}
			for(int i = 0; i < k; i++)
				out.print(s[i]);
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