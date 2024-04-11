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
			int[][] sum = new int[n+1][200];
			LinkedList<Integer>[] pos = new LinkedList[200];
			int ans = 0;
			for(int a = 0; a < 200; a++)
				pos[a] = new LinkedList<>();
			for(int i = 0; i < n; i++) {
				for(int a = 0; a < 200; a++)
					sum[i+1][a] = sum[i][a];
				int a = f.nextInt()-1;
				ans = Math.max(ans, ++sum[i+1][a]);
				pos[a].add(i);
			}
			for(int a = 0; a < 200; a++) {
				for(int c = 1; pos[a].size() > 1; c++) {
					int l = pos[a].pollFirst();
					int r = pos[a].pollLast();
					for(int b = 0;b < 200; b++)
						ans = Math.max(ans, 2*c+sum[r][b]-sum[l+1][b]);
				}
			}
			out.println(ans);
		}
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			if(a == p.a) return Integer.compare(b, p.b);
			return Integer.compare(p.a, a);
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