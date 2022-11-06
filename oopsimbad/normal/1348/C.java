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
			int[] cnt = new int[26];
			char[] c = f.next().toCharArray();
			for(int i = 0; i < n; i++)
				cnt[c[i]-'a']++;
			int j = 0;
			while(cnt[j] == 0) j++;
			if(cnt[j] >= k) {
				out.print((char) ('a'+j));
				n -= k;
				cnt[j] -= k;
				if(n != 0) {
					while(cnt[j] == 0) j++;
					if(cnt[j] == n) {
						for(int i = 0; i < (cnt[j]+k-1)/k; i++)
							out.print((char) ('a'+j));
					} else {
						while(j < 26) {
							while(cnt[j]-->0) out.print((char) ('a'+j));
							j++;
						}
					}
				}
				out.println();
			} else {
				k -= cnt[j];
				while(k > 0) k -= cnt[++j];
				out.println((char) ('a'+j));
			}
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