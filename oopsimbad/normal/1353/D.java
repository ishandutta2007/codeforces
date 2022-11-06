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
			int[] ans = new int[n];
			PriorityQueue<A> pq = new PriorityQueue<>();
			pq.add(new A(0,n-1));
			for(int i = 0; i < n; i++) {
				A a = pq.poll();
				int m = (a.l+a.r)/2;
				ans[m] = i+1;
				if(a.l <= m-1) pq.add(new A(a.l, m-1));
				if(a.r >= m+1) pq.add(new A(m+1, a.r));
			}
			for(int i : ans) out.print(i + " ");
			out.println();
		}
			
		out.flush();
	}
	class A implements Comparable<A> {
		int l, r;
		public A(int l, int r) {
			this.l = l;
			this.r = r;
		}
		public int compareTo(A a) {
			if(r-l == a.r-a.l) return l-a.l;
			return a.r-a.l-r+l;
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