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
                int[] x = new int[n], y = new int[n];
                for(int i = 0; i < n; i++) {
                    x[i] = f.nextInt();
                    y[i] = f.nextInt();
                }
                HashMap<List<Integer>, Set<Integer>> hm = new HashMap<>();
                for(int i = 0; i < n; i++)
                    for(int j = i+1; j < n; j++) {
                        int dx = x[i]-x[j];
                        int dy = y[j]-y[i];
                        if(dx < 0) {
                            dx *= -1;
                            dy *= -1;
                        } else if(dx == 0) {
                            dy = 1;  
                        } else if(dy == 0) {
                            dx = 1;
                        }
                        int g = gcd(dx,dy);
                        dx /= g;
                        dy /= g;
                        ArrayList<Integer> al = new ArrayList<>(2);
                        al.add(dx); al.add(dy);
                        if(!hm.containsKey(al)) hm.put(al, new HashSet<>());
                        hm.get(al).add(dx*y[i]+dy*x[i]);
                    }
                long ans = 0, totsz = 0;
                Collection<Set<Integer>> c = hm.values();
                for(Set s : c) totsz += s.size();
                for(Set s : c) ans += (totsz-s.size())*s.size();
                out.println(ans/2);
                out.flush();
	}
        public int gcd(int x, int y) {
            if(x * y == 0) return x+y;
            return gcd(y%x, x);
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