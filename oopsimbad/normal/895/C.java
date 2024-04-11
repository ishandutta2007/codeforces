import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	int[] pd;
	HashMap<Integer,Integer> hm;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		pd = new int[71];
		pd[0] = pd[1] = 1;
		hm = new HashMap<Integer,Integer>();
		int primecnt = 0;
		for(int i = 2; i < pd.length; i++) {
			if(pd[i] != 0) continue;
			for(int j = i; j < pd.length; j+=i) if(pd[j] == 0) pd[j] = i;
			hm.put(i, primecnt++);
		}
		long[] pow2 = new long[100010];
		pow2[0] = 1;
		for(int i = 1; i < pow2.length; i++) pow2[i] = pow2[i-1] * 2 % 1000_000_007;
		int n = f.nextInt();
		int[] arr = new int[71];
		for(int i = 0; i < n; i++) arr[f.nextInt()]++;
		long[] dp = new long[1 << 19];
		dp[0] = 1;
		for(int i = 1; i < arr.length; i++) {
			int m = process(i);
			if(arr[i] == 0) continue;
			long c = pow2[arr[i]-1];
			long[] newdp = new long[1 << 19];
			for(int j = 0; j < 1 << 19; j++) {
				newdp[j^m] += (dp[j]*c) % 1000_000_007;
				newdp[j] += (dp[j]*c) % 1000_000_007;
			}
			dp = newdp;
		}
		out.println((dp[0]-1+1000_000_007)%1000_000_007);
		out.flush();
	}
	public int process(int i) {
		int res = 0;
		int cnt = 0;
		int lp = pd[i];
		while(true) {
			int p = pd[i];
			if(p != lp) {
				if(cnt == 1) res |= 1 << hm.get(lp);
				lp = p;
				cnt = 1;
			} else cnt ^= 1;
			i /= p;
			if(p == 1) break;
		}
		return res;
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