import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws Exception {
		new B().run();
	}
	boolean[][] b1, b2;
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int b1r = f.nextInt(), b1c = f.nextInt();
		b1 = new boolean[b1r][b1c];
		int c1 = 0;
		for(int i = 0; i < b1r; i++) {
			char[] c = f.reader.readLine().toCharArray();
			for(int j = 0; j < b1c; j++) c1 += (b1[i][j] = c[j] == '1') ? 1 : 0;
		}
		b2 = new boolean[f.nextInt()][f.nextInt()];
		int c2 = 0;
		for(int i = 0; i < b2.length; i++) {
			char[] c = f.reader.readLine().toCharArray();
			for(int j = 0; j < b2[0].length; j++) c2 += (b2[i][j] = c[j] == '1') ? 1 : 0;
		}
		b1r = Math.max(b1r, b2.length);
		b1c = Math.max(b1c, b2[0].length);
		int max = 0;
		int bx = 0, by = 0;
		outt: for(int x = -b1r+1; x < b1r; x++) {
			for(int y = -b1c+1; y < b1c; y++) {
				int sum = 0;
				for(int i = 0; i < b1.length; i++) {
					for(int j = 0; j < b1[0].length; j++) {
						if(check(i,j,x,y)) {
							sum++;
						}
					}
				}
				if(sum > max) {
					max = sum;
					bx = x;
					by = y;
				}
				if(sum == Math.min(c1, c2)) break outt;
			}
		}
		out.printf("%d %d%n", bx,by);
		out.flush();
	}
	public boolean check(int i, int j, int x, int y) {
		return i+x >= 0 && i+x < b2.length && j+y >= 0 && j+y < b2[0].length && b1[i][j] && b2[i+x][j+y];
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

    }
}