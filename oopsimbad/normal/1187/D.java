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
			LinkedList<Integer>[] to = new LinkedList[n];
			for(int i = 0; i < n; i++) to[i] = new LinkedList<>();
			int[] a = new int[n];
			PriorityQueue<Pair> pq = new PriorityQueue<>();
			for(int i = 0; i < n; i++)
				pq.add(new Pair(a[i] = f.nextInt()-1, i));
			for(int i = 0; i < n; i++)
				to[f.nextInt()-1].add(i);
			init(n);
			int[] map = new int[n];
			boolean ok = true;
			for(int i = 0; i < n; i++) {
				if(to[a[i]].isEmpty()) {
					ok = false;
					break;
				}
				ins(i, map[i] = to[a[i]].pollFirst());
			}
			while(ok && !pq.isEmpty()) {
				int i = pq.poll().b;
				ok &= get(0, i) <= map[i];
				ins(i, 0);
			}
			out.println(ok ? "YES":"NO");
		}
///
		out.flush(); 
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			return -Integer.compare(a, p.a);
		}
	}
	int[] seg;
	int sz;
	void init(int sz) {
		this.sz = Integer.highestOneBit(sz);
		if(this.sz != sz) this.sz <<= 1;
		seg = new int[this.sz << 1];
	}
	void ins(int i, int v) {
		for(seg[i += sz] = v; i > 1; i >>= 1)
			seg[i>>1] = Math.max(seg[(i|1)^1], seg[i|1]);
	}
	int get(int l, int r) {
		int rl = 0, rr = 0;
		for(l += sz, r += sz+1; l < r; l >>= 1, r >>= 1) {
			if((l&1) == 1) rl = Math.max(rl, seg[l++]);
			if((r&1) == 1) rr = Math.max(rr, seg[--r]);
		}
		return Math.max(rl, rr);
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