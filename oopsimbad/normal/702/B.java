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
		HashMap<Long, Integer> hm = new HashMap<Long,Integer>();
		long[] pow = new long[64];
		pow[0] = 1;
		for(int i = 1; i < 64; i++) pow[i] = pow[i-1] * 2;
		hm.put(0L, 0);
		int n = f.nextInt();
		long totalcnt = 0;
		for(int i = 0; i < n; i++) {
			long sum = f.nextLong();
			for(long j : pow) {
				if(j < sum) continue;
				long diff = j-sum;
				if(!hm.containsKey(diff)) continue;
				totalcnt += hm.get(diff);
			}
			if(!hm.containsKey(sum)) hm.put(sum, 1);
			else hm.put(sum,hm.get(sum)+1);
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