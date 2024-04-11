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
		ArrayList<Integer>[] a = new ArrayList[]{new ArrayList<Integer>(),new ArrayList<Integer>(), new ArrayList<Integer>()};
		for(int i = 0; i < 3; i++) {
			char[] c = f.next().toCharArray();
			if(c[1] == 's') a[0].add(c[0]-'0');
			if(c[1] == 'm') a[1].add(c[0]-'0');
			if(c[1] == 'p') a[2].add(c[0]-'0');
		}
		int min = 2;
		for(ArrayList<Integer> al : a) {
			Collections.sort(al);
			if(al.size() == 3 && al.get(0) == al.get(1) && al.get(1) == al.get(2)) min = 0;
			if(al.size() == 3 && al.get(0) == al.get(1)-1 && al.get(1) == al.get(2)-1) min = 0;
			for(int i = 1; i < al.size(); i++)
				if(al.get(i) - al.get(i-1) <= 2) min = Math.min(min, 1);
		}
		out.println(min);
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