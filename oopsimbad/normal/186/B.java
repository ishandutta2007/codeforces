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
		int n = f.nextInt(), t1 = f.nextInt(), t2 = f.nextInt();
		double p = 1-f.nextDouble()/100;
		Oops[] oops = new Oops[n];
		for(int i = 0; i < n; i++) oops[i] = new Oops(i+1,t1,t2,f.nextInt(),f.nextInt(),p);
		Arrays.sort(oops);
		for(Oops o : oops) out.println(o);
		out.flush();
	}
	class Oops implements Comparable<Oops> {
		int id;
		double max;
		public Oops(int id, int t1, int t2, int r1, int r2, double p) {
			this.id = id;
			max = Math.max(t1*r1*p + r2*t2, t1*r2*p + r1*t2);
		}
		public int compareTo(Oops o) {
			if(max != o.max) return Double.compare(o.max,max);
			return Integer.compare(id,o.id);
		}
		public String toString() {
			return id + " " + String.format("%.2f", max);
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