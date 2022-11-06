import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		Point[] p = new Point[3];
		for(int i = 0; i < 3; i++) p[i] = new Point(f.nextInt(),f.nextInt());
		TreeSet<Point> ts = new TreeSet<Point>();
		ts.add(p[0].next(p[1], p[2]));
		ts.add(p[1].next(p[2], p[0]));
		ts.add(p[2].next(p[0], p[1]));
		ts.add(p[0].next(p[2], p[1]));
		ts.add(p[2].next(p[1], p[0]));
		ts.add(p[1].next(p[0], p[2]));
		out.println(ts.size());
		for(Point pp : ts )out.println(pp.x  +" " + pp.y);
		out.flush();
	}
	class Point implements Comparable<Point> {
		int x, y;
		public Point(int x, int y) {
			this.x = x;
			this.y = y;
		}
		public int compareTo(Point p) {
			if(p.x != x) return x - p.x;
			return y - p.y;
		}
		public Point next(Point p, Point o) {
			int dx = p.x - x;
			int dy = p.y - y;
			return new Point(o.x + dx, o.y + dy);
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