import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class E {
	public static void main(String[] args) throws Exception {
		new E().run();
	}
	int[] BIT;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt(), k = f.nextInt();
		int[] arr = new int[k];
		int[] to = new int[n+1];
		BIT = new int[k+5];
		remove(k);
		Arrays.fill(to,-1);
		boolean[] used = new boolean[k];
		int[] aux = new int[k];
		for(int i = 0; i < k; i++)
			to[(aux[i] = arr[i] = f.nextInt())] = i;
		Arrays.sort(aux);
		int curind = -1;
		LinkedList<Integer> ll = new LinkedList<Integer>();
		for(int i = 0; i < k; i++) {
			int v = aux[i];
			if(i != 0) {
				for(int j = v-1; j > aux[i-1]; j--) {
					if(to[j] != -1) {
						System.out.println(-1);
						return;
					}
					ll.add(j);
					curind = k;
				}
			} else {
				for(int j = v-1; j > 0; j--) {
					if(to[j] != -1) {
						System.out.println(-1);
						return;
					}
					ll.add(j);
					curind = k;
				}
			}
			//check if poss
			int ind = to[v];
			if(curind > ind && query(curind) - query(ind) < curind-ind) {
				System.out.println(-1);
				return;
			}
			used[ind] = true;
			remove(ind);
			curind = ind;
		}
		for(int j = n; j > aux[k-1]; j--) {
			if(to[j] != -1) {
				System.out.println(-1);
				return;
			}
			ll.add(j);
			curind = k;
		}
		for(int i : arr) out.printf("%d ", i);
		for(int i : ll) out.printf("%d ", i);
		out.println();
		out.flush();
	}
	public int query(int i) {
		i++;
		int res = 0;
		while(i > 0) {
			res += BIT[i];
			i -= i & -i;
		}
		return res;
	}
	public void remove(int i) {
		i++;
		while(i < BIT.length) {
			BIT[i]++;
			i += i & -i;
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