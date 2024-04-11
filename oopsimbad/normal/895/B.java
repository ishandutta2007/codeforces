import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), x = f.nextInt(), k = f.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = f.nextInt();
		Arrays.sort(arr);
		HashMap<Integer,Long> cnts = new HashMap<Integer,Long>();
		long totalcnt = 0;
		for(int i = 0; i < n; i++) {
			int j = i+1;
			for(;j < n && arr[j] == arr[i]; j++);
			if(!cnts.containsKey((arr[i]-1)/x)) cnts.put((arr[i]-1)/x, 0L);
			cnts.put((arr[i]-1)/x, cnts.get((arr[i]-1)/x) + j - i);
			if(cnts.containsKey(arr[i]/x-k)) totalcnt += (j-i) * cnts.get(arr[i]/x-k);
			i = j-1;
		}
		out.println(totalcnt);
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