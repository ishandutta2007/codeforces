import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	int min;
	int[] arr;
	LinkedList<Integer> p;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		p = new LinkedList<Integer>();
		arr = new int[n+1];
		for(int i = 2; i <= n; i++) {
			if(arr[i] == 0) {
				p.add(i);
				for(int j = 2*i; j <= n; j+=i)
					arr[j] = i;
			}
		}
		visited = new boolean[n+1][3];
		min = 2147483647;
		recur(n,2);
		System.out.println(min);
		out.flush();
	}
	boolean[][] visited;
	public void recur(int n, int t) {
		if(visited[n][t]) return;
		visited[n][t] = true;
		if(t == 2) {
			for(int pr : p) {
				if(n % pr == 0) {
	 				for(int i = 0; i < pr; i++) {
						if(n-i < pr)
							break;
						recur(n-i,t-1);
					}
				}
			}
		} else {
			min = Math.min(min, Math.max(n-arr[n]+1, arr[n]));
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