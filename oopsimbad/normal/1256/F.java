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
		int asdf = f.nextInt();
		while(asdf-->0) {
			int n = f.nextInt();
			char[] a = f.next().toCharArray();
			char[] b = f.next().toCharArray();
			int[] cnt1 = new int[26];
			int[] cnt2 = new int[26];
			for(char c : a) cnt1[c-'a']++;
			for(char c : b) cnt2[c-'a']++;
			boolean works = true;
			for(int i = 0; i < 26; i++) {
				if(cnt1[i] != cnt2[i]) {
					works = false;
					break;
				}
			}
			if(!works) {
				out.println("NO");
				continue;
			}
			for(int i = 0; i < 26; i++) {
				if(cnt1[i] >= 2) {
					works = false;
					break;
				}
			}
			if(!works) {
				out.println("YES");
				continue;
			}
			for(int i = 1; i < n; i++) {
				for(int j = i; j > 0; j--) {
					if(a[j-1] > a[j]) {
						works ^= true;
						char temp = a[j];
						a[j] = a[j-1];
						a[j-1] = temp;
					}
				}
			}
			for(int i = 1; i < n; i++) {
				for(int j = i; j > 0; j--) {
					if(b[j-1] > b[j]) {
						works ^= true;
						char temp = b[j];
						b[j] = b[j-1];
						b[j-1] = temp;
					}
				}
			}
			if(works) out.println("YES");
			else out.println("NO");
		}
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