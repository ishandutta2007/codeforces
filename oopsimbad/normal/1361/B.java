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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt(), p = f.nextInt();
			Integer[] arr = new Integer[n];
			for(int i = 0; i < n; i++ ) arr[i] = f.nextInt();
			if(p == 1) {
				out.println(n%2);
				continue;
			}
			Arrays.sort(arr);
			long cur = 0;
			boolean curb = true;
			boolean[] add = new boolean[n];
			for(int i = n-1; i >= 0; i--) {
				if(i != n-1 && arr[i] < arr[i+1]) {
					int diff = arr[i+1]-arr[i];
					while(diff-->0 && cur < (i+1) && cur > 0) cur *= p;
					if(cur >= (i+1) || cur < 0) {
						for(int j = 0; j <= i; j++)
							add[j] = curb;
						break;
					}
				}
				cur--;
				add[i] = curb;
				if(cur < 0) {
					curb ^= true;
					cur *= -1;
				}
			}
			long ans = 0;
			for(int i = 0; i < n; i++)
				if(add[i]^curb) ans = (ans + exp(p,arr[i]))%MOD;
				else ans = (ans - exp(p,arr[i])+MOD)%MOD;
			out.println(ans);
		}
		out.flush();
	}
	long MOD = 1_000_000_007;
	public long exp(int a, int e) {
		if(e == 0) return 1;
		if(e == 1) return a;
		long r = exp(a,e/2);
		r = r*r%MOD;
		if(e%2 == 1) r = r*a%MOD;
		return r;
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