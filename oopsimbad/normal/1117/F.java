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
		int p = f.nextInt();
		int[] charcnt = new int[p];
		boolean[][] allowed = new boolean[p][p];
		char[] c = f.next().toCharArray();
		int[] valid = new int[1 << p];
		Arrays.fill(valid, -1);
		for(int i = 0; i < p; i++) 
			for(int j = 0; j < p; j++) {
				if(!(allowed[i][j] = f.nextInt() == 1)) {
					char ii = (char) ('a' + i);
					char jj = (char) ('a' + j);
					int curmask = 0;
					boolean first = true;
					char prev = '0';
					for(int k = 0; k < n; k++) {
						if(c[k] == ii || c[k] == jj) {
							if(!first && (c[k] != prev || i == j)) {
								valid[curmask] = 1 << i | 1 << j;
							}
							first = false;
							curmask = 0;
							prev = c[k];
						}
						else curmask |= 1 << (c[k] - 'a');
					}
				}
				for(int a = 0; a < (1 << p); a++) 
					if(valid[a] == (1 << i | 1 << j)) {
						for(int b = 1; b < 1 << p; b <<= 1)
							if((valid[a] & b) == 0 && (a & b) == 0) {
								valid[a ^ b] = valid[a];
							}
					}
			}
		for(char cc : c)
			charcnt[cc-'a']++;
		boolean[] reachable = new boolean[1 << p];
		reachable[0] = true;
		int best = n;
		for(int i = 0; i < (1 << p); i++) {
			if(reachable[i] && valid[i] == -1) {
				int cnt = c.length;
				for(int b = 1, a = 0; b < 1 << p; b <<= 1, a++) {
					if((i & b) == 0) {
						reachable[i ^ b] = true;
					} else cnt -= charcnt[a];
				}
				best = Math.min(best, cnt);
			}
		}
		System.out.println(best);
		out.flush();
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