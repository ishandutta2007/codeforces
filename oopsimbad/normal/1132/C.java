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
		int n = f.nextInt(), q = f.nextInt();
		Pair[] arr = new Pair[q];
		int[] total = new int[n];
		for(int i = 0 ; i < q; i++) {
			arr[i] = new Pair(f.nextInt(), f.nextInt());
			for(int j = arr[i].l; j < arr[i].r; j++)
				total[j]++;
		}
		long best = 0;
		for(int i = 0; i < q; i++) {
			for(int j = arr[i].l; j < arr[i].r; j++)
				total[j]--;
			int[] total2 = new int[n+1];
			long tot = 0;
			for(int j = 0; j < n; j++) {
				total2[j+1] = total2[j] + (total[j] == 1 ? 1 : 0);
				if(total[j] != 0) tot++;
			}
			for(int j = 0; j < q; j++) {
				if(j == i) continue;
				best = Math.max(best, tot - (total2[arr[j].r] - total2[arr[j].l]));
			}
			for(int j = arr[i].l; j < arr[i].r; j++)
				total[j]++;
		}
		out.println(best);
		out.flush();
	}
	class Pair {
		int l, r;
		public Pair(int a, int b) {
			l = a-1;
			r = b;
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