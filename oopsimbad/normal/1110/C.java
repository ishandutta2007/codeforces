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
		long[] ans = new long[26];
		for(int i = 1; i < ans.length; i++) {
			long l = (1 << i) - 1;
			ans[i] = 1;
			for(long j = 2; j*j <= l; j++) {
				if(l % j == 0) {
					ans[i] = l/j;
					break;
				}
			}
		}
		int n = f.nextInt();
		while(n-->0) {
			long a = f.nextInt();
			long b = 1;
			int c = 0;
			while(b <= a) {
				b <<= 1;
				c++;
			}
			if(b-1 == a) out.println(ans[c]);
			else out.println(b-1);
		} 
		out.flush();
	}
	public long gcd(long a, long b) {
		if(a == 0 || b == 0) return a+b;
		return gcd(b%a,a);
	}
	class Pair implements Comparable<Pair>{
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			if(a != p.a) return -Integer.compare(a,p.a);
			return Integer.compare(b, p.b);
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