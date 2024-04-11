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
			int r = f.nextInt(), c = f.nextInt();
			int[] to = new int[r*c];
			LinkedList<Integer>[] rev = new LinkedList[r*c];
			boolean[] black = new boolean[r*c];
			boolean[] vis1 = new boolean[r*c];
			boolean[] vis2 = new boolean[r*c];
			int[] ind = new int[r*c];
			for(int i = 0; i < r; i++) {
				char[] a = f.next().toCharArray();
				for(int j = 0; j < c; j++) {
					black[i*c+j] = a[j] == '0';
					rev[i*c+j] = new LinkedList<>();
				}
			}
			for(int i = 0; i < r; i++) {
				char[] a = f.next().toCharArray();
				for(int j = 0; j < c; j++) {
					if(a[j] == 'U') to[i*c+j] = (i-1)*c+j;
					if(a[j] == 'D') to[i*c+j] = (i+1)*c+j;
					if(a[j] == 'L') to[i*c+j] = i*c+j-1;
					if(a[j] == 'R') to[i*c+j] = i*c+j+1;
					rev[to[i*c+j]].add(i*c+j);
				}
			}
			int ans1 = 0, ans2 = 0;
			LinkedList<Integer> ll = new LinkedList<>();
			for(int i = 0; i < r*c; i++) {
				if(vis2[i]) continue;
				int d = 0;
				int j = i;
				while(!vis1[j]) {
					vis1[j] = true;
					ind[j] = d++;
					j = to[j];
				}
				int len = d-ind[j];
				ans1 += len;
				boolean[] exist = new boolean[len];
				ll.add(j); ll.add(0);
				while(!ll.isEmpty()) {
					j = ll.poll();
					d = ll.poll();
					if(vis2[j]) continue;
					if(black[j]) exist[d] = true;
					vis2[j] = true;
					d = (d+1)%len;
					for(int k : rev[j]) {
						ll.add(k);
						ll.add(d);
					}
				}
				for(boolean b : exist)
					if(b) ans2++;
			}
			out.println(ans1 + " " + ans2);
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