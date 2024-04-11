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
		int asdf = f.nextInt();
		while(asdf-->0) {
			char[] c = f.next().toCharArray();
			int[] cnt = new int[26];
			for(char cc : c)
				cnt[cc-'a']++;
			int n = f.nextInt();
			int[] a = new int[n];
			for(int i = 0; i < n; i++)
				a[i] = f.nextInt();
			char[] ans = new char[n];
			ArrayList<Integer> al = new ArrayList<>();
			int b = 25;
			while(true) {
				al.clear();
				for(int i = 0; i < n; i++)
					if(ans[i] == 0 && a[i] == 0)
						al.add(i);
				if(al.isEmpty()) break;
				while(cnt[b] < al.size()) b--;
				for(int i : al) {
					ans[i] = (char) ('a'+b);
					for(int j = 0; j < n; j++)
						a[j] -= Math.abs(i-j);
				}
					
				b--;
			}
			out.println(ans);
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