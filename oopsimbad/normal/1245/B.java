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
			int n = f.nextInt();
			int x = f.nextInt(), y = f.nextInt(), z= f.nextInt();
			char[] c = f.next().toCharArray();
			char[] ans = new char[n];
			int cnt = 0;
			for(int i = 0; i < n; i++) {
				if(c[i] == 'R') { if(y > 0) { cnt++; y--; ans[i] = 'P'; }}
				if(c[i] == 'P') { if(z > 0) { cnt++; z--; ans[i] = 'S'; }}
				if(c[i] == 'S') { if(x > 0) { cnt++; x--; ans[i] = 'R'; }}
			}
			for(int i = 0; i < n; i++)
				if(ans[i] == 0) {
					if(x > 0) {
						ans[i] = 'R';
						x--;
					} else if(y > 0) {
						ans[i] = 'P';
						y--;
					} else {
						ans[i] = 'S';
						z--;
					}
				}
			if(cnt * 2 >= n) {
				out.println("YES");
				out.println(ans);
			} else out.println("NO");
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