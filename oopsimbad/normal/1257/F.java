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
		int[] arr1 = new int[n];
		int[] arr2 = new int[n];
		for(int i = 0; i < n; i++) {
			int a = f.nextInt();
			arr1[i] = a & ((1 << 15) - 1);
			arr2[i] = a >> 15;
		}
		HashMap<Integer,Integer>[] trie = new HashMap[n << 15];
		int[] x = new int[n << 15];
		int xi = 1;
		trie[0] = new HashMap<>();
		for(int i = 0; i < 1 << 15; i++) {
			int[] res = new int[n-1];
			int start = Integer.bitCount(arr1[0] ^ i);
			for(int j = 0; j < n-1; j++) res[j] = Integer.bitCount(arr1[j+1] ^ i) - start;
			int cur = 0;
			for(int j = 0; j < n-1; j++) {
				if(!trie[cur].containsKey(res[j])) {
					trie[cur].put(res[j], xi);
					x[xi] = i;
					trie[xi] = new HashMap<>();
					xi++;
				}
				cur = trie[cur].get(res[j]);
			}
		}
		boolean print = false;
		for(int i = 0; i < 1 << 15; i++) {
			int[] res = new int[n-1];
			int start = Integer.bitCount(arr2[0] ^ i);
			for(int j = 0; j < n-1; j++) res[j] = start - Integer.bitCount(arr2[j+1] ^ i);
			int cur = 0;
			for(int j = 0; j < n-1; j++) {
				if(!trie[cur].containsKey(res[j])) {
					cur = -1;
					break;
				}
				cur = trie[cur].get(res[j]);
			}
			if(cur != -1) {
				print  = true;
				out.println((i << 15) + x[cur]);
				break;
			}
		}
		if(!print) out.println(-1);

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