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
		LinkedList<Integer>[] adj1 = new LinkedList[n];
		LinkedList<Integer>[] adj2 = new LinkedList[n];
		LinkedList<Integer>[] rev = new LinkedList[n];
		for(int i = 0; i < n; i++) {
			adj1[i] = new LinkedList<>();
			adj2[i] = new LinkedList<>();
			rev[i] = new LinkedList<>();
		}
		int[] in1 = new int[n];
		int[] in2 = new int[n];
		for(int i = 0; i < m; i++) {
			int a = f.nextInt()-1, b = f.nextInt()-1;
			in1[b]++;
			adj1[a].add(b);
			rev[b].add(a);
			if(a > b) {
				adj2[b].add(a);
				in2[a]++;
			} else {
				adj2[a].add(b);
				in2[b]++;
			}
		}
		LinkedList<Integer> ll = new LinkedList<>();
		for(int i = 0; i < n; i++)
			if(in1[i] == 0) ll.add(i);
		int tot = 0;
		while(!ll.isEmpty()) {
			tot++;
			int i = ll.poll();
			for(int j : adj1[i])
				if(--in1[j] == 0)
					ll.add(j);
		}
		if(tot == n) {
			char[] vals = new char[n];
			boolean[] vis1 = new boolean[n];
			boolean[] vis2 = new boolean[n];
			for(int i = 0; i < n; i++) {
                                boolean A = vals[i] == 0;
ll.add(i);
						while(!ll.isEmpty()) {
							int j = ll.poll();
							if(vis1[j]) continue;
							vis1[j] = true;
							vals[j] = 'E';
							for(int k : adj1[j])
								ll.add(k);
						}
						ll.add(i);
						while(!ll.isEmpty()) {
							int j = ll.poll();
							if(vis2[j]) continue;
							vis2[j] = true;
							vals[j] = 'E';
							for(int k : rev[j])
								ll.add(k);
						}
						if(A) vals[i] = 'A';
			}
			int ans = 0;
			for(char c : vals)
				if(c == 'A') ans++;
			out.println(ans);
			out.println(vals);
		} else out.println(-1);
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