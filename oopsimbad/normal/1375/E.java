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
		int n = f.nextInt();
		int[] arr = new int[n];
		ArrayList<Pair>[] inv = new ArrayList[n];
		ArrayList<Integer> moves = new ArrayList<>();
		for(int i = 0; i < n; i++) {
			inv[i] = new ArrayList<>();
			arr[i] = f.nextInt();
			for(int j = 0; j < i; j++)
				if(arr[i] < arr[j]) inv[j].add(new Pair(arr[i], i));
		}
		for(int i = 0; i < n; i++) {
			if(inv[i].isEmpty()) continue;
			Collections.sort(inv[i]);
			for(int j = inv[i].size()-1; j >= 0; j--) {
				Pair p = inv[i].get(j);
				int t = arr[p.b];
				arr[p.b] = arr[i];
				arr[i] = t;
				moves.add(i); moves.add(p.b);
			}
		}
		boolean ok = true;
		for(int i = 1; i < n; i++) ok &= arr[i] >= arr[i-1];
		if(ok) {
			out.println(moves.size()/2);
			for(int i = 0; i < moves.size(); i+=2)
				out.println((moves.get(i)+1) + " " + (moves.get(i+1)+1));
		} else out.println(-1);
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			return Integer.compare(a, p.a);
		}
	}
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() { reader = new BufferedReader(new InputStreamReader(System.in), 32768);
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