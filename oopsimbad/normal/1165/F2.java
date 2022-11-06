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
		int n = f.nextInt(), m = f.nextInt();
		int[] nec = new int[n];
		int tot = 0;
		for(int i = 0; i < n; i++) tot += nec[i] = f.nextInt();
		LinkedList<Integer>[] ll = new LinkedList[200000];
		for(int i = 0; i < ll.length; i++) ll[i] = new LinkedList<>();
		for(int i = 0; i < m; i++) {
			int a = f.nextInt(), b = f.nextInt();
			ll[a-1].add(b-1);
		}
		int lo = 1, hi = tot*2;
		while(lo < hi) {
			int mid = (lo+hi)/2;
			int total = tot;
			int y = mid;
			int z = mid;
			int[] cnt = new int[n];
			for(int i = mid-1; i >= 0; i--) {
				y = Math.min(y, i+1);
				if(i < ll.length) for(int a : ll[i])
					while(y > 0 && cnt[a] < nec[a]) {
						cnt[a]++;
						y--;
						z--;
						total--;
					}
			}
			if(total * 2 <= z) hi = mid;
			else lo = mid+1;
		}
		out.println(lo);
 		out.flush();
	}
	public static final long MOD = 998244353;
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