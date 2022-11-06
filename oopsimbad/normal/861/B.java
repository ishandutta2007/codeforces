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
		int tflat = f.nextInt()-1, num = f.nextInt();
		int tfloor = -1;
		int[] map = new int[101];
		while(num-->0) map[f.nextInt()-1] = f.nextInt();
		for(int inc = 1; inc <= 100; inc++) {
			boolean b = true;
			for(int i = 0; b && i < map.length; i++) {
				if(map[i] == 0) continue;
				b = map[i] == 1+i/inc;
			}
			if(!b) continue;
			if(tfloor == -1 || tfloor == 1+tflat/inc) tfloor = 1+tflat/inc;
			else {
				out.println(-1);
				out.flush();
				return;
			}
			
		}
		out.println(tfloor);
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