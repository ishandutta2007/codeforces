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
        ok = new boolean[800000];
        up = new int[800000];
        down = new int[800000];
        init(0, 0, n);
        TreeSet<Integer>[] up = new TreeSet[n];
        TreeSet<Integer>[] down = new TreeSet[n];
        for(int i = 0; i < n; i++) up[i] = new TreeSet<>();
        for(int i = 0; i < n; i++) down[i] = new TreeSet<>();
        for(int i = 0; i < n; i++) {
            up[i].add(200001);
            down[i].add(-1);
        }
        while(q-->0) {
            int r = f.nextInt()-1, c = f.nextInt()-1;
            if(r % 2 == 1) {
                if(!down[r/2].add(c/2))
                    down[r/2].remove(c/2);
                update(0, 0, n, r/2, down[r/2].last(), true);
            } else {
                if(!up[r/2].add(c/2))
                    up[r/2].remove(c/2);
                update(0, 0, n, r/2, up[r/2].first(), false);
            }
            out.println(ok[0] ? "YES" : "NO");
        }
        ///
///
		out.flush();
	}
    public void init(int i, int l, int r) {
        if(l != r-1) {
            int m = (l+r)/2;
            init(2*i+1, l, m);
            init(2*i+2, m, r);
        }
        ok[i] = true;
        up[i] = 200001;
        down[i] = -1;
    }
    boolean[] ok;
    int[] up, down;
    public void update(int i, int l, int r, int qi, int qv, boolean b) {
        if(qi >= r || qi < l) return;
        if(l == r-1) {
            if(b) down[i] = qv;
            else up[i] = qv;
            ok[i] = up[i] > down[i];
        } else {
            int m = (l+r)/2;
            update(2*i+1, l, m, qi, qv, b);
            update(2*i+2, m, r, qi, qv, b);
            up[i] = Math.min(up[2*i+1], up[2*i+2]);
            down[i] = Math.max(down[2*i+1], down[2*i+2]);
            ok[i] = ok[2*i+1] && ok[2*i+2] && up[2*i+1] > down[2*i+2];
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