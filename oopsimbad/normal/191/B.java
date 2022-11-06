import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static final long MOD = 998_244_353;
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), k = f.nextInt();
		long total = f.nextLong();
		long[] arr = new long[n];
		long[] sort = new long[n];
		HashMap<Long, Integer> hm = new HashMap<Long,Integer>();
		for(int i = 0; i < n; i++) {
			arr[i] = f.nextLong();
			sort[i] = arr[i];
		}
		hm.put(arr[n-1], 0);
		sort[n-1] = 0;
		Arrays.sort(sort);
		for(int i = 0; i < n; i++)
			hm.put(sort[i],i);
		int min = n-1;
		int sum = 0;
		for(int i = 0; i < k-1; i++)
			sum += sort[n-i-1];
		//System.out.println(sum);
		for(int i = 0; i < n; i++) {
			if(hm.get(arr[i]) > n-k) {
				//System.out.println(sum + sort[n-k]);
				if(sum + sort[n-k] > total) {
					min = i;
					break;
				}
			} else if(sum + arr[i] > total) {
				//System.out.println(sum+arr[i]);
				min = i;
				break;
			} else {
				//System.out.println(sum+arr[i]);
			}
		}
		out.println(min+1);
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