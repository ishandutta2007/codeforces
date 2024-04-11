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
		int[][] mat = new int[n][n];
		int[] cnts = new int[1001];
		for(int i = 0; i < n*n; i++) cnts[f.nextInt()]++;
		if(n % 2 == 0) {
			boolean works = true;
			for(int i : cnts) works = works && i % 4 == 0;
			if(!works) out.println("NO");
			else {
				int pos = 0;
				int m = n/2;
				for(int i = 0; i <= 1000; i++)
					for(int j = 0; j < cnts[i]; j+= 4) {
						mat[pos/m][pos%m] = mat[n-1-pos/m][pos%m] = mat[pos/m][n-1-pos%m] = mat[n-1-pos/m][n-1-pos%m] = i;
						pos++;
					}
				out.println("YES");
				for(int[] i : mat) {
					for(int j : i) out.print(j + " ");
					out.println();
				}
			}
		} else {
			boolean works = true;
			LinkedList<Integer> _1 = new LinkedList<>();
			LinkedList<Integer> _2 = new LinkedList<>();
			LinkedList<Integer> _4 = new LinkedList<>();
			for(int i = 0; i <= 1000; i++) {
				if(cnts[i] == 0) continue;
				if(cnts[i] % 2 == 1) _1.add(i);
				else if(cnts[i] % 4 == 0) _4.add(i);
				else _2.add(i);
			}
			if(_1.size() != 1) out.println("NO");
			else {
				int _1val = _1.get(0);
				mat[n/2][n/2] = _1val;
				if(--cnts[_1val] != 0) {
					if(cnts[_1val] % 4 == 0) _4.add(_1val);
					else _2.add(_1val);
				}
				if(_2.size() > (n-1)*2 || _2.size() % 2 != (n-1) % 2) out.println("NO");
				else {
					for(int i = 0; i < (n-1)/2; i++) {
						if(_2.size() == 0) {
							int val = _4.pollFirst();
							_2.add(val);
							mat[n/2][i] = mat[n/2][n-i-1] = val;
							cnts[val] -= 2;
						} else {
							int val = _2.pollFirst();
							if(cnts[val] != 2)
								_4.add(val);
							cnts[val] -= 2;
							mat[n/2][i] = mat[n/2][n-i-1] = val;
						}
					}
					for(int i = 0; i < (n-1)/2; i++) {
						if(_2.size() == 0) {
							int val = _4.pollFirst();
							_2.add(val);
							mat[i][n/2] = mat[n-i-1][n/2] = val;
							cnts[val] -= 2;
						} else {
							int val = _2.pollFirst();
							if(cnts[val] != 2)
								_4.add(val);
							cnts[val] -= 2;
							mat[i][n/2] = mat[n-i-1][n/2] = val;
						}
					}
					if(_2.size() != 0) out.println("NO");
					else {
						int pos = 0;
						int m = n/2;
						for(int i : _4)
							for(int j = 0; j < cnts[i]; j+= 4) {
								mat[pos/m][pos%m] = mat[n-1-pos/m][pos%m] = mat[pos/m][n-1-pos%m] = mat[n-1-pos/m][n-1-pos%m] = i;
								pos++;
							}
						out.println("YES");
						for(int[] i : mat) {
							for(int j : i) out.print(j + " ");
							out.println();
						}
					}
				}
			}
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