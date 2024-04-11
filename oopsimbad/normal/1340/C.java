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
		int[] arr = new int[m];
		for(int i = 0; i < m; i++)
			arr[i] = f.nextInt();
		Arrays.sort(arr);
		int g = f.nextInt(), r = f.nextInt();
		int[][] min = new int[m][g];
		boolean[][] vis = new boolean[m][g];
		for(int i = 0; i < m; i++)
			Arrays.fill(min[i], 2147483647);
		min[0][0] = 0;
		LinkedList<Integer> q = new LinkedList<>();
		q.add(0); q.add(0);
		while(!q.isEmpty()) {
			int i = q.pollFirst(), j = q.pollFirst();
			if(vis[i][j]) continue;
			vis[i][j] = true;
			if(i != 0) {
				int d = j+arr[i]-arr[i-1];
				if(d > g) {}
				else if(d == g) {
					if(min[i-1][0] > min[i][j]+1) {
						min[i-1][0] = min[i][j]+1;
						q.add(i-1);
						q.add(0);
					}
				} else {
					if(min[i-1][d] > min[i][j]) {
						min[i-1][d] = min[i][j];
						q.addFirst(d);
						q.addFirst(i-1);
					}
				}
			}
			if(i != m-1) {
				int d = j+arr[i+1]-arr[i];
				if(d > g) {}
				else if(d == g) {
					if(min[i+1][0] > min[i][j]+1) {
						min[i+1][0] = min[i][j]+1;
						q.add(i+1);
						q.add(0);
					}
				} else {
					if(min[i+1][d] > min[i][j]) {
						min[i+1][d] = min[i][j];
						q.addFirst(d);
						q.addFirst(i+1);
					}
				}
			}
		}
		int ans = 2147483647;
		for(int i = 0; i < m; i++) {
			for(int j = 0; j <= g-arr[m-1]+arr[i] && j < g; j++) {
				if(min[i][j] != 2147483647)
					ans = Math.min(ans, (r+g)*min[i][j]+arr[m-1]-arr[i]+j);
			}
		}
		if(ans == 2147483647) out.println(-1);
		else out.println(ans);
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