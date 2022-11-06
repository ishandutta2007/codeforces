import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	FastScanner f;
	PrintWriter out;
	int qcnt;
	public void run() throws Exception {
		f = new FastScanner();
		out = new PrintWriter(System.out);
		ArrayList<Integer> primes = new ArrayList<>();
		for(int i = 2; i <= 100; i++)
			if(isPrime(i)) primes.add(i);
		int cnt = 0;
		for(int i = 0; i < primes.size() && qcnt < 20; i++) {
			if(qcnt < 20 && query(primes.get(i))) cnt++;
			if(qcnt < 20 && primes.get(i)*primes.get(i) < 100 && query(primes.get(i)*primes.get(i))) cnt++;
		}
		if(cnt <= 1) out.println("prime");
		else out.println("composite");
		out.flush();
	}
	public boolean query(int i) {
		qcnt++;
		out.println(i);
		out.flush();
		String s = f.next();
		return s.equals("yes");
	}
	public boolean isPrime(int i) {
		for(int j = 2; j < i; j++) if(i%j == 0) return false;
		return true;
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