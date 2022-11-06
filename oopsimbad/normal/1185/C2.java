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
        int n = f.nextInt(), m = f.nextInt();
        int[] arr = new int[n];
        int[] map = new int[n];
        for(int i = 0; i < n; i++)
            arr[i] = f.nextInt();
        {
            ArrayList<Pair> p = new ArrayList<>();
            for(int i = 0; i < n; i++)
                p.add(new Pair(i, arr[i]));
            Collections.sort(p);
            for(int i = 0; i < n; i++)
                map[p.get(i).i] = i;
        }
        BIT b = new BIT(n);
        BIT c = new BIT(n);
        int[] ans = new int[n];
        for(int i = 0; i < n; i++) {
            int l = 0, r = n;
            while(l < r) {
                int mid = (l+r)/2;
                if(b.get(mid) > m-arr[i]) r = mid;
                else l = mid+1;
            }
            ans[i] = i - c.get(r-1);
            c.upd(map[i],1);
            b.upd(map[i],arr[i]);
        }
        for(int i : ans) out.print(i + " ");
        out.flush();
    }
    class Pair implements Comparable<Pair> {
        int v, i;
        public Pair(int i, int v) {
            this.i = i;
            this.v = v;
        }
        public int compareTo(Pair p) {
            return Integer.compare(v,p.v);
        }
    }
    class BIT {
        int[] a;
        public BIT(int sz) {
            a = new int[sz+5];
        }
        public int get(int i) {
            int res = 0;
            i++;
            while(i > 0) {
                res += a[i];
                i -= i  & -i;
            }
            return res; 
        }
        public void upd(int i, int k) {
            i++;
            while(i < a.length) {
                a[i] += k;
                i += i & -i;
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