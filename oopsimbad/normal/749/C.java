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
		char[] c = f.next().toCharArray();
		LinkedList<Integer> d = new LinkedList<Integer>(), r = new LinkedList<Integer>();
		for(int i = 0; i < n; i++) if(c[i] == 'D') d.add(i); else r.add(i);
		while(!d.isEmpty() && !r.isEmpty()) {
			LinkedList<Integer> nd = new LinkedList<Integer>(), nr = new LinkedList<Integer>();
			while(!d.isEmpty() && !r.isEmpty()) {
				if(d.peek() < r.peek()) {
					nd.add(d.poll());
					r.poll();
				} else {
					d.poll();
					nr.add(r.poll());
				}
			}
			while(!d.isEmpty()) {
				nd.add(d.poll());
				nr.poll();
			}while(!r.isEmpty()) {
				nr.add(r.poll());
				nd.poll();
			}
			d = nd;
			r = nr;
		}
		if(d.isEmpty()) out.println("R");
		else out.println("D");
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