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
		int n = f.nextInt();
		long[] add = new long[n];
		long[] bounds = new long[n+1];
		for(int i = 0; i < n; i++)
			add[i] = f.nextLong();
		for(int i = 0; i < n; i++)
			bounds[i+1] = f.nextLong() + bounds[i];
		for(int i = 0; i < n; i++) 
			add[i] += bounds[i];
		PriorityQueue<Long> pq = new PriorityQueue<Long>();
		for(int i = 0; i < n; i++) {
			pq.add(add[i]);
			long cnt = 0;
			while(!pq.isEmpty() && pq.peek() < bounds[i+1]) {
				cnt += pq.poll()-bounds[i];
			}
			cnt += (bounds[i+1] - bounds[i])*pq.size();
			out.print(cnt);
			out.print(" ");
		}
		out.flush();
	}
	int[] BIT;
	public void add(int n, int i) {
		i++;
		while(i < BIT.length) {
			BIT[i] += n;
			i += i & -i;
		}
	}
	public int query(int i) {
		i++;
		int res = 0;
		while(i > 0) {
			res += BIT[i];
			i -= i & -i;
		}
		return res;
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