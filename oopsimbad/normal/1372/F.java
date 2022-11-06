import java.io.*; 
import java.text.*; 
import java.util.*; 
import java.math.*;
public class template { 
    public static void main(String[] args) throws Exception {
        new template().run();
    } 
    public void run() throws Exception { 
        f = new FastScanner(); 
        out = new PrintWriter(System.out); 
        int n = f.nextInt(); 
        query(0, n);
        arr = new int[n]; 
        hm = new HashMap<>();
        solve(0, n, f.nextInt(), f.nextInt());
        out.print("!");
        for(int i : arr) out.print(" "+i);
///
		out.flush();
	}
    HashMap<Integer,Integer> hm;
    int[] arr;
    public int solve(int l, int r, int x, int m) {
        if(hm.containsKey(x)) {
            if(hm.get(x) >= r) {
                hm.remove(x);
                for(int i = r-m; i < r; i++)
                    arr[i] = x;
                if(r-m > l) {
                    query(l, r-m);
                    solve(l, r-m, f.nextInt(), f.nextInt());
                }
                return arr[r-1];
            } else {
                hm.remove(x);
                for(int i = l; i < l+m; i++)
                    arr[i] = x;
                if(l+m < r) {
                    query(l+m, r);
                    solve(l+m, r, f.nextInt(), f.nextInt());
                }
                return arr[r-1];
            }
        } else hm.put(x,r);
        if(r-l == m) {
            for(int i = l; i < r; i++) arr[i] = x;
            return arr[r-1];
        }
        while(l < r) {
            query(l, l+m);
            if(solve(l, l+m, f.nextInt(), f.nextInt()) == x) {
                int i = l+m-1;
                while(i > l && arr[i-1] == x) i--;
                l = i;
                for(i = l; i < l+m; i++) arr[i] = x;
                l += m;
                if(l < r) {
                    query(l, r);
                    solve(l, r, f.nextInt(), f.nextInt());
                }
                break;
            }
            l += m;
        }
        return arr[r-1];
    }
    FastScanner f; 
    PrintWriter out; 
    public void query(int l, int r) {
        out.printf("? %d %d%n", l+1, r);
        out.flush();
    }
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in), 32768);
			tokenizer = null;
		}
		public String next() { while (tokenizer == null || !tokenizer.hasMoreTokens()) {
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