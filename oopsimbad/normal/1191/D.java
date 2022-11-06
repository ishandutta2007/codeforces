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
		Integer[] a = new Integer[n];
		for(int i = 0; i < n; i++) a[i] = f.nextInt();
		Arrays.sort(a);
		long cnt = 0;
		boolean b = true;
		int prev = -1;
		boolean useExc = false;
		boolean first = false;
		for(int i = 0; i < n; i++) {
			if(a[i] - 1 > prev) {
				prev = a[i];
				first = true;
			} else {
				if(a[i] <= prev && first && !useExc) {
					useExc = true;
					prev--;
				}
				b &= a[i] > prev;
				first = false;
				prev = a[i];
			}
		}
		for(int i = 0; i < n; i++) {
			if(a[i] < i) b = false;
			cnt += a[i]-i;
		}
		if(b) out.println(cnt % 2 == 0 ? "cslnb" : "sjfnb");
		else out.println("cslnb");
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