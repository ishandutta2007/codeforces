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
            int[] dp = new int[n];
            int[] arr = new int[n];
            int[] nx = new int[n];
            int[] val = new int[n];
            boolean[] end = new boolean[n];
            boolean[] st = new boolean[n];
            Pair[] p = new Pair[n];
            HashMap<Integer,Integer> hm = new HashMap<>();
            TreeMap<Integer,Integer> tm = new TreeMap<>();
            for(int i = 0; i < n; i++) {
                int a = f.nextInt();
                hm.put(a, (p[i] = new Pair(a, hm.getOrDefault(a,-1)+1, i)).b);
                tm.put(a, -1);
            }
            {
                int cnt = 0;
                for(int i : tm.keySet()) tm.put(i, cnt++);
            }
            int[] cnt = new int[n];
            Arrays.sort(p);
            for(int i = 0; i < n; i++) {
                arr[p[i].c] = i;
                nx[p[i].c] = -1;
                if(i != n-1 && p[i+1].c > p[i].c)
                    nx[p[i].c] = p[i+1].c;
                end[p[i].c] = i != n-1 && p[i+1].a != p[i].a;
                st[p[i].c] = p[i].b == 0;
                val[p[i].c] = tm.get(p[i].a);
            }
            int ans = 0;
            int[] no = new int[n];
            for(int i = 0; i < n; i++) {
                if(val[i] != 0 && st[i])
                    dp[i] = Math.max(dp[i], cnt[val[i]-1]);
                no[i] = ++cnt[val[i]];
                dp[i]++;
                if(nx[i] != -1) 
                    dp[nx[i]] = dp[i];
            }
            int[] cnt2 = new int[n];
            for(int i = n-1; i >= 0; i--) {
                ans = Math.max(ans, (end[i] ? dp[i] : no[i]) + (val[i] == n-1 ? 0 : cnt2[val[i]+1]));
                cnt2[val[i]]++;
            }
            out.println(n-ans);
        }
///
		out.flush();
	}
    class Pair implements Comparable<Pair> {
        int a, b, c;
        public Pair(int a, int b, int c) {
            this.a = a;
            this.b = b;
            this.c = c;
        }
        public int compareTo(Pair p) {
            if(a != p.a) return Integer.compare(a, p.a);
            return Integer.compare(b, p.b);
        }
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