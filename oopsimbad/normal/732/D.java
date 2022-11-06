import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	int[] arr, time;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), m = f.nextInt();
		arr = new int[n];
		time = new int[m];
		for(int i = 0; i < n; i++) arr[i] = f.nextInt();
		for(int i = 0; i < m; i++) time[i] = f.nextInt();
		int l = 0, h = n;
		while(l < h) {
			int mid = (l+h)/2;
			if(simulate(mid)) h = mid;
			else l = mid+1;
		}
		System.out.println(l == n ? -1 : l+1);
 		out.flush();
	}
	public boolean simulate(int mid) {
		boolean[] barr = new boolean[time.length];
		Queue<Integer> q = new LinkedList<Integer>();
		int cur = 0;
		for(int i = mid; i >= 0; i--) {
			if(arr[i] == 0 || barr[arr[i]-1]) {
				if(!q.isEmpty()) {
					cur--;
					if(cur == 0) {
						q.poll();
						if(!q.isEmpty()) cur = time[q.peek()];
					}
				}
			} else {
				barr[arr[i]-1] = true;
				if(q.isEmpty()) cur = time[arr[i]-1];
				q.add(arr[i]-1);
			}
		}
		for(boolean b : barr) if(!b) return false;
		return q.isEmpty();
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

    }
}