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
        int asdf = f.nextInt();
        while(asdf-->0) {
            int n = f.nextInt();
            int k = f.nextInt();
            Integer[] sz = new Integer[k];
            int[] max = new int[k], min = new int[k];
            Integer[] arr = new Integer[n];
            for(int i = 0; i < n; i++) arr[i] = f.nextInt();
            for(int i = 0; i < k; i++) sz[i] = f.nextInt();
            Arrays.sort(arr);
            Arrays.sort(sz);
            for(int i = 0; i < k; i++)
                min[i] = max[i] = arr[n-i-1];
            int l = 0;
            for(int i = k-1; i >= 0; i--) {
                if(sz[i] <= 1) continue;
                min[i] = arr[l];
                l += sz[i]-1;
            }
            long ans = 0;
            for(int i = 0; i < k; i++) ans += min[i] + max[i];
            out.println(ans);
        }
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