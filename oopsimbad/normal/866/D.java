import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		PriorityQueue<Integer> canBuy = new PriorityQueue<Integer>();
		PriorityQueue<Pair> sold = new PriorityQueue<Pair>();
		long tp = 0;
		for(int i = 0; i < n; i++) {
			int val = f.nextInt();
			if(!canBuy.isEmpty() && canBuy.peek() < val) {
				int buyval = canBuy.peek();
				if(!sold.isEmpty() && sold.peek().x < buyval) {
					Pair p = sold.poll();
					canBuy.add(p.x);
					tp += val - p.x;
					p.x = val;
					sold.add(p);
				} else {
					canBuy.poll();
					sold.add(new Pair(val,val-buyval));
					tp += val - buyval;
				}
			} else if(!sold.isEmpty() && sold.peek().x < val) {
				Pair p = sold.poll();
				canBuy.add(p.x);
				tp += val - p.x;
				p.x = val;
				sold.add(p);
			} else canBuy.add(val);
			//System.out.println(canBuy);
			//System.out.println(sold);
		}
		System.out.println(tp);
		
 		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int x, y;
		public Pair(int a, int b) {
			x = a;
			y = b;
		}
		public int compareTo(Pair p) {
			return x - p.x;
		}
		public String toString() {
			return x + "," + y;
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

    }
}