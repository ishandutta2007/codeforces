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
		HashMap<Integer,Integer> hm = new HashMap<>();
                for(int i = 0; i < 19; i++)
                    hm.put(1 << i, i);
                int n = f.nextInt();
                ArrayList<Integer> al = new ArrayList<>();
                for(int i = 0; i < n; i++)
                    al.add(f.nextInt());
                Collections.sort(al);
                LinkedList<Integer> ll = new LinkedList<>();
                ll.add(0);
                int szworks = 0, cursz = 0;
                boolean[] used = new boolean[1 << 19];
                used[0] = true;
                ArrayList<Integer> xors = new ArrayList<>();
                for(int a : al) {
                    if(used[ll.peekLast() ^ a]) continue;
                    while(1 << cursz <= a) cursz++;
                    xors.add(a);
                    int lim = ll.size();
                    for(int i = lim; i > 0; i--) {
                        int nv = xors.get(hm.get(i & -i)) ^ ll.peekLast();
                        used[nv] = true;
                        ll.add(nv);
                    }
                    if(1 << cursz == ll.size()) szworks = cursz;
                    //out.println(a + " " + (1 << cursz) + " " + ll);
                }
                out.println(szworks);
                int i = 0;
                for(int a : ll) {
                    if(i == 1 << szworks) break;
                    out.print(a + " ");
                    i++;
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