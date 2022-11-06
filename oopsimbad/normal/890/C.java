import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int[] arr = new int[n+1];//input
		arr[0] = -1;
		int[] parr = new int[n+1];//prev index of a room
		int[] rarr = new int[n+1];//corresponding room
		int size = 1;
		for(int i = 1; i <= n; i++) {
			int a = arr[i] = f.nextInt();
			int room = rarr[a];
			if(parr[room] == a) {
				parr[room] = i;
				rarr[i] = room;
			} else {
				rarr[i] = size;
				parr[size++] = i;
			}
		}
		out.println(size);
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

    }
}