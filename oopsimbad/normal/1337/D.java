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
			int na = f.nextInt(), nb = f.nextInt(), nc = f.nextInt();
			Long[] a = new Long[na];
			Long[] b = new Long[nb];
			Long[] c = new Long[nc];
			for(int i = 0; i < na; i++)
				a[i] = f.nextLong();
			for(int i = 0; i < nb; i++)
				b[i] = f.nextLong();
			for(int i = 0; i < nc; i++)
				c[i] = f.nextLong();
			Arrays.sort(a);
			Arrays.sort(b);
			Arrays.sort(c);
			Long[] t;
			long ans = Long.MAX_VALUE;
			{
				int j = 0, k = 0;
				for(int i = 0; i < a.length; i++) {
					while(j < b.length-1 && b[j+1] <= a[i]) j++;
					while(k < c.length && c[k] < a[i]) k++;
					if(j == b.length || k == c.length) break;
					if(b[j] <= a[i] && a[i] <= c[k])
						ans = Math.min(ans, (a[i]-b[j])*(a[i]-b[j])+(a[i]-c[k])*(a[i]-c[k])+(c[k]-b[j])*(c[k]-b[j]));
				}
			}
			t = a;
			a = b;
			b = t;
			{
				int j = 0, k = 0;
				for(int i = 0; i < a.length; i++) {
					while(j < b.length-1 && b[j+1] <= a[i]) j++;
					while(k < c.length && c[k] < a[i]) k++;
					if(j == b.length || k == c.length) break;
					if(b[j] <= a[i] && a[i] <= c[k])
						ans = Math.min(ans, (a[i]-b[j])*(a[i]-b[j])+(a[i]-c[k])*(a[i]-c[k])+(c[k]-b[j])*(c[k]-b[j]));
				}
			}
			t = b;
			b = c;
			c = t;
			{
				int j = 0, k = 0;
				for(int i = 0; i < a.length; i++) {
					while(j < b.length-1 && b[j+1] <= a[i]) j++;
					while(k < c.length && c[k] < a[i]) k++;
					if(j == b.length || k == c.length) break;
					if(b[j] <= a[i] && a[i] <= c[k])
						ans = Math.min(ans, (a[i]-b[j])*(a[i]-b[j])+(a[i]-c[k])*(a[i]-c[k])+(c[k]-b[j])*(c[k]-b[j]));
				}
			}
			t = c;
			c = a;
			a = t;
			{
				int j = 0, k = 0;
				for(int i = 0; i < a.length; i++) {
					while(j < b.length-1 && b[j+1] <= a[i]) j++;
					while(k < c.length && c[k] < a[i]) k++;
					if(j == b.length || k == c.length) break;
					if(b[j] <= a[i] && a[i] <= c[k])
						ans = Math.min(ans, (a[i]-b[j])*(a[i]-b[j])+(a[i]-c[k])*(a[i]-c[k])+(c[k]-b[j])*(c[k]-b[j]));
				}
			}
			t = b;
			b = a;
			a = t;
			{
				int j = 0, k = 0;
				for(int i = 0; i < a.length; i++) {
					while(j < b.length-1 && b[j+1] <= a[i]) j++;
					while(k < c.length && c[k] < a[i]) k++;
					if(j == b.length || k == c.length) break;
					if(b[j] <= a[i] && a[i] <= c[k])
						ans = Math.min(ans, (a[i]-b[j])*(a[i]-b[j])+(a[i]-c[k])*(a[i]-c[k])+(c[k]-b[j])*(c[k]-b[j]));
				}
			}
			t = c;
			c = b;
			b = t;
			{
				int j = 0, k = 0;
				for(int i = 0; i < a.length; i++) {
					while(j < b.length-1 && b[j+1] <= a[i]) j++;
					while(k < c.length && c[k] < a[i]) k++;
					if(j == b.length || k == c.length) break;
					if(b[j] <= a[i] && a[i] <= c[k])
						ans = Math.min(ans, (a[i]-b[j])*(a[i]-b[j])+(a[i]-c[k])*(a[i]-c[k])+(c[k]-b[j])*(c[k]-b[j]));
				}
			}
			out.println(ans);
		}
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			return -Integer.compare(a, p.a);
		}
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