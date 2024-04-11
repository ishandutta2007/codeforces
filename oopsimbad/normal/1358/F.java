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
		long[] a = new long[n];
		long[] b = new long[n];
		for(int i = 0; i < n; i++) a[i] = f.nextLong();
		for(int i = 0; i < n; i++) b[i] = f.nextLong();
		if(n == 1) {
			if(a[0] == b[0]) out.println("SMALL\n0");
			else out.println("IMPOSSIBLE");
			out.flush();
			return;
		}
		char[] ans = new char[500000];
		boolean print = true;
		boolean ok = true;
		long i = 0;
		long rcnt = 0;
		boolean rev = false;
		while(true) {
			boolean same = true;
			for(int j = 0; same && j < n; j++)
				same = b[rev ? n-j-1 : j] == a[j];
			if(same) break;
			same = true;
			for(int j = 0; same && j < n; j++)
				same = b[rev ? j : n-j-1] == a[j];
			if(same) {
				if(print) ans[(int)i] = 'R';
				i++;
				rcnt++;
				if(i == ans.length) print = false;
				break;
			}
			if(b[0] < a[0] && b[n-1] < a[0]) {
				ok = false;
				break;
			}
			if(b[rev ? n-1 : 0] > b[rev ? n-2 : 1]) {
				rev ^= true;
				if(print) ans[(int)i] = 'R';
				i++;
				rcnt++;
				if(i == ans.length) print = false;
			}
			if(n == 2) {
				if(b[0] <= 0 || b[1] <= 0) {
					ok = false;
					break;
				}
				if(rev) {
					long steps = b[0]/b[1];
					if(b[1] == a[0] && b[0] - a[1] > 0 && b[0]%b[1] == a[1]%b[1])
						steps = (b[0] - a[1])/b[1];
					if(b[1] == a[1] && b[0] - a[0] > 0 && b[0]%b[1] == a[0]%b[1])
						steps = (b[0] - a[0])/b[1];
					b[0] -= b[1]*steps;
					while(print && steps-->0) {
						ans[(int)i++] = 'P';
						if(i == ans.length) print = false;
					}
					if(!print) i += steps;
				} else {
					long steps = b[1]/b[0];
					if(b[0] == a[0] && b[1] - a[1] > 0 && b[1]%b[0] == a[1]%b[0])
						steps = (b[1] - a[1])/b[0];
					if(b[0] == a[1] && b[1] - a[0] > 0 && b[1]%b[0] == a[0]%b[0])
						steps = (b[1] - a[0])/b[0];
					b[1] -= b[0]*steps;
					while(print && steps-->0) {
						ans[(int)i++] = 'P';
						if(i == ans.length) print = false;
					}
					if(!print) i += steps;
				}
			} else {
				long sum = b[rev ? n-1 : 0];
				for(int j = 1; ok && j < n; j++) {
					ok &= (b[rev ? n-j-1 : j] -= sum) > 0;
					sum += b[rev ? n-j-1 : j];
				}
				if(!ok) break;
				if(print) ans[(int)i] = 'P';
				i++;
				if(i == ans.length) print = false;
			}
		}
		if(!ok) out.println("IMPOSSIBLE");
		else if(i-rcnt <= 200000) {
			out.println("SMALL");
			out.println(i);
			for(int j = (int) i-1; j >= 0; j--)
				out.print(ans[j]);
			out.println();
		} else {
			out.println("BIG");
			out.println(i-rcnt);
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