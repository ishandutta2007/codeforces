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
		long val = f.nextLong();
		boolean found = false;
		for(int n = 2; n <= 2000 && !found; n++)
			for(int k = 1; k < n && !found; k++) {
				int a = n-k;
				int b = n;
				for(long x = Math.max(a, (val+a-1)/a * a); !found && x <= k * 1000000L; x += a) {
					if((x - val) % b == 0 && (x - val) / b > 0 && (x - val) / b <= (n-k) * 1000000) {
						//out.printf("x:%d y:%d posL:%d negL:%d%n", x, (x-val)/b, k, n-k);
						out.println(n);
						long y = (x-val)/b;
						for(int i = n-k-1; i >= 0; i--) {
							out.print(-Math.max(y - i * 1000000, 0));
							y -= Math.max(y - i * 1000000, 0);
							out.print(" ");
						}
						for(int i = k-1; i >= 0; i--) {
							out.print(Math.max(x - i * 1000000, 0));
							x -= Math.max(x - i * 1000000, 0);
							out.print(" ");
						}
						found = true;
					} 
				} 
			}
		
		if(!found) out.println(-1);
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
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }
    }
}