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
		Integer[] arr = new Integer[n];
		for(int i = 0; i <n; i++)
			arr[i] = f.nextInt();
		int l = 0, h = 1_000_000_001;
		Arrays.sort(arr);
		while(l < h) {
			int m = (l+h)/2;
			boolean[] thing = new boolean[n];
			int cur = arr[0];
			boolean works = true;
			for(int i = 1; i < n; i++) {
				if(arr[i] - cur > m) {
					if(arr[i-1] == cur) works = false;
					else {
						cur = arr[i-1];
						thing[i-1] = true;
						i--;
					}
				}
			}
			works = works && cur + m >= arr[n-1];
			cur = arr[n-1];
			for(int i = n-2; i >= 0; i--) {
				if(thing[i]) continue;
				works = works && cur <= arr[i] + m;
				cur = arr[i];
			}
			if(works) h = m;
			else l = m+1;
		}
		boolean[] thing = new boolean[n];
		thing[0] = true;
		int cur = arr[0];
		boolean works = true;
		out.print(cur + " ");
		for(int i = 1; i < n; i++) {
			if(arr[i] - cur > l) {
				if(arr[i-1] == cur) works = false;
				else {
					cur = arr[i-1];
					out.print(cur + " ");
					thing[i-1] = true;
				}
			}
		}
		works = works && cur + l >= arr[n-1];
		cur = arr[n-1];
		out.print(cur + " ");
		for(int i = n-2; i >= 0; i--) {
			if(thing[i]) continue;
			works = works && cur <= arr[i] + l;
			cur = arr[i];
			out.print(cur + " ");
		}
		out.println();
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