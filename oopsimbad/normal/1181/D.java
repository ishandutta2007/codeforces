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
		int n = f.nextInt(), m = f.nextInt(), q = f.nextInt();
		int[] pre = new int[m];
		for(int i = 0; i < n; i++) pre[f.nextInt()-1]++;
		Pair[] event = new Pair[m];
		for(int i = 0; i < m; i++) event[i] = new Pair(i+1, pre[i]);
		Arrays.sort(event);
		int[] ans = new int[q];
		QPair[] qu = new QPair[q];
		for(int i = 0; i < q; i++)
			qu[i] = new QPair(i, f.nextLong()-n-1);
		Arrays.sort(qu);
		int qi = 0;
		int ei = 0;
		long cw = 0;
		long cv = 0;
		long ch = 0;
		BIT b = new BIT(m);
		while(qi < q && ei < m) {
			long nh = event[ei].b;
			long nw = cw;
			long nv = cv + cw * (nh - ch);
			while(qi < q && qu[qi].b < nv) {
				ans[qu[qi].a] = b.get((int) ((qu[qi].b - cv) % cw + 1));
				qi++;
			}
			while(ei < m && event[ei].b == nh) {
				nw++;
				b.add(event[ei].a);
				ei++;
			}
			cv = nv;
			cw = nw;
			ch = nh;
		}
		while(qi < q) {
			ans[qu[qi].a] = b.get((int) ((qu[qi].b - cv) % cw + 1));
			qi++;
		}
		for(int i : ans)
			out.println(i);
///
		out.flush();
	}
	class BIT {
		int[] arr;
		public BIT(int sz) {
			arr = new int[sz+5];
		}
		public int get(int i) {
			int res = 0;
			int cur = 0;
			for(int b = 1<<30; b > 0; b >>= 1) {
				if(res + b < arr.length && cur + arr[res + b] < i) {
					res += b;
					cur += arr[res];
				}
			}
			return res;
		}
		public void add(int i) {
			i++;
			while(i < arr.length) {
				arr[i]++;
				i += i & -i;
			}
		}
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			return Integer.compare(b, p.b);
		}
	}
	class QPair implements Comparable<QPair> {
		int a;
		long b;
		public QPair(int a, long b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(QPair p) {
			return Long.compare(b, p.b);
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