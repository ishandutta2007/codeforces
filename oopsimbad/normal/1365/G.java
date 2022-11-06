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
        ///
        int n = f.nextInt();
        int id = 0;
        ArrayList<Integer>[] queries = new ArrayList[13];
        for(int i = 0; i < 13; i++) queries[i] = new ArrayList<>();
        long[] pos = new long[n];
        int[] cnt = new int[64];
        int[] uniq = new int[64];
        for(int i = 0; i < n; i++) {
            while(Integer.bitCount(id) != 6) id++;
            for(int b = 0; b < 13; b++)
                if((id & 1 << b) != 0) queries[b].add(i);
            pos[i] = Long.MAX_VALUE;
            id++;
        }
        for(int i = 0; i < 13; i++) {
            if(queries[i].isEmpty()) continue;
            out.print("? " + queries[i].size());
            for(int j : queries[i]) out.print(" "+(j+1));
            out.println();
            out.flush();
            long l = f.nextLong();
            for(int j : queries[i]) pos[j] &= l;
        }
        Arrays.fill(uniq,-1);
        long tot = 0;
        for(int i = 0; i < n; i++) {
            tot |= pos[i];
            for(int b = 0; b < 64; b++)
                if((1L << b & pos[i]) != 0) {
                    if(uniq[b] == -1) uniq[b] = i;
                    cnt[b]++;
                }
        }
        long[] ans = new long[n];
        Arrays.fill(ans, tot);
        for(int i = 0; i < 64; i++)
            if(cnt[i] == 1)
                ans[uniq[i]] ^= 1L << i;
        out.print("!");
        for(long l : ans) out.print(" " +l);
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