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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt();
			PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
			while(n-->0)
				pq.add(f.nextInt());
			int max = pq.peek();
			boolean _2 = false, _3 = false, _5 = false;
			ArrayList<Integer> al = new ArrayList<>();
			while(!pq.isEmpty()) {
				int a = pq.poll();
				_2 = _2 || a == max/2;
				_3 = _3 || a == max/3;
				_5 = _5 || a == max/5;
				if(al.size() < 3) {
					boolean works = true;
					for(int b : al) works = works && b % a != 0;
					if(works) al.add(a);
				}
			}
			long ans = 0;
			for(int a : al) ans += a;
			if(_2 && _3 && _5 && max % 30 == 0) ans = Math.max(ans, max * 31 / 30);
			out.println(ans);

		}
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