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
		adj = new ArrayList[n];
		cost = new ArrayList[n];
		for(int i = 0; i < n; i++) {
			adj[i] = new ArrayList<>();
			cost[i] = new ArrayList<>();
		}
		for(int i = 0; i < n-1; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1, c = f.nextInt();
			adj[a].add(b);
			adj[b].add(a);
			cost[a].add(c);
			cost[b].add(c);
		}
		int st = -1;
		for(int i = 0 ; i < n && st == -1; i++)
			if(adj[i].size() == 1) st = i;
		par = new int[n];
		sz = new int[n];
		total = new int[n];
		dfs(st, -1);
		boolean works = true;
		for(int i = 0; i < n; i++) 
			works &= st == i || sz[i] != 1;
		out.println(works ? "YES" : "NO");
		if(works) {
			ans = new LinkedList<>();
			FakeLL ll = dfs2(st);
			while(ll != null) {
				if(ll.v != 0) {
					ans.add(st+1); ans.add(ll.i); ans.add(ll.v);
				}
				ll = ll.nx;
			}
			out.println(ans.size()/3);
			while(!ans.isEmpty()) out.printf("%d %d %d%n", ans.poll(), ans.poll(), ans.poll());
		}
///
		out.flush();
	}
	LinkedList<Integer> ans;
	ArrayList<Integer>[] adj;
	ArrayList<Integer>[] cost;
	int[] par, sz, total;
	public void dfs(int i, int p) {
		if(p != -1) sz[p]++;
		par[i] = p;
		for(int a = 0; a < adj[i].size(); a++) {
			int j = adj[i].get(a);
			total[i] += cost[i].get(a);
			if(j == p) {
				adj[i].remove(a);
				cost[i].remove(a);
				a--;
			} else dfs(j, i);
		}
	}
	public FakeLL dfs2(int i) {
		int total = this.total[i];
		if(adj[i].size() == 0)
			return new FakeLL(i+1, total);
		FakeLL cur = dfs2(adj[i].get(0));
		total -= cost[i].get(0);
		for(int a = 1; a < adj[i].size(); a++) {
			FakeLL nx = dfs2(adj[i].get(a));
			total -= cost[i].get(a);
			int tv = (cur.t + nx.t - total)/2;
			while(tv != 0) {
				while(cur.nx != null && cur.v == 0) cur = cur.nx();
				while(nx.nx != null && nx.v == 0) nx = nx.nx();
				int v = Math.abs(tv);
				if(cur.nx != null && (cur.v < 0 == v < 0)) v = Math.min(v, Math.abs(cur.v)); 
				if(nx.nx != null && (nx.v < 0 == v < 0)) v = Math.min(v, Math.abs(nx.v)); 
				v *= Math.signum(tv);
				if(v != 0) {
					ans.add(cur.i); ans.add(nx.i); ans.add(v);
				}
				cur.v -= v;
				cur.t -= v;
				nx.v -= v;
				nx.t -= v;
				tv -= v;
			}
			nx.setnx(cur);
			cur = nx;
			while(cur.nx != null && cur.v == 0) cur = cur.nx;
		}
		return cur;
	}
	class FakeLL {
		int i, v, t;
		FakeLL nx, f;
		public FakeLL(int i, int v) {
			this.i = i;
			this.v = v;
			this.t = v;
			f = this;
		}
		public void setnx(FakeLL n) {
			f.nx = n;
			t += n.t;
			f = n.f;
		}
		public FakeLL nx() {
			nx.f = f;
			nx.t = t;
			return nx;
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