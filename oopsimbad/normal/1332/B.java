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
		ArrayList<Integer> primes = new ArrayList<>();
		boolean[] sieve = new boolean[1005];
		for(int i = 2; i < sieve.length; i++) 
			if(!sieve[i]) {
				primes.add(i);
				for(int j = 2*i; j < sieve.length; j+=i) sieve[j] = true;
			}
		int times = f.nextInt();
		while(times-->0) {
			int n = f.nextInt();
			int[] arr = new int[n];
			TreeSet<Integer> hs = new TreeSet<>();
			int[] color = new int[n];
			for(int i = 0; i < n; i++) {
				arr[i] = f.nextInt();
				for(int j = 0; j < 11; j++)
					if(arr[i] % primes.get(j) == 0) {
						color[i] = j;
						hs.add(j);
						break;
					}
			}	
			int[] map = new int[11];
			int cnt = 1;
			for(int i : hs) map[i] = cnt++;
			out.println(hs.size());
			for(int i : color)
				out.print(map[i] +" ");
				out.println();
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
        public String nextLine() {
        	try {
        		return reader.readLine();
        	} catch(IOException e) {
        		throw new RuntimeException(e);
        	}
        }
    }
}