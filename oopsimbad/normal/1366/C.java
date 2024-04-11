import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int asdf = f.nextInt();
		while(asdf-->0) {
			int r = f.nextInt(), c = f.nextInt();
			int[] cnt = new int[r+c-1];
			int[] tot = new int[r+c-1];
			for(int i = 0; i < r; i++) {
				for(int j = 0; j < c; j++) {
					int a = f.nextInt();
					cnt[i+j] += a;
					tot[i+j]++;
				}
			}
			int ans = 0;
			for(int i = 0; i < cnt.length/2; i++)
				ans += Math.min(cnt[i]+cnt[cnt.length-i-1], tot[i]+tot[cnt.length-i-1]-cnt[i]-cnt[cnt.length-i-1]);
			out.println(ans);
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