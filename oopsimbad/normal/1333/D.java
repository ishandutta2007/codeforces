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
		int n = f.nextInt(), k = f.nextInt();
		char[] arr = f.next().toCharArray();
		int inv = countInv(arr);
		if(inv < k) out.println(-1);
		else {
			LinkedList<Integer> poss = new LinkedList<Integer>();
			for(int j = 0; j < n-1; j++) 
				if(arr[j] == 'R' && arr[j+1] == 'L') {
					poss.add(-1);
					poss.add(j);
				}
			LinkedList<Integer>[] mv = new LinkedList[k];
			for(int asdf = 0; asdf < k; asdf++) {
				mv[asdf] = new LinkedList<>();
				while(inv > (k-asdf-1) && !poss.isEmpty() && poss.peek() < asdf) {
					poss.poll(); int i = poss.poll();
					arr[i] = 'L';
					arr[i+1] = 'R';
					inv--;
					if(i > 0 && arr[i-1] == 'R') {
						poss.add(asdf);
						poss.add(i-1);
					}
					if(i < n-2 && arr[i+2] == 'L') {
						poss.add(asdf);
						poss.add(i+1);
					}
					mv[asdf].add(i+1);
				}
			}
			if(inv != 0)
				out.println(-1);
			else for(LinkedList<Integer> l : mv) {
				out.print(l.size());
				for(int i : l) out.print(" " + i);
				out.println();
			}
		}
///
		out.flush(); 
	}
	public int countInv(char[] arr) {
		int c = 0;
		int ans = 0;
		for(int i = 0; i < arr.length; i++)
			if(arr[i] == 'R') c++;
			else ans += c;
		return ans;
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