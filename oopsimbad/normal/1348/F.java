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
		min = new int[4*n];
		max = new int[4*n];
		for(int i = 0; i < min.length; i++) {
			min[i] = 2147483647;
			max[i] = -2147483648;
		}
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		LinkedList<Pair>[] ll = new LinkedList[n];
		for(int i = 0; i < n; i++) ll[i] = new LinkedList<>();
		for(int i = 0; i < n; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			ll[a].add(new Pair(b, i, a));
		}
		Pair[] arr = new Pair[n];
		for(int i = 0; i < n; i++) {
			for(Pair p : ll[i]) pq.add(p);
			Pair p = pq.poll();
			arr[i] = p;
			insMin(0, 0, n, i, p.c);
			insMax(0, 0, n, i, p.a);
		}
		boolean found = false;
		for(int i = 0; i < n; i++) {
			if(getMax(0, 0, n, arr[i].c, i) >= i) {
				out.println("NO");
				int[] ans = new int[n];
				for(int a = 0; a < n; a++) ans[arr[a].b] = a;
				for(int a : ans) out.print(a + 1 + " ");
				out.println();
				int j;
				for(j = arr[i].c; j < i; j++)
					if(arr[j].a >= i)
						break;
				ans[arr[j].b] = i;
				ans[arr[i].b] = j;
				for(int a : ans) out.print(a + 1 + " ");
				out.println();
				found = true;
				break;
			}
			if(getMin(0, 0, n, i+1, arr[i].a+1) <= i) {
				out.println("NO");
				int[] ans = new int[n];
				for(int a = 0; a < n; a++) ans[arr[a].b] = a;
				for(int a : ans) out.print(a + 1 + " ");
				out.println();
				int j;
				for(j = i+1; j <= arr[i].a; j++)
					if(arr[j].c <= i)
						break;
				ans[arr[j].b] = i;
				ans[arr[i].b] = j;
				for(int a : ans) out.print(a + 1 + " ");
				out.println();
				found = true;
				break;
			}
		}
		if(!found) {
			out.println("YES");
			int[] ans = new int[n];
			for(int i = 0; i < n; i++) ans[arr[i].b] = i;
			for(int i : ans) out.print(i + 1 + " ");
			out.println();
		}
		out.flush();
	}

	class Pair implements Comparable<Pair> {
		int a, b, c;
		public Pair(int a, int b, int c) {
			this.a = a;
			this.b = b;
			this.c = c;
		}
		public int compareTo(Pair p) {
			return Integer.compare(a, p.a);	
		}
	}
	int[] min, max;
	public int getMax(int i, int l, int r, int ql, int qr) {
		if(ql < l) ql = l;
		if(qr > r) qr = r;
		if(qr <= l || ql >= r) return -2147483648;
		if(ql == l && qr == r) return max[i];
		int m = (l+r)/2;
		return Math.max(getMax(2*i+1, l, m, ql, qr),getMax(2*i+2, m, r, ql, qr));
	}
	public int getMin(int i, int l, int r, int ql, int qr) {
		if(ql < l) ql = l;
		if(qr > r) qr = r;
		if(qr <= l || ql >= r) return 2147483647;
		if(ql == l && qr == r) return min[i];
		int m = (l+r)/2;
		return Math.min(getMin(2*i+1, l, m, ql, qr),getMin(2*i+2, m, r, ql, qr));
	}
	public void insMax(int i, int l, int r, int qi, int qv) {
		max[i] = Math.max(max[i],qv);
		if(l != r-1) {
			int m = (l+r)/2;
			if(qi < m) insMax(2*i+1, l, m, qi, qv);
			else insMax(2*i+2, m, r, qi, qv);
		}
	}
	public void insMin(int i, int l, int r, int qi, int qv) {
		min[i] = Math.min(min[i],qv);
		if(l != r-1) {
			int m = (l+r)/2;
			if(qi < m) insMin(2*i+1, l, m, qi, qv);
			else insMin(2*i+2, m, r, qi, qv);
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