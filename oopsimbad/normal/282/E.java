import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static final long MOD = 998_244_353;
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		long[] arr = new long[n];
		long[] pref = new long[n];
		long total = 0;
		for(int i = 0; i < n; i++) {
			total ^= arr[i] = f.nextLong();
			if(i == 0) pref[i] = arr[i];
			else pref[i] = pref[i-1] ^ arr[i];
		}
		Node root = new Node(0, 1L << 40);
		long max = total;
		for(int i = 0; i < n; i++) {
			total ^= arr[i];
			max = Math.max(max, total ^ root.get(total));
			root.add(pref[i]);
		}
		out.println(max);
		out.flush();
	}
	class Node {
		Node[] c;
		long cur;
		boolean done;
		long bit;
		public Node(long cu, long b) {
			c = new Node[2];
			cur = cu;
			done = false;
			bit = b;
		}
		public void add(long l) {
			if(cur == l) return;
			if(!done) {
				if((cur & bit) > 0)
					c[1] = new Node(cur,bit>>1);
				else
					c[0] = new Node(cur,bit>>1);
			}
			done = true;
			if((l & bit) > 0) {
				if(c[1] == null) c[1] = new Node(l, bit>>1);
				c[1].add(l);
			}
			else {
				if(c[0] == null) c[0] = new Node(l, bit>>1);
				else c[0].add(l);
			}
		}
		public long get(long l) {
			if(!done) return cur;
			if((l & bit) > 0) {
				if(c[0] != null) return c[0].get(l);
				return c[1].get(l);
			} else {
				if(c[1] != null) return c[1].get(l);
				return c[0].get(l);
			}
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