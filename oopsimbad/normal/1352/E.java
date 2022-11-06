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
		int asdf = f.nextInt()+1;
		int[] ex = new int[8001];
		while(asdf-->1) {
			int n= f.nextInt();
			int[] arr = new int[n];
			for(int i = 0; i < arr.length; i++)
				arr[i] = f.nextInt();
			for(int i = 0; i < arr.length; i++) {
				int s = arr[i];
				for(int j = i+1; j < arr.length; j++) {
					s += arr[j];
					if(s > 8000) break;
					else ex[s] = asdf;
				}
			}
			int ans = 0;
			for(int i : arr)
				if(ex[i] == asdf) ans++;
			out.println(ans);
		}
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