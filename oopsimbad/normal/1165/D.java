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
			long[] arr = new long[n];
			for(int i = 0; i < n; i++)
				arr[i] = f.nextLong();
			Arrays.sort(arr);
			long val = 0;
			if(n % 2 == 1) val = arr[n/2]*arr[n/2];
			else val = arr[0]*arr[n-1];
			for(int i = 0; i < n/2; i++) {
				if(val != arr[i] * arr[n-i-1]) {
					val = -1;
					break;
				}
			}
			if(val != -1) {
				TreeSet<Long> ts = new TreeSet<>();
				for(int i = 2; i <= Math.sqrt(val); i++)
					if(val % i == 0) {
						ts.add((long) i);
						ts.add(val/i);
					}
				int i = 0;
				for(long a : ts) {
					if(i == arr.length || arr[i] != a) {
						val = -1;
						break;
					}
					i++;
				}
			}
			out.println(val);
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