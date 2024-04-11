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
		final int n = f.nextInt();
		final int d = f.nextInt();
		long total = 0;
		int cnt = 0;
		Pair[] parr = new Pair[n];
		int psize = 0;
		long max = 0;
		for(int i = 0; i < n; i++) {
			int val = f.nextInt();
			max = Math.max(val, max);
			if(val == 0) {
				parr[psize++] = new Pair(total,max);
				max = 0;
				if(total < 0) total = 0;
			} else total += val;
			if(total > d) {
				System.out.println(-1);
				return;
			}
		}
		if(total > d) {
			System.out.println(-1);
			return;
		}
		for(int i = 0; i < psize; i++) if(parr[i].sum > d) {
			System.out.println(-1);
			return;
		}
		for(int i = 0; i < psize; i++) {
			while(i < psize && parr[i].sum >= 0) i++;
			if(i == psize) break;
			cnt++;
			long minopen = Long.MAX_VALUE;
			while(i < psize-1) {
				Pair next = parr[i+1];
				minopen = Math.min(minopen, d-next.max);
				if(-next.sum > minopen) {
					break;
				}
				minopen += next.sum;
				i++;
			}
		}
		out.println(cnt);
		out.flush();
	}
	class Pair {
		long sum, max;
		public Pair(long x, long y) {
			sum = x;
			max = y;
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