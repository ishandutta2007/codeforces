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
		int n = f.nextInt();
		char[] c1 = f.next().toCharArray(), c2 = f.next().toCharArray();
		int[] changes = new int[n-1];
		changes[0] = c2[0] - c1[0];
		for(int i = 1; i < n-1; i++)
			changes[i] = c2[i] - (c1[i] + changes[i-1]);
		//System.out.println(Arrays.toString(changes));
		if(changes[n-2] + c1[n-1] != c2[n-1]) {
			out.println(-1);
			out.flush();
			return;
		}
		long total = 0;
		for(int i : changes)
			total += Math.abs(i);
		out.println(total);
		int i = 0;
		for(int asdf = 0; asdf < total && asdf < 100000; asdf++) {
			if(i == n-1) i = 0;
			if(changes[i] == 0) {
				i++;
				asdf--;
			} else if(changes[i] < 0) {
				if(c1[i+1] == '0') {
					i++;
					asdf--;
				} else {
					out.println(i + 1 + " -1");
					c1[i]--; c1[i+1]--;
					changes[i]++;
				}
			} else {
				if(c1[i+1] == '9') {
					i++;
					asdf--;
				} else {
					out.println(i + 1 + " 1");
					c1[i]++; c1[i+1]++;
					changes[i]--;
				}
			}
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