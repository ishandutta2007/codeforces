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
		long[] dist = new long[n];
		long MOD = 1_000_000_007;
		int[] max1 = new int[n];
		long[] max2 = new long[n];
		Arrays.fill(dist, Long.MIN_VALUE);
		Arrays.fill(max2, Long.MIN_VALUE);
		dist[0] = 0;
		ArrayList<Pair> al = new ArrayList<>();
		for(int i = 0; i < m; i++) {
			int	a = f.nextInt()-1, b = f.nextInt()-1;
			int v = f.nextInt();
			al.add(new Pair(a,b,v));
			max1[a] = Math.max(max1[a],v);
			max1[b] = Math.max(max1[b],v);
		}
		max2[0] = 0;
		long ans = 0;
		for(long it = 1; it < n; it++) {
			long[] ndist = new long[n];
			Arrays.fill(ndist, Long.MIN_VALUE);
			for(Pair p : al) {
				ndist[p.j] = Math.max(ndist[p.j], dist[p.i]+p.v);
				ndist[p.i] = Math.max(ndist[p.i], dist[p.j]+p.v);
			}
			dist = ndist;
			long max = 0;
			for(int i = 0; i < n; i++) {
				if(dist[i] > 0) max2[i] = Math.max(max2[i], dist[i]-it*max1[i]);
				max = Math.max(max,dist[i]);
			}
			if(it < n-1) ans += max;
		}
		Line[] arr = new Line[n];
		for(int i = 0; i < n; i++)
			arr[i] = new Line(max1[i],max2[i]);
		Arrays.sort(arr);
		ArrayList<Line> ch = new ArrayList<>();
		ArrayList<Double> inter = new ArrayList<>();
		inter.add(0.0);
		for(Line l : arr) {
			if(l.b < Integer.MIN_VALUE) continue;
			while(true) {
				if(ch.size() >= 2 && computeInter(ch.get(ch.size()-2), l) <= inter.get(inter.size()-1) || ch.size() >= 1 && ch.get(ch.size()-1).m == l.m) {
					if(ch.size() != 1) inter.remove(inter.size()-1);
					ch.remove(ch.size()-1);
				} else break;
			}
			if(!ch.isEmpty()) inter.add(computeInter(ch.get(ch.size()-1), l));
			ch.add(l);
		}
		inter.add(1.0*k);
		for(int i = 0; i < ch.size(); i++) {
			long l =  Math.max((long) Math.floor(inter.get(i)), n-2);
			long r = Math.min((long) Math.floor(inter.get(i+1)), k);
			Line line = ch.get(i);
			if(r <= l) continue;
			ans = (ans + (r-l)*line.b%MOD)%MOD;
			ans = (ans - (l*(l+1)/2)%MOD*line.m%MOD+MOD)%MOD;
			ans = (ans + (r*(r+1)/2)%MOD*line.m%MOD+MOD)%MOD;
		}
		out.println(ans);
///
		out.flush();
	}
	public double computeInter(Line l1, Line l2) {
		double x = l1.b - l2.b;
		x /= l2.m - l1.m;
		return x;
	}
	class Line implements Comparable<Line> {
		long m, b;
		public Line(long a, long c) {
			this.m = a;
			this.b = c;
		}
		public int compareTo(Line l) {
			if(m == l.m) return Long.compare(b, l.b);
			return Long.compare(m, l.m);
		}
		public String toString() {return "("+m +","+b+")";}
	}
	class Pair {
		int i, j; long v;
		public Pair(int a, int b, long c) {
			i = a;
			j = b;
			v = c;
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