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
        int asdf = f.nextInt();
        while(asdf-->0) {
            int n = f.nextInt(), m = f.nextInt();
            int[] id = new int[n];
            int[] ind = new int[n];
            ArrayList<Integer>[] nx = new ArrayList[n];
            for(int i = 0; i < n; i++) nx[i] = new ArrayList<>();
            ArrayList<Integer> dumb = new ArrayList<>();
            for(int i = 0; i < m; i++) {
                int t = f.nextInt(), a = f.nextInt()-1, b = f.nextInt()-1;
                if(t == 0) {
                    dumb.add(a); dumb.add(b);
                } else {
                    nx[a].add(b);
                    ind[b]++;
                }
            }
            LinkedList<Integer> q = new LinkedList<>();
            for(int i = 0; i < n; i++) if(ind[i] == 0) q.add(i);
            int cnt = 0;
            while(!q.isEmpty()) {
                int i = q.poll();
                id[i] = cnt++;
                for(int j : nx[i])
                    if(--ind[j] == 0) q.add(j);
            }
            if(cnt != n) out.println("NO");
            else {
                out.println("YES");
                for(int i = 0; i < n; i++)
                    for(int j : nx[i]) out.println(i+1 + " " + (j+1));
                for(int i = 0; i < dumb.size(); i+= 2) {
                    int a = dumb.get(i), b = dumb.get(i+1);
                    if(id[a] < id[b]) out.println(a+1 + " " + (b+1));
                    else out.println(b+1 + " " + (a+1));
                }
            }
        }
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