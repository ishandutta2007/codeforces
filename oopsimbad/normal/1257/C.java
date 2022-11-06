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
			LinkedList<Integer>[] ll = new LinkedList[n];
			for(int i = 0; i < n; i++) ll[i] = new LinkedList<>();
			for(int i = 0; i < n; i++)
				ll[f.nextInt()-1].add(i);
			int min = n+1;
			for(int i = 0; i < n; i++) {
				if(ll[i].isEmpty()) continue;
				int prev = ll[i].poll();
				while(!ll[i].isEmpty()) {
					int a = ll[i].poll();
					min = Math.min(min, a-prev+1);
					prev = a;
				}
			}
			if(min == n+1) out.println(-1);
			else out.println(min);
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