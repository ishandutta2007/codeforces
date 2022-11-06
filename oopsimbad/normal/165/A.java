import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws Exception {
		new A().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int times = f.nextInt();
		Point[] arr =  new Point[times];
		for(int i =0 ; i < times; i++) 
			arr[i] = new Point(f.nextInt(), f.nextInt());
		long count = 0;
		for(int i = 0; i < times; i++) {
			boolean[] barr = new boolean[5];
			for(int j = 0; j < times; j++) barr[arr[i].check(arr[j])] = true;
			if(barr[1] && barr[2] && barr[3] && barr[4]) count++;
			}
		out.println(count);
		out.flush();
	}
	class Point {
		int x, y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		public int check(Point p) {
			if(x == p.x && y < p.y) return 1;
			if(y == p.y && x > p.x) return 2;
			if(x == p.x && y > p.y) return 3;
			if(y == p.y && x < p.x) return 4;
			return 0;
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

    }
}