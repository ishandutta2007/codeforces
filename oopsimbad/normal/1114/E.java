import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public static final int MOD = 1_000_000_007;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int l = 0, h = 1_000_000_001;
		int cnt = 0;
		while(l < h) {
			int m = (l+h)/2;
			out.print("> ");
			out.println(m);
			cnt++;
			out.flush();
			if(f.nextInt() == 1) l = m+1;
			else h = m;
		}
		Random r = new Random(2346832573827523L);
		HashSet<Integer> hs = new HashSet<>();
		ArrayList<Integer> al = new ArrayList<Integer>();
		for(; cnt < 60 && hs.size() < n; cnt++) {
			int a = r.nextInt(n);
			while(hs.contains(a)) a = r.nextInt(n);
			hs.add(a);
			out.print("? ");
			out.println(a+1);
			out.flush();
			al.add(f.nextInt());
		}
		int totalgcd = Math.abs(al.get(0) - al.get(1));
		for(int i = 0; i < al.size(); i++)
			for(int j = i+1; j < al.size(); j++)
				totalgcd = gcd(totalgcd, Math.abs(al.get(i)-al.get(j)));
		out.print("! ");
		out.print(l - totalgcd * (n-1));
		out.print(" ");
		out.println(totalgcd);
		out.flush();
	}
	public int gcd(int a, int b) {
		if(a * b == 0) return a + b;
		return gcd(b%a, a);
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