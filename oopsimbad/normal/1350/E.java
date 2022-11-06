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
		int n = f.nextInt(), m = f.nextInt();
		int t = f.nextInt();
		int[][] orig = new int[n][m];
		long[][] min = new long[n][m];
		for(int i = 0; i < n; i++) {
			char[] c = f.next().toCharArray();
			for(int j = 0; j < m; j++) {
				orig[i][j] = c[j]-'0';
				min[i][j] = Long.MAX_VALUE;
			}
		}
		LinkedList<Integer> ll = new LinkedList<>();
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				boolean b = false;
				if(i != 0) b |= orig[i-1][j] == orig[i][j];
				if(i != n-1) b |= orig[i+1][j] == orig[i][j];
				if(j != 0) b |= orig[i][j-1] == orig[i][j];
				if(j != m-1) b |= orig[i][j+1] == orig[i][j];
				if(b) {
					ll.add(i); ll.add(j); min[i][j] = 0;
				}
			}
		}
		while(!ll.isEmpty()) {
			int i = ll.poll(), j = ll.poll(), d = (int) (min[i][j]+1);
			if(i != 0 && min[i-1][j] == Long.MAX_VALUE) {min[i-1][j] = d; ll.add(i-1); ll.add(j);}
			if(i != n-1 && min[i+1][j] == Long.MAX_VALUE) {min[i+1][j] = d; ll.add(i+1); ll.add(j);}
			if(j != 0 && min[i][j-1] == Long.MAX_VALUE) {min[i][j-1] = d; ll.add(i); ll.add(j-1);}
			if(j != m-1 && min[i][j+1] == Long.MAX_VALUE) {min[i][j+1] = d; ll.add(i); ll.add(j+1);}
		}
		while(t-->0) {
			int i = f.nextInt()-1, j = f.nextInt()-1;
			long v = f.nextLong();
			if(min[i][j] >= v) out.println(orig[i][j]);
			else out.println(orig[i][j] ^ (v - min[i][j])%2);
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