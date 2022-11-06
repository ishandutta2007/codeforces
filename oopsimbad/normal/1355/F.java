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
		boolean[] np = new boolean[100001];
		ArrayList<Integer> al = new ArrayList<>();
		for(int i = 2; i <= 100000; i++) {
			if(np[i]) continue;
			for(int j = 2*i; j <= 100000; j+=i)
				np[j] = true;
			al.add(i);
		}
		int asdf = f.nextInt();
		while(asdf-->0) {
			int max = 1000000000;
			int ans = 1;
			int p = 0;
			int qcnt = 22;
			while(p < al.size() && max >= al.get(p) && qcnt > 0) {
				long query = 1;
				int i = p;
				while(p < al.size() && query*al.get(p) <= 1000000000000000000L && query*al.get(p) > 0)
					query *= al.get(p++);
				qcnt--;
				out.println("? " + query);
				out.flush();
				long res = f.nextLong();
				for(; i < p; i++) {
					int pr = al.get(i);
					if(res % pr == 0) {
						query = 1;
						while(query*pr <= 1000000000000000000L && query*pr > 0) query *= pr;
						int mul = 0;
						if(qcnt != 0) {
							qcnt--;
							out.println("? " + query);
							out.flush();
							long res2 = f.nextLong();
							while(res2 % pr == 0) {
								res2 /= pr;
								max /= pr;
								mul++;
							}
						} else mul = 1;
						ans *= mul+1;
					}
				}
			}
			out.println("! " + Math.max(ans*2, 8));
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