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
		TreeSet<Integer> ts = new TreeSet<>();
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		for(int i = 0; i < n; i++) {
			int a = f.nextInt(), b = f.nextInt();
			ts.add(a);
			pq.add(new Pair(a,b));
		}
		HashMap<Integer,Integer> hm = new HashMap<>();
		int sz = 0;
		for(int i : ts) hm.put(i,sz++);
		long ans = 0;
		boolean[] exists = new boolean[n];
		long tot = 0;
		BIT b = new BIT(sz);
		while(!pq.isEmpty()) {
			int y = pq.peek().b;
			int prev = -1;
			while(!pq.isEmpty() && pq.peek().b == y) {
				int x = hm.get(pq.poll().a);
				if(!exists[x]) {
					exists[x] = true;
					b.add(x);
					tot++;
				}
				long t = b.get(prev, x-1);
				ans -= t * (t+1)/2;
				prev = x;
			}
			long t = b.get(sz, prev-1);
			ans += tot * (tot+1)/2 - t * (t+1)/2;
		}
		out.println(ans);
///
		out.flush(); 
	}
	class BIT {
		int[] arr;
		public BIT(int sz) {
			arr = new int[sz+5];
		}
		public int get(int l, int r) {
			return get(r) - get(l);
		}
		public void add(int i) {
			i++;
			while(i < arr.length) {
				arr[i]++;
				i += i & -i;
			}
		}
		public int get(int i) {
			i++;
			int res = 0;
			while(i > 0) {
				res += arr[i];
				i -= i & -i;
			}
			return res;
		}
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			if(b == p.b) return Integer.compare(a, p.a);
			return -Integer.compare(b, p.b);
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