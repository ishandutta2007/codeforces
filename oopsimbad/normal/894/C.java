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
		int m = f.nextInt();
		int[] arr = new int[m];
		for(int i = 0; i < m; i++) {
			arr[i] = f.nextInt();
			if(arr[i] % arr[0] != 0) {
				System.out.println(-1);
				return;
			}
		}
		out.println(m*2);
		for(int i : arr) {
			out.print(arr[0]);
			out.print(" ");
			out.print(i);
			out.print(" ");
		}
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int x, y;
		public Pair(int a, int b) {
			x = a;
			y = b;
		}
		public int compareTo(Pair p) {
			return Integer.compare(y, p.y);
		}
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