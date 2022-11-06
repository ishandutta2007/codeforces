import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class E {
	public static void main(String[] args) throws Exception {
		new E().run();
	}
	final long MOD = 1000_000_007;
	long[] primedivisor, fact, pow2;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		
		//calc powers of 2
		pow2 = new long[1000010];
		pow2[0] = 1;
		for(int i = 1; i < pow2.length; i++) pow2[i] = pow2[i-1] * 2 % MOD;
		
		//calc a div
		primedivisor = new long[1000010];
		primedivisor[1] = 1;
		for(int i = 2; i*i <= primedivisor.length; i++) {
			if(primedivisor[i] != 0) continue;
			for(int j = 2*i; j < primedivisor.length; j+=i) {
				if(primedivisor[j] == 0) primedivisor[j] = i;
			}
		}
		for(int i = 0; i < primedivisor.length; i++) if(primedivisor[i] == 0) primedivisor[i] = i;
		//calc facts
		fact = new long[2000010];
		fact[0] = 1;
		for(int i = 1; i < fact.length; i++) fact[i] = fact[i-1]*i % MOD;
		int times = f.nextInt();
		
		while(times-->0) {
			int x = f.nextInt(), y = f.nextInt();
			if(x == 1) {
				out.println(pow2[y-1]);
				continue;
			}
			LinkedList<Integer> exps = new LinkedList<Integer>();
			long lastpdiv = primedivisor[x];
			int cnt = 0;
			while(true) {
				long pd = primedivisor[x];
				if(pd != lastpdiv) {
					exps.add(cnt);
					lastpdiv = pd;
					cnt = 1;
				} else cnt++;
				x /= pd;
				if(pd == 1) break;
			}
			long combo = pow2[y-1];
			for(int e : exps) 
				combo = combo * starsnbars(e,y) % MOD;
			out.println(combo % MOD);
		}
		out.flush();
	}
	public long starsnbars(int i, int y) {
		long val = moddiv(moddiv(fact[y+i-1],fact[i]),fact[y-1]);
		return val;
	}
	public long moddiv(long a, long b) {
		a %= MOD;
		idkwhatthisgcdmethoddoes(b, MOD);
		return (x % MOD + MOD) % MOD * a % MOD;
	}
	long x, y;
	public void idkwhatthisgcdmethoddoes(long a, long b) {
		if(a == 0) {
			x = 0;
			y = 1;
			return;
		}
		idkwhatthisgcdmethoddoes(b%a, a);
		long temp = x;
		x = y - b/a * x;
		y = temp;
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