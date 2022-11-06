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
			long k = f.nextLong();
			ArrayList<Integer> pos = new ArrayList<>();
			char[] c = f.next().toCharArray();
			for(int i = 0; i < n; i++) if(c[i] == '0') pos.add(i);
			for(int i = 0; i < pos.size(); i++) {
				int dist = pos.get(i)-i;
				if(k >= dist) {
					k -= dist;
					pos.set(i, i);
				} else {
					pos.set(i, (int) (pos.get(i)-k));
					break;
				}
			}
			Arrays.fill(c, '1');
			for(int i : pos) c[i] = '0';
			out.println(c);
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