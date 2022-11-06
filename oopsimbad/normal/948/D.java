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
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = f.nextInt();
		TrieNode root = new TrieNode(30);
		for(int i = 0; i < n; i++)
			root.insert(f.nextInt());
		for(int i : arr) {
			int ans = root.query(i, 0);
			out.print(ans ^ i);
			out.print(" ");
		}
		out.flush();
	}
	class TrieNode {
		int size;
		TrieNode l, r;
		int cnt;
		int depth;
		public TrieNode(int depth) {
			size = 0;
			cnt = 0;
			this.depth = depth;
		}
		public void insert(int i) {
			if(depth == -1) {
				cnt++;
			}
			else if((i & (1 << depth)) != 0) {
				if(r == null) r = new TrieNode(depth-1);
				r.insert(i);
			} else {
				if(l == null) l = new TrieNode(depth-1);
				l.insert(i);
			}
			size++;
		}
		public int query(int i, int v) {
			size--;
			if(depth == -1) return v;
			if((i & (1 << depth)) != 0) {
				if(r == null || r.size == 0)
					return l.query(i, v << 1);
				else return r.query(i, v << 1 | 1);
			} else {
				if(l == null || l.size == 0)
					return r.query(i, v << 1 | 1);
				else return l.query(i, v << 1);
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