import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class F {
	public static void main(String[] args) throws Exception {
		new F().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		int k = (int) Math.sqrt(n);
		int[] arr = new int[n];
		int[] ans = new int[k];
		while(true) {
			int j = 0;
			for(int i = 0; i < n; i++) {
				if(arr[i] == 1) continue;
				int sum = 0;
				int st = (i-k+1+n)%n;
				for(int a = 0; a < k; a++)
					sum += arr[(st+a)%n];
				int e = (st+k)%n;
				boolean ok = sum < k-1;
				while(ok) {
					if(st == i) break;
					sum += arr[e];
					sum -= arr[st];
					ok &= sum < k-1;
					st = (st+1)%n;
					e = (e+1)%n;
				}
				if(ok) {
					arr[i] = 1;
					ans[j++] = i;
					if(j == k) break;
				}
			}
			if(j != k) {
				out.println(0);
				break;
			}
			out.print(j);
			for(int i : ans) out.print(" " + (i+1));
			out.println();
			out.flush();
			j = f.nextInt()-1;
			if(j == -2) break; 
			for(int i = 0; i < k; i++) arr[(j+i)%n] = 0;
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