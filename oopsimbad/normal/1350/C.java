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
		int[] min1 = new int[200001];
		int[] min2 = new int[200001];
		int[] cnt = new int[200001];
		for(int i = 0; i <= 200000; i++)
			min1[i] = min2[i] = -1;
		int n = f.nextInt();
		long ans = 1;
		for(int i = 0; i < n; i++) {
			int a = f.nextInt();
			for(int d = 2; d*d <= a; d++) {
				int c = 0;
				while(a%d == 0) {
					a /= d;
					c++;
				}
				if(c != 0) {
					cnt[d]++;
					if(min1[d] == -1 || min1[d] > c) {
						min2[d] = min1[d];
						min1[d] = c;
					} else if(min2[d] == -1 || min2[d] > c) 
						min2[d] = c;
				}
			}
			if(a != 1) {
				cnt[a]++;
				if(min1[a] == -1 || min1[a] > 1) {
					min2[a] = min1[a];
					min1[a] = 1;
				} else if(min2[a] == -1 || min2[a] > 1) 
					min2[a] = 1;
			}
		}
		for(int i = 0; i <= 200000; i++)
			if(cnt[i] == n-1)
				for(int j = 0; j < min1[i]; j++)
					ans *= i;
			else if(cnt[i] == n)
				for(int j = 0; j < min2[i]; j++)
					ans *= i;
		out.println(ans);
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