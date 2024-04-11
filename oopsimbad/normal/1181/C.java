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
		int r = f.nextInt(), c = f.nextInt();
		char[][] mat = new char[r][c];
		String[][] fl = new String[r][c];
		for(int i = 0; i < r; i++) mat[i] = f.next().toCharArray();
		for(int j = 0; j < c; j++) {
			LinkedList<Character> ch = new LinkedList<>();
			LinkedList<Integer> sz = new LinkedList<>();
			int cursz = 1;
			char cur = mat[0][j];
			for(int i = 1; i < r; i++) {
				if(mat[i][j] != cur) {
					if(ch.size() == 2) {
						int s1 = sz.poll();
						int s2 = sz.peek();
						char c1 = ch.poll();
						char c2 = ch.peek();
						if(s1 >= s2 && s2 <= cursz)
							fl[i-cursz-s2*2][j] = ""+s2+c1+c2+cur;
					}
					ch.add(cur);
					sz.add(cursz);
					cur = mat[i][j];
					cursz = 1;
				} else cursz++;
			}
			if(ch.size() == 2) {
				int s1 = sz.poll();
				int s2 = sz.peek();
				char c1 = ch.poll();
				char c2 = ch.peek();
				if(s1 >= s2 && s2 <= cursz)
					fl[r-cursz-s2*2][j] = ""+s2+c1+c2+cur;
			}
		}
		long ans = 0;
		for(int i = 0; i < r; i++) {
			String cur = null;
			int cnt = 0;
			for(int j = 0; j < c; j++) {
				if(fl[i][j] == null && cur == null || fl[i][j] != null && fl[i][j].equals(cur)) cnt++;
				else {
					if(cur != null) ans += cnt * (cnt+1)/2;
					cur = fl[i][j];
					cnt = 1;
				}
			}
			if(cur != null) ans += cnt * (cnt+1)/2;
		}
		out.println(ans);
///
		out.flush();
	}
///
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