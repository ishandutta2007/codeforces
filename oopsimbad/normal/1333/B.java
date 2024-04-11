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
		int times = f.nextInt();
		while(times-->0) {
			int n = f.nextInt();
			int[] arr1 = new int[n];
			int[] arr2 = new int[n];
			for(int i = 0; i < n; i++)
				arr1[i] = f.nextInt();
			for(int i = 0; i < n; i++)
				arr2[i] = f.nextInt();
			boolean l = false, g = false;
			boolean b = true;
			for(int i = 0; i < n; i++) {
				if(!(arr1[i] == arr2[i] || arr1[i] < arr2[i] && g || arr1[i] > arr2[i] && l)) b = false;
				l |= arr1[i] == -1;
				g |= arr1[i] == 1;
			}
			out.println(b ? "YES" : "NO");
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