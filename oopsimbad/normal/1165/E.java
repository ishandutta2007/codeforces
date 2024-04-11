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
		ArrayList<Long> a1 = new ArrayList<>();
		ArrayList<Long> a2 = new ArrayList<>();
		for(int i = 0; i < n; i++) a1.add(f.nextLong() * (i+1) * (n-i));
		for(int i = 0; i < n; i++) a2.add(f.nextLong());
		Collections.sort(a1);
		Collections.sort(a2, Collections.reverseOrder());
		long ans = 0;
		for(int i = 0; i < n; i++)
			ans = (ans + a1.get(i) % MOD * a2.get(i) % MOD) % MOD;
		out.println(ans);
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