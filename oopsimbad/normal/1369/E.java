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
        int n = f.nextInt(), m = f.nextInt();
        int[] cnt = new int[n];
        ArrayList<Integer>[] friends = new ArrayList[n];
        for(int i = 0; i < n; i++) {
            friends[i] = new ArrayList<>();
            cnt[i] = f.nextInt();
        }
        boolean[] used = new boolean[m];
        int[][] vals = new int[m][2];
        for(int i = 0; i < m; i++) {
            int a = f.nextInt(), b = f.nextInt();
            a--; b--;
            friends[a].add(i); friends[b].add(i);
            cnt[a]--; cnt[b]--;
            vals[i][0] = a; vals[i][1] = b;
        }
        LinkedList<Integer> ll = new LinkedList<>();
        Stack<Integer> ans = new Stack<>();
        for(int i = 0; i < n; i++)
            if(cnt[i] >= 0) ll.addAll(friends[i]);
        while(!ll.isEmpty()) {
            int i = ll.poll();
            if(used[i]) continue;
            ans.add(i);
            used[i] = true;
            if(++cnt[vals[i][0]] == 0)
                ll.addAll(friends[vals[i][0]]);
            if(++cnt[vals[i][1]] == 0)
                ll.addAll(friends[vals[i][1]]);
        }
        if(ans.size() == m) {
            out.println("ALIVE");
            while(!ans.isEmpty()) out.print(ans.pop()+1+" ");
        } else out.println("DEAD");
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