import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	int[] BIT;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int[] arr = new int[n];
		BIT = new int[n+10];
		int inv = 0;
		for(int i = 0; i < n; i++) {
			arr[i] = f.nextInt();
			inv ^= (i-query(arr[i])) & 1;
			add(arr[i]);
		}
		int k = f.nextInt();
		while(k-->0) {
			int diff = -f.nextInt()+f.nextInt()+1;
			inv ^= (diff*(diff-1)/2) & 1;
			out.println(inv == 1 ? "odd" : "even");
		}
		out.flush();
	}

	public int query(int i) {
		i++;
		int res = 0;
		while(i > 0) {
			res += BIT[i];
			i -= i & -i;
		}
		return res;
	}
	public void add(int i) {
		i++;
		while(i < BIT.length) {
			BIT[i]++;
			i += i & -i;
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