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
		int asdf = f.nextInt();
		int[][][] dp = new int[1 << 15][15][15];
		int[][][] prev1 = new int[1 << 15][15][15];
		int[][][] prev2 = new int[1 << 15][15][15];
		int[][] npos = new int[1 << 15][15];
		for(int i = 0; i < 1 << 15; i++) {
			npos[i][14] = -1;
			for(int a = 14; a >= 0; a--)
				if((i & (1 << a)) != 0)
					npos[i][a] = a;
				else if(a != 14) npos[i][a] = npos[i][a+1]; 
		}
		while(asdf-->0) {
			int[] sum = new int[1 << 15];
			int n = f.nextInt();
			int[] arr = new int[n];
			for(int i = 0; i < n; i++)
				arr[i] = f.nextInt();
			LinkedList<Integer> ll = new LinkedList<>();
			for(int i = 1; i < 1 << n; i++) {
				for(int j = 0; j < n; j++)
					for(int k = 0; k < n; k++)
						dp[i][j][k] = 2147483647;
				int pos = -1;
				for(int b = 0; b < n; b++)
					if((i&1<<b) != 0) {
						sum[i] += arr[b];
						if(pos == -1) pos = b;
					}
				dp[i][0][pos] = sum[i];
				prev1[i][0][pos] = i;
				ll.add(i);
				ll.add(0);
				ll.add(pos);
			}
			int bj = 0, bk = 0;
			while(!ll.isEmpty()) {
				int i = ll.pollFirst();
				int j = ll.pollFirst();
				int k = ll.pollFirst();
				int v = dp[i][j][k];
				int m = ((1 << n)-1)^i;
				int ni = m;
				while(ni != 0) {
					if(sum[ni] > v && npos[ni][k] != -1) {
						if(dp[i|ni][j+1][npos[ni][k]] == 2147483647) {
							ll.add(i|ni);
							ll.add(j+1);
							ll.add(npos[ni][k]);
						}
						if(dp[i|ni][j+1][npos[ni][k]] > sum[ni]) {
							dp[i|ni][j+1][npos[ni][k]] = sum[ni];
							prev1[i|ni][j+1][npos[ni][k]] = ni;
							prev2[i|ni][j+1][npos[ni][k]] = k;
						}
					}
					ni = (ni-1)&m;
				}
				if(m == 0) {
					bj = j;
					bk = k;
				}
			}
			int bi = (1 << n) - 1;
			out.println(n-bj-1);
			int[] pos = new int[n];
			for(int i = 0; i < n; i++)
				pos[i] = i+1;
			while(bi != 0) {
				int ni = prev1[bi][bj][bk];
				int nk = prev2[bi][bj][bk];
				for(int i = 0; i < 15; i++)
					if((1 << i & ni) != 0 && i != bk) {
						out.println(pos[i]+ " " + pos[bk]);
						for(int j = i; j < n; j++)
							pos[j]--;
					}
				bi ^= ni;
				bj--;
				bk = nk;
			}
		}
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