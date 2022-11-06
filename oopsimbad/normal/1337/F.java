import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	PrintWriter out;
	FastScanner f;
	int a, b, c, d;
	public void run() throws Exception {
		f = new FastScanner();
		out = new PrintWriter(System.out);
		int n = f.nextInt();
		a = f.nextInt();
		b = f.nextInt();
		int[] arr = new int[n];
		Stack<Integer> s = new Stack<>();
		for(int i = n-2; i >= 2; i--) {
			query(i);
			s.add(d);
		}
		query(0);
		int bc1 = d;
		query(1);
		int d2 = d;
		query(0);
		int b1c1 = d;
		if(c == 0) {
			arr[0] = 2+c;
		} else {
			arr[0] = (int) Math.ceil(Math.sqrt(c*2))+1;
		}
		arr[2] = b1c1-bc1;
		arr[1] = b1c1/arr[2];
		arr[0]--;
		arr[1]--;
		arr[3] = (d2-arr[0]*arr[2])/arr[2];
		arr[0]--;
		for(int i = 4; i < n; i++) {
			d = s.pop();
			arr[i] = (d-arr[i-4]*arr[i-3]-arr[i-3]*arr[i-1])/arr[i-1];
			arr[i-2]--;
		}
		arr[n-2]--;
		out.print("!");
		for(int i = 0; i < n; i++)
			out.print(" " + arr[i]);
		out.flush();
	}
	public void query(int i) {
		out.println("+ " + (i+1));
		out.flush();
		int a = f.nextInt();
		int b = f.nextInt();
		c = a-this.a;
		d = b-this.b;
		this.a = a;
		this.b = b;
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			return -Integer.compare(a, p.a);
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