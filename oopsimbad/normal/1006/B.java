import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static final int MOD = 1_000_000_007;
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), k = f.nextInt();
		PriorityQueue<Pair> pq = new PriorityQueue<Pair>(new Comparator<Pair>() {
			public int compare(Pair p1, Pair p2) {
				return -Long.compare(p1.b, p2.b);
			}
		});
		for(int i = 0; i < n; i++)
			pq.add(new Pair(i,f.nextLong()));
		PriorityQueue<Pair> pq2 = new PriorityQueue<Pair>(new Comparator<Pair>() {
			public int compare(Pair p1, Pair p2) {
				return Integer.compare(p1.a, p2.a);
			}
		});
		long sum = 0;
		for(int i = 0; i < k; i++) {
			sum += pq.peek().b;
			pq2.add(pq.poll());
		}
		out.println(sum);
		int prev = -1;
		for(int i = 0; i < k-1; i++) {
			int index = pq2.poll().a;
			out.print(index-prev);
			out.print(" ");
			prev = index;
		}
		out.print(n-prev-1);
		out.flush();
	}
	class Pair {
		int a;
		long b;
		public Pair(int a, long b) {
			this.a = a;
			this.b = b;
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