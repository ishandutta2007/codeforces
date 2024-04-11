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
			int[] cntt = new int[n];
			int[] cnt1 = new int[n];
			for(int i = 0; i < n; i++) {
				int a= f.nextInt()-1;
				cntt[a]++;
				cnt1[a]++;
			}
			Pair[] arr = new Pair[n];
			for(int i = 0; i < n; i++) arr[i] = new Pair(cntt[i], cnt1[i]);
			Arrays.sort(arr, new Comparator<Pair>() {
				public int compare(Pair a, Pair b) {
					return -Integer.compare(a.a, b.a);
				}
			});
			PriorityQueue<Pair> pq = new PriorityQueue<>(new Comparator<Pair>() {
				public int compare(Pair a, Pair b) {
					return -Integer.compare(a.b, b.b);
				}
			});
			int totalt = 0, total1 = 0, prev = 2147483647;
			int j = 0;
			while(true) {
				if(pq.isEmpty()) {
					if(j == n) break;
					prev = arr[j].a;
				}
				while(j < n && arr[j].a >= prev) pq.add(arr[j++]);
				Pair p = pq.poll();
				totalt += prev = Math.max(0, Math.min(prev, p.a));
				total1 += Math.min(p.b, prev);
				prev--;
			}
			out.println(totalt);
		}
///
		out.flush();
	}
	class Pair {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
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