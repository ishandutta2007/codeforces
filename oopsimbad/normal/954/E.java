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
		int n = f.nextInt(), t = f.nextInt();
		long[] arr1 = new long[n];
		long[] arr2 = new long[n];
		for(int i = 0; i < n; i++)
			arr1[i] = f.nextInt();
		long less = 0, more = 0;
		double cursum = 0;
		TreeSet<Pair> ls = new TreeSet<Pair>(), ms = new TreeSet<Pair>();
		for(int i = 0; i < n; i++) {
			arr2[i] = f.nextInt()-t;
			if(arr2[i] < 0) {
				less += arr1[i]*-arr2[i];
				ls.add(new Pair(arr1[i],-arr2[i],i));
			}
			else if(arr2[i] > 0) {
				more += arr1[i]*arr2[i];
				ms.add(new Pair(arr1[i],arr2[i],i));
			}
			else cursum += arr1[i];
		}
		long tar = Math.min(less, more);
		less = more = tar;
		for(Pair p : ls) {
			if(p.a * p.b <= less) {
				cursum += p.a;
				less -= p.a*p.b;
			} else {
				cursum += (double) less/p.b;
				break;
			}
		}
		for(Pair p : ms) {
			if(p.a * p.b <= more) {
				cursum += p.a;
				more -= p.a*p.b;
			} else {
				cursum += (double) more/p.b;
				break;
			}
		}
		out.println(cursum);
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		long a, b;
		int i;
		public Pair(long a, long b, int i) {
			this.a = a;
			this.b = b;
			this.i = i;
		}
		public int compareTo(Pair p) {
			if(b != p.b) return Long.compare(b, p.b);
			if(a != p.a) return Long.compare(a, p.a);
			return Integer.compare(i, p.i);
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