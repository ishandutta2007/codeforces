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
		int n = f.nextInt();
		int[] arr = new int[2*n];
		for(int i = 0; i < 2*n; i++)
			arr[i] = f.nextInt();
		int l = 0, h = 21;
		LinkedList<Integer>[] hm = new LinkedList[1 << 20];
		int[] am = new int[1 << 20];
		int[] ex = new int[1 << 20];
		int[] am2 = new int[1 << 20];
		DSU(2*n);
		int asdf = 1;
		while(l < h) {
			int m = (l+h)/2;
			for(int i = 0; i < 2*n; i++) {
				par[i] = i;
				sz[i] = 1;
				int a = arr[i] & ((1 << m)-1);
				if(am[a] != asdf) {
					hm[a] = new LinkedList<>();
					am[a] = asdf;
				}
				hm[a].add(i);
			}
			boolean[] vis = new boolean[2*n];
			boolean works = true;
			{
				int end = arr[0] & ((1 << m)-1);
				int cur = arr[1] & ((1 << m)-1);
				union(1,0);
				ex[cur] = 1;
				am2[cur] = asdf;
				vis[0] = vis[1] = true;
				while(cur != end) {
					Integer nx = hm[cur].pollFirst();
					while(nx != null && vis[nx])
						nx = hm[cur].pollFirst();
					if(nx == null) {
						works = false;
						break;
					}
					union(nx,0); union(nx^1,0);
					vis[nx] = vis[nx^1] = true; 
					cur = arr[nx^1] & ((1 << m)-1);
					if(am2[cur] != asdf) {
						ex[cur] = nx^1;
						am2[cur] = asdf;
					}
				}
			}
			for(int i = 2; works && i < 2*n; i += 2) {
				if(vis[i]) continue;
				int end = arr[i] & ((1 << m)-1);
				int cur = arr[i+1] & ((1 << m)-1);
				union(i+1,i);
				if(am2[cur] == asdf) union(ex[cur],i+1);
				else {
					ex[cur] = i+1;
					am2[cur] = asdf;
				}
				vis[i] = vis[i+1] = true;
				while(cur != end) {
					Integer nx = hm[cur].pollFirst();
					while(nx != null && vis[nx])
						nx = hm[cur].pollFirst();
					if(nx == null) {
						works = false;
						break;
					}
					union(nx,i); union(nx^1,i);
					vis[nx] = vis[nx^1] = true; 
					cur = arr[nx^1] & ((1 << m)-1);
					if(am2[cur] == asdf) union(ex[cur],i);
					else {
						ex[cur] = nx^1;
						am2[cur] = asdf;
					}
				}
			}
			works &= sz[find(0)] == 2*n;
			if(works) l = m+1;
			else h = m;
			asdf++;
		}
		out.println(h-1);
		int m = h-1;
		for(int i = 0; i < 2*n; i++) {
			par[i] = i;
			sz[i] = 1;
			int a = arr[i] & ((1 << m)-1);
			if(am[a] != asdf) {
				hm[a] = new LinkedList<>();
				am[a] = asdf;
			}
			hm[a].add(i);
		}
		int[] next = new int[2*n];
		boolean[] vis = new boolean[2*n];
		{
			int end = arr[0] & ((1 << m)-1);
			int cur = arr[1] & ((1 << m)-1);
			union(1,0);
			ex[cur] = 1;
			am2[cur] = asdf;
			next[0] = 1;
			int curi = 1;
			vis[0] = vis[1] = true;
			while(cur != end) {
				Integer nx = hm[cur].pollFirst();
				while(nx != null && vis[nx])
					nx = hm[cur].pollFirst();
				vis[nx] = vis[nx^1] = true;
				union(nx,0); union(nx^1,0);
				next[curi] = nx;
				next[nx] = nx^1;
				curi = nx^1;
				cur = arr[curi] & ((1 << m)-1);
				if(am2[cur] != asdf) {
					ex[cur] = curi;
					am2[cur] = asdf;
				}
			}
			next[curi] = 0;
		}
		for(int i = 2; i < 2*n; i += 2) {
			if(vis[i]) continue;
			int end = arr[i] & ((1 << m)-1);
			int cur = arr[i+1] & ((1 << m)-1);
			int curi = i+1;
			union(i+1,i);
			if(am2[cur] == asdf) {
				if(union(ex[cur],i+1)) {
					int a = ex[cur];
					int b = next[a];
					next[a] = next[curi];
					next[curi] = b;
					curi = a;
				}
			} else {
				ex[cur] = i+1;
				am2[cur] = asdf;
			}
			vis[i] = vis[i+1] = true;
			next[i] = i+1;
			while(cur != end) {
				Integer nx = hm[cur].pollFirst();
				while(nx != null && vis[nx])
					nx = hm[cur].pollFirst();
				union(nx,i); union(nx^1,i);
				vis[nx] = vis[nx^1] = true;
				next[curi] = nx;
				next[nx] = nx^1;
				curi = nx^1;
				cur = arr[nx^1] & ((1 << m)-1);
				if(am2[cur] == asdf) {
					if(union(ex[cur],i)) {
						int a = ex[cur];
						int b = next[a];
						next[a] = next[curi];
						next[curi] = b;
						curi = a;
					}
				} else {
					ex[cur] = curi;
					am2[cur] = asdf;
				}
			}
			next[curi] = i;
		}
		int i = 0;
		while(true) {
			out.print(i+1+ " ");
			i = next[i];
			if(i == 0) break;
		}
		out.println();
		out.flush();
	}
	int[] par, sz;
	public void DSU(int n) {
		par = new int[n];
		sz= new int[n];
	}
	public int find(int x) {
		if(par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	public boolean union(int x, int y) {
		x = find(x); y = find(y);
		if(x == y) return false;
		if(sz[x] < sz[y]) {
			sz[y] += sz[x];
			par[x] = y;
		} else {
			sz[x] += sz[y];
			par[y] = x;
		}
		return true; 
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