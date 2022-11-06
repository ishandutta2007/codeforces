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
			int[] arr = new int[n];
			for(int i = 0; i < n; i++) arr[i] = f.nextInt();
			int m = f.nextInt();
			Pair[] parr = new Pair[m];
			for(int i = 0; i < m; i++) parr[i] = new Pair(f.nextInt(), f.nextInt());
			Arrays.sort(parr);
			int cur = 0;
			for(int i = 1; i < m; i++) {
				while(cur != -1 && parr[cur].b < parr[i].b) cur--;
				parr[++cur] = parr[i];
			}
			m = cur+1;
			int ans = 1;
			int start = 0;
			int max = arr[0];
			for(int i = 0; i < n; i++) {
				int l = 0, r = m;
				while(l < r) {
					int mid = (l+r)/2;
					if(parr[mid].b <= i-start) r = mid;
					else l= mid+1;
				}
				l--;
				max = Math.max(max, arr[i]);
				if(l == -1 || parr[l].a < max) {
					ans++;
					start = i;
					max = arr[i];
					if(parr[m-1].a < max) {
						ans = -1;
						break;
					}
				}
			}
			out.println(ans);
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
			return Integer.compare(a, p.a);
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