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
		ArrayList<Q> al = new ArrayList<>();
		for(int i = 0; i < n; i++) {
			int x1 = f.nextInt()+5000;
			int y1 = f.nextInt()+5000;
			int x2 = f.nextInt()+5000;
			int y2 = f.nextInt()+5000;
			if(y1 == y2) al.add(new Q(x1, x2, y1, i));
			else {
				al.add(new Q(x1, y1, y1 < y2, i));
				al.add(new Q(x1, y2, y2 < y1, i));
			}
		}
		Collections.sort(al);
		long ans = 0;
		for(int i = 0; i < al.size(); i++) {
			if(!al.get(i).q) continue;
			int l = al.get(i).x1;
			int r = al.get(i).x2;
			BIT b = new BIT(10000);
			HashSet<Integer> hs = new HashSet<>();
			for(int j = 0; j < al.size(); j++) {
				Q q = al.get(j);
				if(q.q) {
					if(j <= i) continue;
					long v = b.get(q.x2) - b.get(q.x1-1);
					ans += v * (v-1)/2;
				} else {
					if(q.x1 < l || q.x1 > r) continue;
					if(q.add && j < i) {
						b.add(q.x1, 1);
						hs.add(q.i);
					}
					else 
						if(hs.remove(q.i)) b.add(q.x1, -1);
				}
			}
		}
		out.println(ans);
///
		out.flush(); 
	}
	 class BIT {
		 int[] arr;
		 public BIT(int sz) {
			 arr = new int[sz+5];
		 }
		 public int get(int i) {
			 i++;
			 int res = 0;
			 while(i > 0) {
				 res += arr[i];
				 i -= i & -i;
			 }
			 return res;
		 }
		 public void add(int i, int v) {
			 i++;
			 while(i < arr.length) {
				 arr[i]+=v;
				 i += i & -i;
			 }
		 }
	 }
	 class Q implements Comparable<Q> {
		 int x1, x2, y, i;
		 boolean q; boolean add;
		 public Q(int x1, int x2, int y, int i) {
			 this.i = i;
			 if(x2 < x1) {
				 x1 ^= x2;
				 x2 ^= x1;
				 x1 ^= x2;
			 }
			 this.x1 = x1;
			 this.x2 = x2;
			 this.y = y;
			 q = true;
		 }
		 public Q(int x, int y, boolean add, int i) {
			 this.i = i;
			 this.x1 = x;
			 this.y = y;
			 this.add = add;
		 }
		 public int compareTo(Q q) {
			 if(y != q.y) return Integer.compare(y, q.y);
			 int a = 1;
			 if(!this.q) {
				 a = 2;
				 if(add) a = 0;
			 }
			 int b = 1;
			 if(!q.q) {
				 b = 2;
				 if(q.add) b = 0;
			 }
			 return Integer.compare(a, b);
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