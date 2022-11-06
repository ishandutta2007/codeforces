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
		long lim = 1 << 30;
    	while(asdf-->0) {
    		int n = f.nextInt(), k = f.nextInt();
    		char[] c = f.next().toCharArray();
    		long cur = 0;
    		int ofc = 0;
    		for(int i = 0; i < k; i++) {
    			cur = cur*2+('1'-c[i]);
    			if(cur >= lim) {
    				ofc++;
    				cur -= lim;
    			} 
    		}
    		HashSet<Long> hs = new HashSet<>();
    		for(int i = k; i < n; i++) {
    			if(ofc == 0) hs.add(cur);
    			
    			cur = 2*cur+('1'-c[i]);
    			if(cur >= lim) {
    				ofc++;
    				cur -= lim;
    			}
    			if(c[i-k] == '0') {
    				if(k < 30) cur -= 1 << k;
    				else ofc--;
    			}
    		}
			if(ofc == 0) hs.add(cur);
    		long ans = 0;
    		while(hs.contains(ans)) ans++;
    		if(k < 30 && 1 << k <= ans) out.println("NO");
    		else {
    			out.println("YES");
    			String s = Long.toBinaryString(ans);
    			for(int i = 0; i + s.length() < k; i++) out.print(0);
    			out.println(s);
    		}
    	}
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