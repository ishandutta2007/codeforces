import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	Set<Integer>[] adj;
	boolean[] visited;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		adj = new Set[n];
		LinkedHashSet<Integer> unv = new LinkedHashSet<Integer>();
		for(int i = 0; i < n; i++) {
			adj[i] = new LinkedHashSet<Integer>();
			unv.add(i);
		}
		int m = f.nextInt();
		while(m-->0) {
			int a = f.nextInt()-1;
			int b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		ArrayList<Integer> al = new ArrayList<Integer>(n);
		
		for(int i = 0; i < n; i++) {
			if(unv.contains(i)) {
				Queue<Integer> q = new LinkedList<Integer>();
				q.add(i);
				int s = 0;
				while(!q.isEmpty()) {
					int a = q.poll();
					unv.remove(a);
					s++;
					LinkedHashSet<Integer> nunv = new LinkedHashSet<Integer>();
					for(int j : adj[a]) {
						if(unv.contains(j))  {
							nunv.add(j);
							unv.remove(j);
						}
					}
					for(int j : unv)
						q.add(j);
					unv = nunv;
				}
				al.add(s);
			}
		}
		Collections.sort(al);
		out.println(al.size());
		for(int i : al) out.print(i + " ");
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