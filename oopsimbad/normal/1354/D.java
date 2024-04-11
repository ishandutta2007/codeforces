import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	BufferedReader bf;
	public void run() throws Exception {
		bf = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		int n = nextInt(), q = nextInt();
		BIT = new int[n+1];
		for(int i = 0; i < n; i++)
			add(nextInt(),1);
		while(q-->0) {
			int a = nextInt();
			if(a < 0) add(get(-a),-1);
			else add(a,1);
		}
		int ans = get(1);
		if(ans == n+1) ans = 0;
		out.println(ans);
		out.flush();
	}
	public int nextInt() throws Exception {
		boolean neg = false;
		int val = 0;
		boolean start = false;
		while(true) {
			int c = bf.read();
			if(c == '-') {
				start = true;
				neg = true;
			} else if(Character.isDigit(c)) {
				start = true;
				val = val*10+c-'0';
			} else if(start) break;
		}
		if(neg) val *= -1;
		return val;
	}
	int[] BIT;
	public int get(int v) {
		int i = 0;
		int cur = 0;
		for(int b = 1 << 19; b > 0; b >>= 1)
			if(i+b < BIT.length && cur+BIT[i+b] < v)
				cur += BIT[i += b];
		return i+1;
	}
	public void add(int i, int v) {
		while(i < BIT.length) {
			BIT[i] += v;
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