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
		int k1 = f.nextInt();
		int k2 = f.nextInt();
		int k3 = f.nextInt();
		int n = k1+k2+k3;
		int[] cnt1 = new int[n+1];
		int[] cnt2 = new int[n+1];
		int[] cnt3 = new int[n+1];
		for(int i = 0; i < k1; i++) cnt1[f.nextInt()]++;
		for(int i = 0; i < k2; i++) cnt2[f.nextInt()]++;
		for(int i = 0; i < k3; i++) cnt3[f.nextInt()]++;
		for(int i = 1; i <= n; i++) {
			cnt1[i] += cnt1[i-1];
			cnt2[i] += cnt2[i-1];
			cnt3[i] += cnt3[i-1];
		}
		int[] max = new int[n+1];
		for(int i = 0; i <= n; i++) max[i] = cnt2[i] - cnt3[i];
		for(int i = n-1; i >= 0; i--) max[i] = Math.max(max[i+1], max[i]);
		int ans = n;
		for(int l = 0; l <= n; l++)
			ans = Math.min(ans, n-(cnt1[l] + max[l] + k3 - cnt2[l]));
		out.println(ans);
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