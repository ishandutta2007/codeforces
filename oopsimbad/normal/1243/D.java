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
		HashSet<Integer>[] adj = new HashSet[n];
		LinkedList<Integer> set = new LinkedList<>();
		for(int i = 0; i < n; i++) {
			adj[i] = new HashSet<>();
			set.add(i);
		}
		for(int i = 0; i < m; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		boolean[] skip = new boolean[n];
		LinkedList<Integer> q = new LinkedList<>();
		int cnt = 0;
		for(int i = 0; i < n; i++) {
			if(skip[i]) continue;
			q.add(i);
			ListIterator<Integer> it = set.listIterator();
			it.next(); it.remove();
			while(!q.isEmpty()) {
				it = set.listIterator();
				int a = q.poll();
				while(it.hasNext()) {
					int j = it.next();
					if(adj[a].contains(j)) continue;
					it.remove();
					skip[j] = true;
					q.add(j);
				}
			}
			cnt++;
		}
		out.println(cnt-1);
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