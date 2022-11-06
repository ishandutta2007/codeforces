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
		int or = 0, and = (1 << 10)-1, xor = 0;
		
		for(int i = 0; i < n; i++) {
			String key = f.next();
			int v = f.nextInt();
			if(key.equals("|")) {
				or |= v;
				and |= v;
				xor &= ~v;
			} else if(key.equals("&")) {
				and &= v;
				or &= v;
				xor &= v;
			} else {
				xor ^= v;
			}
		}
		out.println(3);
		out.println("| " + or);
		out.println("& " + and);
		out.println("^ " + xor);
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