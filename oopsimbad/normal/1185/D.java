import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class D {
	public static void main(String[] args) throws Exception {
		new D().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
        PrintWriter out = new PrintWriter(System.out);
        int n = f.nextInt();
        ArrayList<Integer> al = new ArrayList<>();
        HashMap<Integer,Integer> orig = new HashMap<>();
        for(int i = 0; i < n; i++) {
            int a = f.nextInt();
            al.add(a);
            orig.put(a,i+1);
        }
        Collections.sort(al);
        int ans = -1;
        if(ans == -1) {
            int diff = al.get(1)-al.get(0), tans = -1;
            boolean works = true;
            for(int i = 2; i < n; i++) {
                if(al.get(i)-al.get(i-1) == diff) continue;
                if(tans != -1) works = false;
                else if(i == n-1) tans = i;
                else if(al.get(i+1) - al.get(i-1) == diff) tans = i++;
                else works = false;
            }
            if(works) ans = tans == -1 ? 0 : tans;

        }
        if(ans == -1) {
            boolean works = true;
            int diff = al.get(2)-al.get(0);
            for(int i = 3; i < n; i++) {
                works &= al.get(i)-al.get(i-1) == diff;
            }
            if(works) ans = 1;
        }
        if(ans == -1) {
            boolean works = true;
            int diff = al.get(2)-al.get(1);
            for(int i = 3; i < n; i++) {
                works &= al.get(i)-al.get(i-1) == diff;
            }
            if(works) ans = 0;
        }
        if(ans == -1) out.println(-1);
        else out.println(orig.get(al.get(ans)));
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