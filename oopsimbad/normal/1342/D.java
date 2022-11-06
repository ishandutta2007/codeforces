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
		int n = f.nextInt(), k = f.nextInt();
		TreeSet<Pair> ts = new TreeSet<>();
		for(int i = 0; i < n; i++)
			ts.add(new Pair(f.nextInt()-1,i));
		int[] max = new int[n+1];
		Arrays.fill(max, -1);
		int prev = n;
		for(int i = 0; i < k; i++) {
			int a = f.nextInt()-1;
			while(prev != a) max[prev-1] = max[prev--];
			max[a] = i;
		}
		while(prev != 0) max[prev-1] = max[prev--];
		Pair[] p = new Pair[n+1];
		for(int i = 0; i <= n; i++) p[i] = new Pair(max[i],n);
		LinkedList<LinkedList<Integer>> ans = new LinkedList<>();
		while(!ts.isEmpty()) {
			LinkedList<Integer> ll = new LinkedList<>();
			Pair a = null;
			while((a = ts.floor(p[ll.size()])) != null) {
				ll.add(a.a);
				ts.remove(a);
			}
			ans.add(ll);
		}
		out.println(ans.size());
		for(LinkedList<Integer> ll : ans) {
			out.print(ll.size());
			for(int i : ll) out.print(" " + (i+1));
			out.println();
		}
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			if(a == p.a) return b - p.b;
			return a - p.a;
		}
		public String toString() {
			return a + " "+ b;
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