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
        ///
        int n = f.nextInt(), h = f.nextInt(), m = f.nextInt(), k = f.nextInt();
        int[] arr = new int[n];
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        for(int i = 0; i < n; i++) {
            f.next();
            arr[i] = f.nextInt()%(m/2);
            pq.add(new Pair(arr[i]+1, 1));
            pq.add(new Pair(arr[i]+1-m/2, 1));
            pq.add(new Pair(arr[i]+k-m/2, -1));
            pq.add(new Pair(arr[i]+k, -1));
        }
        int best = n;
        int loc = -1;
        int cur = 0;
        while(!pq.isEmpty()) {
            Pair p = pq.poll();
            cur += p.d;
            if(cur < best && p.t >= 0 && p.t < m/2) {
                best = cur;
                loc = p.t;
            }
        }
        out.println(best + " " + loc);
        for(int i = 0; i < n; i++)
            if(arr[i]-m/2 < loc && arr[i]-m/2+k > loc || arr[i]+k > loc && arr[i] < loc) out.println(i+1);
///
		out.flush();
	}
    class Pair implements Comparable<Pair> {
        int t, d;
        public Pair(int a, int b) {
            t = a;
            d = b;
        }
        public int compareTo(Pair p) {
            if(t == p.t) return -Integer.compare(d, p.d);
            return Integer.compare(t, p.t);
        }
    }
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in), 32768);
			tokenizer = null;
		}
		public String next() { while (tokenizer == null || !tokenizer.hasMoreTokens()) {
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