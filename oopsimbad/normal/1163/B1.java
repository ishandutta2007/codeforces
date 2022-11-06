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
		int[] cnt = new int[100001];
		HashMap<Integer,Integer> hm = new HashMap<>();
		int max = 0;
		HashSet<Integer> exists = new HashSet<>();
		for(int i = 0; i < n; i++) {
			int a = f.nextInt()-1;
			int val = hm.getOrDefault(a, 0)+1;
			if(val != 1) {
				if(--cnt[val-1] == 0) exists.remove(val-1);
			}
			exists.add(val);
			cnt[val]++;
			hm.put(a, val);
			int m = hm.size();
			if(exists.size() == 2) {
				boolean b = true;
				int p = -1;
				for(int c : exists) {
					b &= cnt[c] == 1 || cnt[c] == m-1;
					if(p == -1) p = c;
					else b &= p-c == 1 && cnt[p] == 1 || c-p == 1 && cnt[c] == 1 || c == 1 && cnt[c] == 1 || p == 1 && cnt[p] == 1;
				}
				if(b) max = i+1;
			} else if(exists.size() == 1) {
				boolean b = true;
				for(int c : exists)
					b = cnt[c] == 1;
				if(exists.contains(1) || b) max = i+1;
			}
		}
		out.println(max);
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