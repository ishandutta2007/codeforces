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
		long[] arr = new long[n];
		TreeSet<Long> ts = new TreeSet<>();
		for(int i = 0; i < n; i++) ts.add(arr[i] = f.nextInt());
		HashMap<Long,Integer> hm = new HashMap<>();
		{
			int i = 0;
			for(long c : ts)
				hm.put(c, i++);
		}
		int[] a = new int[n];
		for(int i = 0; i < n; i++)
			a[i] = hm.get(arr[i]);
		long ans = 0;
		{
			BIT val = new BIT(n);
			for(int i = 0; i < n; i++) {
				ans = (ans + val.get(a[i]) % MOD * (n-i) % MOD * arr[i] % MOD) % MOD;
				ans = (ans + (i+1L) * (n-i) % MOD * arr[i] % MOD) % MOD;
				val.add(a[i], i+1);
			}
		}
		long[] narr = new long[n];
		int[] na = new int[n];
		for(int i = 0; i < n; i++) {
			narr[i] = arr[n-i-1];
			na[i] = a[n-i-1];
		}
		arr = narr;
		a = na;
		{
			BIT val = new BIT(n);
			for(int i = 0; i < n; i++) {
				ans = (ans + val.get(a[i]) % MOD * (n-i) % MOD * arr[i] % MOD) % MOD;
				val.add(a[i], i+1);
			}
		}
		out.println(ans);
 		out.flush();
	}
	public static final long MOD = 1_000_000_007;
	class BIT {
		long[] arr;
		public BIT(int sz) {
			arr = new long[sz+5];
		}
		public long get(int i) {
			i++;
			long res = 0;
			while(i > 0) {
				res += arr[i];
				i -= i & -i;
			}
			return res;
		}
		public void add(int i, int k) {
			i++;
			while(i < arr.length) {
				arr[i] += k;
				 i += i & -i;
			}
		}
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