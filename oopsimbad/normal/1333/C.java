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
		long ans = n*(n+1L)/2;
		HashMap<Long,Integer> hm = new HashMap<Long,Integer>();
		long p = 0;
		hm.put(p, 0);
		int recent = -1;
		for(int i = 0; i < n; i++) {
			p += f.nextInt();
			if(hm.containsKey(p)) {
				ans -= Math.max(0,1L*(hm.get(p)-recent)*(n-i));
				recent = Math.max(recent, hm.get(p));
			}
			hm.put(p, i+1);
		}
		out.println(ans);
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