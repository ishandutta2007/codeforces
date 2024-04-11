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
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = f.nextInt();
		int diff = -1;
		int prevdiff = 212;
		for(int i = 0; i < n-1; i++) {
			int curdiff = Math.abs(arr[i]-arr[i+1]);
			if(curdiff != 1) {
				if(diff != -1) {
					if(curdiff != diff)	{
						System.out.println("NO");
						return;
					}
				} else diff = curdiff;
			}
		}
		if(diff == -1) {
			System.out.println("YES");
			System.out.println("1000000000 1000000000");
		} else if(diff == 0) {
			System.out.println("NO");
		} else {
			for(int i = 0; i < n-1; i++)
				if(Math.abs(arr[i]-arr[i+1]) == 1 && (arr[i]-1)/diff != (arr[i+1]-1)/diff) {
					System.out.println("NO");
					return;
				}
			System.out.println("YES");
			System.out.println("1000000000 " + diff);
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