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
		int n = f.nextInt();
		int[] arr = new int[n];
		Pair[] p = new Pair[n];
		for(int i = 0; i < n; i++) {
			arr[i] = -6000000;
			p[i] = new Pair(f.nextInt(), i);
		}
		Arrays.sort(p);
		int pi = 0;
		int ans = 0;
		for(int v = -30; v <= 30; v++) {
			while(pi < n && p[pi].a == v)
				arr[p[pi++].i] = v;
			int best = -20000000;
			int cur = -20000000;
			for(int i = 0; i < n; i++)
				best = Math.max(best,cur = Math.max(cur+arr[i],arr[i]));
			ans = Math.max(ans, best-v);
		}
		out.println(ans);
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, i;
		public Pair(int a, int i) {
			this.a = a;
			this.i = i;
		}
		public int compareTo(Pair p) {
			return Integer.compare(a,p.a);
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