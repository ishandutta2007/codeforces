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
        int asdf = f.nextInt();
        char[] tar = "abacaba".toCharArray();
        while(asdf-->0) {
            int n = f.nextInt();
            String s = f.next().replace("?",".");
            boolean found = false;
            for(int i = 0; i < s.length()-6; i++)
                if((s.substring(0,i)+"abacaba"+s.substring(i+7)).matches(s) && count((s.substring(0,i)+"abacaba"+s.substring(i+7)).replace(".","d")) == 1) {
                    out.println("YES");
                    out.println((s.substring(0, i)+"abacaba"+s.substring(i+7)).replace(".","d"));
                    found = true;
                    break;
                }
            if(!found) out.println("NO");
        }
///
		out.flush();
	}
    public int count(String s) {
        int a = 0;
        for(int i = 0; i < s.length()-6; i++)
            if(s.substring(i, i+7).equals("abacaba")) a++;
        return a;
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