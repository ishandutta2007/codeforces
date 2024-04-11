import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class E {
	public static void main(String[] args) throws Exception {
		new E().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int t = f.nextInt();
		while(t-->0) {
			int n = f.nextInt(), m = f.nextInt();
			int[] rem = new int[n];
			int[] in = new int[n];
			ArrayList<Integer>[] adj = new ArrayList[n];
			for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
			for(int i = 0; i < m; i++) {
				int a = f.nextInt()-1, b = f.nextInt()-1;
				adj[a].add(b);
				in[b]++;
			}
			LinkedList<Integer> ll = new LinkedList<>();
			for(int i = 0; i < n; i++) {
				if(in[i] == 0) ll.add(i);
				rem[i] = 1;
			}
			ArrayList<Integer> ans = new ArrayList<>();
			while(!ll.isEmpty()) {
				int i = ll.poll();
				if(rem[i] == 3) {
					rem[i] = 0;
					ans.add(i);
				}
				for(int j : adj[i]) {
					if(--in[j] == 0) ll.add(j);
					rem[j] = Math.max(rem[j], rem[i]+1);
				}
			}
			out.println(ans.size());
			for(int i : ans) out.print(i+1 + " ");
			out.println();
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