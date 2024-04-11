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
		int n = f.nextInt(), m = f.nextInt(), k = f.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = f.nextInt();
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		for(int i = 0; i < n-1; i++)
			pq.add(-(arr[i+1]-arr[i]-1));
		long total = arr[n-1] - arr[0] + 1;
		for(int i = 1; i < k; i++)
			total += pq.poll();
		out.println(total);
		out.flush();
	}
	class Pair implements Comparable<Pair>{
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			if(a != p.a) return -Integer.compare(a,p.a);
			return Integer.compare(b, p.b);
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