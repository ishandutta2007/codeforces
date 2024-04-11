import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	long[][] dp;
	int[] arr;
	int n;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		n = f.nextInt();
		int k = f.nextInt();
		arr = new int[n];
		for(int i = 0; i < n; i++) arr[i] = f.nextInt();
		//[i][j] = ith door at index j
		dp = new long[k][n];
		
		l(0);
		cnts = new long[n+1];
		for(int i = 0; i < n; i++) {
			r(i+1);
			dp[0][i] = cost;
		}
		//System.out.println(Arrays.toString(dp[0]));
		for(int i = 1; i < k; i++) {
			recur(0,n,0,n,i);
			//System.out.println(Arrays.toString(dp[i]));
		}
		out.println(dp[k-1][n-1]);
		out.flush();
	}
	int curl, curr;
	long cost, cnts[];
	public void r(int r) {
		while(curr < r) {
			cost += cnts[arr[curr]];
			cnts[arr[curr]]++;
			curr++;
		}
		while(curr > r) {
			curr--;
			cnts[arr[curr]]--;
			cost -= cnts[arr[curr]];
		}
	}
	public void l(int l) {
		while(curl > l) {
			curl--;
			cost += cnts[arr[curl]];
			cnts[arr[curl]]++;
		}
		while(curl < l) {
			cnts[arr[curl]]--;
			cost -= cnts[arr[curl]];
			curl++;
		}
	}
	public void recur(int li, int ri, int lj, int rj, int k) {
		if(li >= ri) return;
		if(lj < 1) lj = 1;
		if(rj > ri) rj = ri;
		int i = (li+ri)/2;
		dp[k][i] = 1_000_000_000_000L;
		int bestj = -1;
		r(i+1);
		for(int j = lj; j <= i && j < rj; j++) {
			l(j);
			if(j < rj) {
				long val = dp[k-1][j-1] + cost;
				if(dp[k][i] > val) {
					dp[k][i] = val;
					bestj = j;
				}
			}
		}
		recur(li, i, lj, bestj+1,k);
		recur(i+1, ri, bestj, rj,k);
		
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