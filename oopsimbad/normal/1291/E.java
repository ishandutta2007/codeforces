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
		int n = f.nextInt(), k = f.nextInt();
		char[] on = f.next().toCharArray();
		par = new int[k];
		sz1 = new int[k];
		sz2 = new int[k];
		xor = new int[k];
		req = new int[k];
		int[][] sets = new int[n][2];
		for(int i = 0; i < n; i++)
			sets[i][0] = sets[i][1] = -1;
		for(int i = 0; i < k; i++) {
			par[i] = i;
			sz1[i] = 1;
			int m = f.nextInt();
			while(m-->0) {
				int a = f.nextInt()-1;
				if(sets[a][0] == -1) sets[a][0] = i;
				else sets[a][1] = i;
			}
		}
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(sets[i][0] == -1) {}
			else if(sets[i][1] == -1) {
				int s = find(sets[i][0]);
				if(req[s] == 0) {
					if(on[i] == '0') req[s] = xor[sets[i][0]]+1;
					else req[s] = 2-xor[sets[i][0]];
					ans -= Math.min(sz1[s],sz2[s]);
					if(req[s] == 1) ans += sz1[s];
					else ans += sz2[s];
				}
			} else {
				int s = find(sets[i][0]);
				int t = find(sets[i][1]);
				if(s != t) {
					if(req[s] == 1) ans -= sz1[s];
					else if(req[s] == 2) ans -= sz2[s];
					else ans -= Math.min(sz1[s],sz2[s]);
					if(req[t] == 1) ans -= sz1[t];
					else if(req[t] == 2) ans -= sz2[t];
					else ans -= Math.min(sz1[t],sz2[t]);
					s = union(sets[i][0],sets[i][1], on[i]=='1');
					if(req[s] == 1) ans += sz1[s];
					else if(req[s] == 2) ans += sz2[s];
					else ans += Math.min(sz1[s],sz2[s]);
				}
			}
			out.println(ans);
		}
///
		out.flush();
	}
	int[] par, sz1, sz2, req, xor;
	public int find(int x) {
		if(par[x] == x) return x;
		int np = find(par[x]);
		xor[x] ^= xor[par[x]];
		return par[x] = np;
	}
	public int union(int x, int y, boolean on) {
		int px = find(x), py = find(y);
		if(px == py) return px;
		if(sz1[px]+sz2[px] > sz1[py]+sz2[py]) {
			int t = py;
			py = px;
			px = t;
		}
		if((xor[x] != xor[y]) ^ on) {
			par[px] = py;
			sz1[py] += sz1[px];
			sz2[py] += sz2[px];
			if(req[px] != 0) req[py] = req[px];
		} else {
			par[px] = py;
			sz1[py] += sz2[px];
			sz2[py] += sz1[px];
			xor[px] = 1;
			if(req[px] != 0) req[py] = 3-req[px];
		}
		return py;
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