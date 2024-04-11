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
		int n = f.nextInt();
		ArrayList<Pair> al = new ArrayList<>();
		for(int i = 0; i < n; i++) al.add(new Pair(i, f.nextInt()));
		int[] arr = new int[n];
		int[] par = new int[n];
		Collections.sort(al);
		for(int i = 0; i < n; i++)
			arr[i] = al.get(i).b;
		long[] ans = new long[n];
		long best = -arr[0];
		int p = -1;
		ans[0] = ans[1] = Long.MAX_VALUE;
		for(int i = 2; i < n; i++) {
			ans[i] = best + arr[i];
			par[i] = p;
			if(ans[i-2] - arr[i-1] < best) {
				best = ans[i-2] - arr[i-1];
				p = i-2;
			}
		}
		int cur = par[n-1];
		int cnt = 1;
		int[] label = new int[n];
		for(int i = n-1; i >= 0; i--) {
			if(cur == i) {
				cnt++;
				cur = par[i];
			}
			label[al.get(i).a] = cnt;
		}
		out.println(ans[n-1] + " " + cnt);
		for(int i : label) out.print(i + " ");
///
		out.flush(); 
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			return Integer.compare(b,p.b);
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