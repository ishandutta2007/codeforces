import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		HashMap<String,Integer> hm = new HashMap<>();
		int times = f.nextInt();
		HashSet<String>[] subs = new HashSet[times];
		for(int i = 0; i < times; i++) {
			subs[i] = new HashSet<String>();
			String st = f.next();
			for(int s = 1; s <= 9; s++) {
				for(int j = 0; j <= st.length() - s; j++) {
					subs[i].add(st.substring(j, j+s));
				}
			}
			for(String I : subs[i]) {
				if(!hm.containsKey(I)) hm.put(I,0);
				hm.put(I, hm.get(I) + 1);
			}
		}
		for(int i = 0; i < times; i++) {
			String best = null;
			for(String I : subs[i]) {
				if(hm.get(I) == 1) {
					if(best == null || I.length() < best.length()) best = I;
				}
			}
			out.println(best);
		}
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