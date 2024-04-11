import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	int a, r, m;
	int[] arr;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(); a = f.nextInt(); r = f.nextInt(); m = f.nextInt();
		if(m > a+r) m = a+r;
		arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = f.nextInt();
		int l = 0, h = 1000000001;
		long min = Long.MAX_VALUE;
		while(h-l > 10) {
			int m = (l+h)/2;
			long v1 = get(m);
			long v2 = get(m+1);
			if(v1 < v2) h = m;
			else l = m+1;
			min = Math.min(min, Math.min(v1,v2));
		}
		for(; l <= h; l++) min = Math.min(min, get(l));
		out.println(min);
		out.flush();
	}
	public long get(int t) {
		long x = 0, y = 0;
		for(int i : arr)
			if(i > t) x += i-t;
			else if(i < t) y += t-i;
		if(x > y) return y*m+r*(x-y);
		else return x*m+a*(y-x);
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