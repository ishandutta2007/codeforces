import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public static long MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt();
		long[] arr = new long[n];
		TreeSet<Long> ts = new TreeSet<Long>();
		for(int i = 0; i <  n; i++) arr[i] = f.nextLong();
		for(int i = 0; i < m; i++) ts.add(f.nextLong());
		long max = 0;
		for(long i : arr) {
			long min = Integer.MAX_VALUE;
			Long l = ts.ceiling(i);
			if(l != null) min = Math.min(min, Math.abs(l-i));
			l = ts.floor(i);
			if(l != null) min = Math.min(min, Math.abs(l-i));
			max = Math.max(max, min);
		}
		out.println(max);
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