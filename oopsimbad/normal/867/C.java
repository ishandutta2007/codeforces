import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		long n = f.nextLong(), sps = f.nextLong();
		ArrayList<P> vals = new ArrayList<P>(10000);
		long max = 0;
		long total = 0;
		for(int i = 0; i < n; i++) {
			long s = f.nextLong(), ii = f.nextLong(), j = f.nextLong();
			//long s = 100000, ii = 100000, j = 100000;
			max += s*ii;
			vals.add(new P(s,ii,j));
			total += s;
		}
		if(total % sps != 0) vals.add(new P(sps - total%sps,0,0));
		//System.out.println(max);
		Collections.sort(vals);
		long sl = 0;
		long av = 0;
		for(int i = 0; i < vals.size();i++) {
			P p = vals.get(i);
			if(p.c + sl >= sps) {
				if((av += p.v * (sps-sl)) <= 0) break;
				max += av;
				if(p.v <= 0) break;
				max += (p.c-sps+sl)/sps*sps * p.v;
				sl = (p.c - sps + sl) % sps;
				av = sl * p.v;
			} else {
				av += p.c * p.v;
				sl += p.c;
			}
		}
		out.println(max);
		out.flush();
	}
	class P implements Comparable<P> {
		long v, c;
		public P(long s,long i, long j) {
			c = s;
			v = j-i;
		}
		public int compareTo(P p) {
			return Long.compare(p.v, v);
		}
		public String toString() {
			return c + " " + v;
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