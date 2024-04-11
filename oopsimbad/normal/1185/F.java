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
        int n = f.nextInt(), m = f.nextInt();
		int[] cnt = new int[1 << 9];
		for(int i = 0; i < n; i++) {
			int a = f.nextInt();
			int map = 0;
			for(int j = 0; j < a; j++) map |= 1 << f.nextInt()-1;
			cnt[map]++;
		}
		for(int i = (1<<9)-1; i >= 0; i--) {
			for(int j = 0; j < i; j++) 
				if((i & j) == j) cnt[i] += cnt[j];
		}
		int[] minCost = new int[1 << 9];
		int[] cost = new int[1 << 9], cost2 = new int[1 << 9];
		int[] id = new int[1 << 9], id2 = new int[1 << 9];
		int[] a1 = new int[1 << 9], a2 = new int[1 << 9];
		for(int i = 0; i < 1 << 9; i++)
			minCost[i] = cost[i] = cost2[i] = id[i] = id2[i] = a1[i] = a2[i] = -1;
		for(int i = 0; i < m; i++) {
			int c = f.nextInt();
			int a = f.nextInt();
			int map = 0;
			for(int j = 0; j < a; j++) map |= 1 << f.nextInt()-1;
			if(cost[map] == -1 || cost[map] > c) {
				cost2[map] = cost[map];
				id2[map] = id[map];
				cost[map] = c;
				id[map] = i;
			} else if(cost2[map] > c || cost2[map] == -1) {
				cost2[map] = c;
				id2[map] = i;
			} 
		}
		for(int i = 0; i < 1 << 9; i++)
			if(id[i] != -1 && id2[i] != -1) {
				minCost[i] = cost[i] + cost2[i];
				a1[i] = id[i];
				a2[i] = id2[i];
			}
		for(int i = 0; i < 1 << 9; i++)
			if(cost[i] != -1) 
				for(int j = 0; j < 1 << 9; j++)
					if(i != j && cost[j] != -1 && (cost[i] + cost[j] < minCost[i|j] || minCost[i|j] == -1)) {
						int k = i|j;
						a1[k] = id[i];
						a2[k] = id[j];
						minCost[k] = cost[i] + cost[j];
					}
		int best = -1;
		int bestCost = 2147483647;
		int A1 = 0, A2 = 0;
		for(int i = 0; i < 1 << 9; i++)
			if(minCost[i] != -1 && (cnt[i] > best || cnt[i] == best && bestCost > minCost[i])) {
				bestCost = minCost[i];
				best = cnt[i];
				A1 = a1[i];
				A2 = a2[i];
			}
		out.printf("%d %d%n", A1+1, A2+1);
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