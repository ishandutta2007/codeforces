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
		///
		hm = new HashMap<>();
		int n = f.nextInt();
		ArrayList<Integer> al = new ArrayList<>();
		int[] to = new int[n];
		for(int i = 0; i < n; i++)
			al.add(i);
		Collections.shuffle(al);
		for(int i = 0; i < n; i++)
			to[al.get(i)] = i;
		int pa = (1 << 11) - 1, pb = (1 << 11) - 1;
		int ai = -1, bi = -1;
		int ab = -1;
		for(int i = 0; pa != 0 && pb != 0 && i < n; i++) {
			if(ai == -1) ai = i;
			else if(bi == -1) {
				bi = i;
				ab = query(to[ai], to[bi]);
				if((ab ^ (pa & ab)) != 0) {
					bi = -1;
					ab = -1;
				} else pb = ab;
				pa &= ab;
			} else {
				int ci = i;
				int ac = query(to[ai], to[ci]);
				if((pa & ac) != pa)	{
					pa &= ac;
					if(ac == pa) {
						bi = ci;
						pb = ac;
						ab = ac;
					} else {
						bi = -1;
						pb = (1 << 11) - 1;
						ab = -1;
					}
				} else {
					int bc = query(to[bi], to[ci]);
					if((pb & bc) != pb) {
						pb &= bc;
						if(bc == pb) {
							ai = ci;
							pb = bc;
							ab = bc;
						} else {
							ai = bi;
							pb = pa;
							ab = -1;
							bi = -1;
							pb = (1 << 11) - 1;
						}
					}
				}
			}
		}
		int zi = ai;
		if(pa == 0) zi = ai;
		else if(pb == 0) zi = bi;
		else zi = Math.max(ai, bi);
		int[] ans = new int[n];
		for(int i = 0; i < n; i++)
			if(i != to[zi]) ans[i] = query(i, to[zi]);
		out.print("!");
		for(int i : ans) out.print(" "+i);
		out.println();
///
		out.flush();
	}
	HashMap<String,Integer> hm;
	FastScanner f;
	PrintWriter out;
	public int query(int i, int j) {
		if(i > j) {
			i ^= j; j^= i; i ^= j;
		}
		String s = String.format("? %d %d", i+1, j+1);
		if(!hm.containsKey(s)) {
			out.println(s);
			out.flush();
			hm.put(s, f.nextInt());
		}
		return hm.get(s);
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