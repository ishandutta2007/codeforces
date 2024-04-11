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
		int n = f.nextInt(), k = f.nextInt();
		int[] arr = new int[n], perc = new int[n+1];
		for(int i = 0; i < n; i++) {
			arr[i] = f.nextInt();
			perc[i+1] = (int) Math.round((i+1.0)/n * 100);
		}
		int[] curS = new int[k], curT = new int[k];
		Arrays.fill(curS, -1);
		int a = 0;
		int asdf = 0;
		int time = 0;
		boolean[] is = new boolean[n];
		while(true) {
			//System.out.println("Time " + time);
			boolean allNeg = true;
			for(int i = 0; i < k; i++) {
				if(curS[i] == -1 || curT[i]++ == arr[curS[i]]) {
					if(curS[i] != -1) asdf++;
					if(a == n) {
						curS[i] = -1;
						curT[i] = 0;
					} else {
						curS[i] = a++;
						curT[i] = 1;
					}
				}
				allNeg &= curS[i] == -1;
				//System.out.println("Facility " + i + ": " + curS[i] + " " + curT[i]);
			}
			//System.out.println(perc[asdf]);
			for(int i = 0; i < k; i++)
				if(curS[i] != -1) is[curS[i]] |= perc[asdf] == curT[i];
			if(allNeg) break;
			time++;
		}
		int total = 0;
		for(boolean b : is)
			if(b) total++;
		out.println(total);
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