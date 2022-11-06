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
		int m = f.nextInt();
		int[] arr = new int[2*n];
		int[] map = new int[2*n];
		TreeSet<Pair> ts = new TreeSet<Pair>();
		for(int i = 0; i < 2*n; i++) {
			arr[i] = f.nextInt();
			map[i] = -1;
			ts.add(new Pair(i,arr[i]));
		}
		Pair[] parr = new Pair[m];
		for(int i = 0; i < m; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			parr[i] = new Pair(a,b);
			map[a] = i;
			map[b] = i;
		}
		int t = f.nextInt();
		int total = 2*n;
		if(t == 2) {
			while(total > 0) {
				int pick = f.nextInt()-1;
				ts.remove(new Pair(pick, arr[pick]));
				total--;
				if(map[pick] == -1) break;
				total--;
				Pair p = parr[map[pick]];
				p.use = false;
				int other = p.a + p.b - pick;
				out.println(other + 1);
				out.flush();
				ts.remove(new Pair(other, arr[other]));
			}
			for(Pair p : parr) {
				if(p.use) {
					if(arr[p.a] > arr[p.b])
						out.println(p.a+1);
					else out.println(p.b+1);
					out.flush();
					f.nextInt();
					ts.remove(new Pair(p.a,arr[p.a]));
					ts.remove(new Pair(p.b,arr[p.b]));
					total -= 2;
				}
			}
			while(total > 1) {
				out.println(ts.pollFirst().a+1);
				out.flush();
				int pick = f.nextInt()-1;
				ts.remove(new Pair(pick, arr[pick]));
				total -= 2;
			}
			if(!ts.isEmpty()) out.println(ts.pollFirst().a+1);
		} else {
			for(Pair p : parr) {
				if(p.use) {
					if(arr[p.a] > arr[p.b])
						out.println(p.a+1);
					else out.println(p.b+1);
					out.flush();
					f.nextInt();
					ts.remove(new Pair(p.a,arr[p.a]));
					ts.remove(new Pair(p.b,arr[p.b]));
					total -= 2;
				}
			}
			while(total > 0) {
				out.println(ts.pollFirst().a+1);
				out.flush();
				int pick = f.nextInt()-1;
				ts.remove(new Pair(pick, arr[pick]));
				total -= 2;
			}
		}
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		boolean use;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
			use = true;
		}
		public int compareTo(Pair p) {
			if(b == p.b) return Integer.compare(a, p.a);
			return -Integer.compare(b, p.b);
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