import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws Exception {
		new A().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
        int asdf = f.nextInt();
        while(asdf-->0) {
            int n = f.nextInt();
            int[] arr = new int[n];
            int _0 = 0, _1 = 0;
            for(int i = 0; i < n; i++) {
                arr[i] = f.nextInt();
                if(arr[i] % 2 == 0) _0++;
                else _1++;
            }
            if(Math.abs(_0 - _1) > 1) out.println(-1);
            else if(n%2 == 0) {
                long aans = 214748364749494L;
                {
                    int ind0 = 0, ind1 = 1;
                    long ans = 0;
                    for(int i = 0; i < n; i++)
                        if(arr[i] % 2 == 0) {
                            ans += Math.abs(ind0-i);
                            ind0 += 2;
                        } else {
                            ans += Math.abs(ind1-i);
                            ind1 += 2;
                        }
                    aans = Math.min(aans, ans);
                }
                {
                    int ind0 = 1, ind1 = 0;
                    long ans = 0;
                    for(int i = 0; i < n; i++)
                        if(arr[i] % 2 == 0) {
                            ans += Math.abs(ind0-i);
                            ind0 += 2;
                        } else {
                            ans += Math.abs(ind1-i);
                            ind1 += 2;
                        }
                    aans = Math.min(aans, ans);
                }
                out.println(aans/2);
            } else {
                int ind0 = _0 > _1 ? 0 : 1, ind1 = 1 - ind0;
                long ans = 0;
                for(int i = 0; i < n; i++)
                    if(arr[i] % 2 == 0) {
                        ans += Math.abs(ind0-i);
                        ind0 += 2;
                    } else {
                        ans += Math.abs(ind1-i);
                        ind1 += 2;
                    }
                out.println(ans/2);
            }
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