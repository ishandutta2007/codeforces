import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws Exception {
		new C().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		ArrayList<Integer> al = new ArrayList<>();
		al.add(4); al.add(8); al.add(15); al.add(16); al.add(23); al.add(42);
		int[] cnt = new int[6];
		int rm = 0;
		for(int i = 0; i < n; i++) {
			int a = f.nextInt();
			int ind = al.indexOf(a);
			if(ind == -1) {
				rm++;
				continue;
			}
			if(ind != 0 && cnt[ind-1] <= cnt[ind]) {
				rm++;
				continue;
			}
			cnt[ind]++;
		}
		int min = cnt[5];
		for(int i = 0; i < 6; i++)
			rm += cnt[i] - min;
		out.println(rm);
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