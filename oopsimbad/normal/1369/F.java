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
        ///
        int n = f.nextInt();
        boolean win = false, lose = true;
        for(int i = 0; i < n; i++) {
            long a = f.nextLong(), b = f.nextLong();
            boolean nwin = lose && canWin(a,b) || win && canWin(a+1, b) && canWin(2*a, b);
            boolean nlose = lose && canLose(a,b) || win && canLose(a+1, b) && canLose(2*a, b);
            win = nwin;
            lose = nlose;
        }
        out.print(win ? 1 : 0);
        out.print(" ");
        out.print(lose ? 1 : 0);
///
		out.flush();
	}
    public boolean canWin(long a, long b) {
        if(a > b) return true;
        if(a == b) return false;
        if(2*a > b) return a%2 != b%2;
        if(b%2 == 1) return can1(a, b/2);
        else return can0(a, b/2);
    }
    public boolean canLose(long a, long b) {
        if(a > b) return false;
        if(a == b) return true;
        if(2*a > b) return true;
        return canWin(a, b/2);
    }
    public boolean can0(long a, long b) {
        if(2*a > b) return true;
        return canWin(a, b/2);
    }
    public boolean can1(long a, long b) {
        return a%2 == 0;
    }
///
	static class FastScanner {
		public BufferedReader reader;
		public StringTokenizer tokenizer;
		public FastScanner() {
			reader = new BufferedReader(new InputStreamReader(System.in), 32768);
			tokenizer = null;
		}
		public String next() { while (tokenizer == null || !tokenizer.hasMoreTokens()) {
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