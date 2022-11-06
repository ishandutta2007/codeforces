import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws Exception {
		new A().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt();
		int[] t = new int[n];
		ArrayList<Integer>[] adj = new ArrayList[n];
		for(int i = 0; i < n; i++) adj[i] = new ArrayList<>();
		for(int i = 0; i < m; i++) {
			int a= f.nextInt()-1, b = f.nextInt()-1;
			adj[a].add(b);
			adj[b].add(a);
		}
		for(int i = 0; i < n; i++) t[i] = f.nextInt();
		boolean ok = true;
		int[] dumb = new int[n];
		for(int i = 0; i < n; i++) {
			int cnt = 0;
			for(int j : adj[i]) 
				if(t[j] <= t[i] && dumb[t[j]] != i+1) {
					dumb[t[j]] = i+1;
					cnt++;
				}
			ok &= cnt == t[i]-1;
		}
		if(ok) {
			Pair[] arr = new Pair[n];
			for(int i = 0; i < n; i++)
				arr[i] = new Pair(i+1,t[i]);
			Arrays.sort(arr);
			for(Pair p : arr) out.print(p.a + " ");
		} else out.println(-1);
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b= b;
		}
		public int compareTo(Pair p) {
			return Integer.compare(b, p.b);
		}
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