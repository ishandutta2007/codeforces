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
		int k = f.nextInt();
		HashMap<Long,Integer> hm1 = new HashMap<>();
		HashMap<Long,Integer> hm2 = new HashMap<>();
		HashMap<Long,Integer> vis = new HashMap<>();
		long[][] vals = new long[k][];
		long[] sum = new long[k];
		long tot = 0;
		for(int i = 0; i < k; i++) {
			int n = f.nextInt();
			vals[i] = new long[n];
			for(int j = 0; j < n; j++) {
				vals[i][j] = f.nextInt();
				hm1.put(vals[i][j], i);
				hm2.put(vals[i][j], j);
				sum[i] += vals[i][j];
			}
			tot += sum[i];
		}
		if(tot % k != 0) {
			out.println("No");
			out.flush();
			return;
		}
		long tar = tot/k;
		boolean[] exists = new boolean[1 << k];
		ArrayList<Long>[] moves = new ArrayList[1 << k];
		int asdf = 0;
		for(int i = 0; i < k; i++)
			for(int j = 0; j < vals[i].length; j++) {
				long cur = vals[i][j];
				if(vis.containsKey(cur)) continue;
				++asdf;
				while(hm1.containsKey(cur) && !vis.containsKey(cur)) {
					vis.put(cur, asdf);
					cur = tar - sum[hm1.get(cur)] + cur;
				}
				if(!hm1.containsKey(cur)) continue;
				if(vis.get(cur) == asdf) {
					int map = 1 << hm1.get(cur);
					long st = cur;
					cur = tar - sum[hm1.get(cur)] + cur;
					boolean ok = true;
					ArrayList<Long> al = new ArrayList<>();
					al.add((long) hm1.get(st));
					while(cur != st) {
						al.add(cur);
						al.add((long) hm1.get(cur));
						int b = 1 << hm1.get(cur);
						if((map & b) != 0) {
							ok = false;
							break;
						}
						map |= b;
						cur = tar - sum[hm1.get(cur)] + cur;
					}
					al.add(st);
					if(ok) {
						exists[map] = true;
						moves[map] = al;
					}
				}
			}
		boolean[] pos = new boolean[1 << k];
		int[] to = new int[1 << k];
		pos[0] = true;
		for(int i = 1; i < pos.length; i++) {
			to[i] = -1;
			for(int s = i; s != 0; s = (s-1)&i) 
				if(exists[s] && pos[i-s]) {
					pos[i] = true;
					to[i] = s;
					break;
				}
		}
		if(pos[(1 << k) - 1]) {
			long[] actualmoves = new long[2*k];
			out.println("Yes");
			int cur = (1 << k) -1;
			while(cur != 0) {
				int s = to[cur];
				for(int i = 0; i < moves[s].size(); i+=2) {
					int ii = hm1.get(moves[s].get(i+1));
					actualmoves[2*ii] = moves[s].get(i+1);
					actualmoves[2*ii+1] = moves[s].get(i)+1;
				}
				cur ^= s;
			}
			for(int i = 0; i < actualmoves.length; i+= 2)
				out.println(actualmoves[i] + " " +actualmoves[i+1]);
		} else out.println("No");
///
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