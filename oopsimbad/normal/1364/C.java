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
        int n = f.nextInt();
        int[] arr = new int[n];
        int[] ans = new int[n];
        Stack<Integer> s = new Stack<>();
        int prev = 0;
        for(int i = 0; i < n; i++) {
            arr[i] = f.nextInt();
            ans[i] = 1000000;
            if(arr[i] != prev) {
                ans[i] = prev;
                while(++prev != arr[i]) 
                    ans[s.pop()] = prev;
            } else s.add(i);
            prev = arr[i];
        }
        for(int i : ans) out.print(i + " ");
        out.println();
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