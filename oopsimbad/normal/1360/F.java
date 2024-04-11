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
			int n = f.nextInt(), m = f.nextInt();
			char[][] mat = new char[n][];
			for(int i = 0; i < n; i++)
				mat[i] = f.next().toCharArray();
			boolean found = false;
			for(int k = 0; k < m; k++) {
				char[] ans = new char[m];
				for(int j =0 ; j < m; j++)
					ans[j] = mat[0][j];
				for(int i = 0; i < n; i++) {
					int cnt = 0;
					for(int j = 0; j < m; j++)
						if(mat[i][j] != ans[j]) cnt++;
					if(cnt > 1) ans[k] = mat[i][k];
				}
				boolean ok = true;
				for(int i = 0; i < n; i++) {
					int cnt = 0;
					for(int j = 0; j < m; j++)
						if(mat[i][j] != ans[j]) cnt++;
					ok &= cnt <= 1;
				}
				if(ok) {
					out.println(ans);
					found = true;
					break;
				}
			}
			if(!found) out.println(-1);
		}
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b, i;
		public Pair(int a, int b, int i) {
			this.a = a;
			this.b = b;
			this.i = i;
		}
		public int compareTo(Pair p) {
			return Integer.compare(b, p.b);
		}
		public String toString() {
			return a + "," + b;
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