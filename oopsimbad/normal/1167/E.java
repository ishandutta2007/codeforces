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
		int n = f.nextInt(), m = f.nextInt();
		int[] arr = new int[n];
		for(int i = 0; i < n; i++)
			arr[i] = f.nextInt()-1;
		int[] s = new int[m], e = new int[m];
		for(int i = 0; i < m; i++) {
			s[i] = n;
			e[i] = -1;
		}
		boolean[] found = new boolean[m];
		for(int i = 0; i < n; i++) {
			if(s[arr[i]] == n) s[arr[i]] = i;
			e[arr[i]] = i;
			found[arr[i]] = true;
		}
		int[] pe = new int[m], sb = new int[m];
		pe[0] = e[0];
		for(int i = 1; i < m; i++) {
			if(!found[i]) pe[i] = pe[i-1];
			else if(pe[i-1] == n) pe[i] = n;
			else if(pe[i-1] > s[i]) pe[i] = n;
			else pe[i] = e[i];
		}
		sb[m-1] = s[m-1];
		for(int i = m-2; i >= 0; i--) {
			if(!found[i]) sb[i] = sb[i+1];
			else if(sb[i+1] == -1) sb[i] = -1;
			else if(sb[i+1] < e[i]) sb[i] = -1;
			else sb[i] = s[i];
		}
		int r = 0;
		long cnt = 1;
		for(int i = 0; i < m; i++) {
			if(pe[i] == n) break;
			r = Math.max(r, i+2);
			while(r < m && sb[r] <= pe[i]) r++;
			cnt += Math.max(m-r,0);
			//System.out.println(i + ":" + (m-r));
		}
		//System.out.println(Arrays.toString(pe));
		//System.out.println(Arrays.toString(sb));
		for(int i = 0; i < m-1; i++) {
			if(pe[i] != n) cnt++;
			if(sb[m-i-1] != -1) cnt++;
		}
		//System.out.println(Arrays.toString(pe));
		//System.out.println(Arrays.toString(sb));
		out.println(cnt);
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