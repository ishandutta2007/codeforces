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
			int[][] sets = new int[k][];
			for(int i = 0; i < k; i++) {
				int m = f.nextInt();
				sets[i] = new int[m];
				for(int j = 0; j < m; j++)
					sets[i][j] = f.nextInt();
			}
			out.print("? "+n);
			for(int i = 1; i <= n; i++) out.print(" " + i);
			out.println();
			out.flush();
			int max = f.nextInt();
			int l = 0, h = k;
			while(h-l > 1) {
				int m = (l+h)/2;
				int sum = 0;
				for(int i = l; i < m; i++)
					sum += sets[i].length;
				out.print("? " + sum);
				for(int i = l; i < m; i++)
					for(int j = 0; j < sets[i].length; j++)
						out.print(" "+sets[i][j]);
				out.println();
				out.flush();
				if(f.nextInt() == max) h = m;
				else l = m;
			}
			int[] ans = new int[k];
			Arrays.fill(ans, max);
			boolean[] ask = new boolean[n];
			for(int i = 0; i < sets[l].length; i++)
				ask[sets[l][i]-1] = true;
			out.print("? " + (n-sets[l].length));
			for(int i = 0; i < n; i++)
				if(!ask[i]) out.print(" " + (i+1));
			out.println();
			out.flush();
			ans[l] = f.nextInt();
			out.print("!");
			for(int i : ans) out.print(" "+i);
			out.println();
			out.flush();
			if(f.next().equals("Incorrect")) break;
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