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
		while(asdf-->0) {
			int n = f.nextInt();
			int[][] arrs = new int[n-1][];
			int[] cnt = new int[n];
			for(int i = 0; i < n-1; i++) {
				int m = f.nextInt();
				arrs[i] = new int[m];
				for(int j = 0; j < m; j++)
					cnt[arrs[i][j] = f.nextInt()-1]++;
			}
			boolean[] orig = new boolean[n];
			for(int i = 0; i < n; i++)
				if(cnt[i] == 1) orig[i] = true;
			for(int ignore = 0; ignore < n; ignore++) {
				int start = -1;
				for(int i = 0; i < n; i++)
					if(cnt[i] == 1 && i != ignore) start = i;
				if(start != -1) {
					boolean[] used = new boolean[n-1];
					boolean[] added = new boolean[n];
					int[] seen = new int[n];
					Stack<Integer> s = new Stack<>();
					int i = start;
					while(i != -1 && i != ignore) {
						for(int j = 0; j < n-1; j++)
							if(!used[j]) {
								boolean b = false;
								for(int k : arrs[j])
									if(k == i) b = true;
								if(b) {
									for(int k : arrs[j]) {
										cnt[k]--;
										seen[k]++;
									}
									used[j] = true;
									break;
								}
							}
						s.add(i);
						added[i] = true;
						i = -1;
						for(int j = 0; j < n; j++)
							if(cnt[j] == 1 && !orig[j] && (i == -1 || seen[j] > seen[i] || seen[j] == seen[i] && i == ignore))
								i = j;
					}
					if(s.size() == n-1) {
						out.print(ignore+1 + " ");
						while(!s.isEmpty())
							out.print(s.pop()+1 + " ");
						out.println();
						break;
					} else {
						Arrays.fill(cnt, 0);
						for(int[] a : arrs)
							for(int b : a)
								cnt[b]++;
					}
				}
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