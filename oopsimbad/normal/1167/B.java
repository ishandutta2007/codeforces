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
		int[] a = {4, 8, 15, 16, 23, 42};
		TreeMap<Integer, TreeSet<Integer>> tm = new TreeMap<>();
		for(int i = 0; i < a.length; i++)
			for(int j = i+1; j < a.length; j++) {
				TreeSet<Integer> hs = new TreeSet<>();
				hs.add(a[i]); hs.add(a[j]);
				tm.put(a[i]*a[j], hs);
			}
		out.println("? 1 2");
		out.println("? 2 3");
		out.println("? 4 5");
		out.println("? 5 6");
		out.flush();
		int[] ans = new int[6];
		{
			TreeSet<Integer> s1 = tm.get(f.nextInt());
			TreeSet<Integer> s2 = tm.get(f.nextInt());
			for(int i : s1)
				if(s2.contains(i)) ans[1] = i;
			s1.remove(ans[1]); s2.remove(ans[1]);
			ans[0] = s1.first();
			ans[2] = s2.first();
		}
		{
			TreeSet<Integer> s1 = tm.get(f.nextInt());
			TreeSet<Integer> s2 = tm.get(f.nextInt());
			for(int i : s1)
				if(s2.contains(i)) ans[4] = i;
			s1.remove(ans[4]); s2.remove(ans[4]);
			ans[3] = s1.first();
			ans[5] = s2.first();
		}
		out.print("!");
		for(int i : ans)
			out.print(" " + i);
		out.println();
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