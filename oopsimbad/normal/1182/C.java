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
		HashMap<Integer,String[]> hm = new HashMap<>();
		String VOWELS = "aeiou";
		LinkedList<String> ll = new LinkedList<>();
		while(n-->0) {
			String s = f.next();
			int v = -1;
			int c = 0;
			for(int i = 0; i < s.length(); i++) {
				int a = VOWELS.indexOf(s.charAt(i));
				if(a != -1) {
					c++;
					v = a;
				}
			}
			if(!hm.containsKey(c)) hm.put(c, new String[5]);
			String[] arr = hm.get(c);
			if(arr[v] == null) arr[v] = s;
			else {
				ll.add(arr[v]);
				ll.add(s);
				arr[v] = null;
			}
		}
		LinkedList<String> l = new LinkedList<>();
		for(int i : hm.keySet()) {
			String[] arr = hm.get(i);
			String p = null;
			for(String s : arr) {
				if(s == null) continue;
				if(p == null) p = s;
				else {
					l.add(p);
					l.add(s);
					p = null;
				}
			}
		}
		while(l.size() < ll.size()) {
			l.add(ll.poll());
			l.add(ll.poll());
		}
		out.println(ll.size()/2);
		while(!ll.isEmpty())
			out.printf("%s %s%n", l.poll(), ll.poll());
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