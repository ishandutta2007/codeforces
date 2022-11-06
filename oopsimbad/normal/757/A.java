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
		String s = f.next();
		HashMap<Character,Long> tm = new HashMap<>();
		for(char c : "Bulbasaur".toCharArray()) tm.put(c, 0L);
		for(char c : s.toCharArray()) {
			if(!"Bulbasaur".contains(""+c)) continue;
			else if(!tm.containsKey(c)) {
				tm.put(c, 1L);
			} else tm.put(c,tm.get(c)+1);
		}
		long cnt = min(tm.get('B'),tm.get('u')/2,tm.get('l'),tm.get('b'),tm.get('s'),tm.get('a')/2,tm.get('u'),tm.get('r'));
		out.print(cnt);
		out.flush();
	}
	
	long min(long... args) {
		long min = args[0];
		for(long i : args) {
			if(i < min) min = i;
		}
		return min;
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