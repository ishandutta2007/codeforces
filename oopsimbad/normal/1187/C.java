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
		boolean[] b = new boolean[n];
		int[][] q = new int[m][3];
		for(int i = 0; i < m; i++) {
			q[i][0] = f.nextInt();
			q[i][1] = f.nextInt();
			q[i][2] = f.nextInt();
			if(q[i][0] == 1) 
				for(int a = q[i][1]; a < q[i][2]; a++) 
					b[a] = true;
		}
		for(int i = 0; i < m; i++) {
			if(q[i][0] == 0) {
				boolean all = true;
				for(int a = q[i][1]; a < q[i][2]; a++)
					all &= b[a];
				if(all) {
					out.println("NO");
					out.flush();
					return;
				}
			}
		}
		int[] ans = new int[n];
		int cur = 1;
		for(int i = n-1; i >= 0; i--) {
			ans[i] = cur;
			if(!b[i]) cur++;
		}
		out.println("YES");
		for(int i : ans) out.print(i + " ");
			
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