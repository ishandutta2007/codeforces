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
        int asdf = f.nextInt();
        while(asdf-->0) {
            int n = f.nextInt(), k = f.nextInt();
            char[] c = f.next().toCharArray();
            int[] cnt = new int[26];
            for(char cc : c) cnt[cc-'a']++;
            Arrays.sort(cnt);
            TreeSet<Integer> ts = new TreeSet<>();
            for(int i = 1; i*i <= k; i++)
                if(k % i == 0) {
                    ts.add(i);
                    ts.add(k/i);
                }
            ts.add(0);
            int best = 0;
            for(int i = 1; i <= n; i++) {
                int a = 0;
                for(int j : cnt) a += j/i;
                best = Math.max(best,ts.floor(a)*i);
            }    
            out.println(best);
        }
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