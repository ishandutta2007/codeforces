import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;
public class template {
	public static final int MOD = 1_000_000_007;
	public static void main(String[] args) throws Exception {
		new template().run();
	}
	public void run() throws Exception {
		FastScanner f = new FastScanner();
		PrintWriter out = new PrintWriter(System.out);
		int n = f.nextInt();
		long m = f.nextLong();
		PriorityQueue<Pair> pq1 = new PriorityQueue<Pair>();
		PriorityQueue<Pair> pq2 = new PriorityQueue<Pair>();
		for(int i = 0; i < n; i++)
			pq1.add(new Pair(f.nextInt()-1, f.nextLong(), f.nextLong()+1));
		long curm = 1;
		long[][] cur = {{0,1,0}};
		long[][] mat = {{1,1,0},{1,1,1},{0,1,1}};
		long[][] defaul = {{1,1,0},{1,1,1},{0,1,1}};
		int[] cnts = new int[3];
		while(!pq1.isEmpty() || !pq2.isEmpty()) {
			if(pq1.isEmpty() || !pq2.isEmpty() && pq2.peek().a < pq1.peek().a) {
				//remove seg
				Pair p = pq2.poll();
				cur = mult(cur,pow(mat,curm-p.a));
				cnts[p.r]--;
				if(cnts[p.r] == 0)
					for(int i = 0; i < 3; i++)
						mat[p.r][i] = defaul[p.r][i];
				curm = p.a;
			} else {
				//add seg
				Pair p = pq1.poll();
				cur = mult(cur,pow(mat,curm-p.a));
				pq2.add(p.getComp());
				if(cnts[p.r] == 0)
					for(int i = 0; i < 3; i++)
						mat[p.r][i] = 0;
				cnts[p.r]++;
				curm = p.a;
			}
			//System.out.println(Arrays.toString(cur[0]));
		}
		cur = mult(cur,pow(mat,m-curm));
		System.out.println(cur[0][1]);
		out.flush();
	}
	public long[][] pow(long[][] mat, long e) {
		if(e == 0) return new long[][] {{1,0,0},{0,1,0},{0,0,1}};
		long[][] m = pow(mat,e/2);
		m = mult(m,m);
		if((e & 1) == 1) return mult(m,mat);
		return m;
	}
	public long[][] mult(long[][] mat1, long[][] mat2) {
		long[][] ans = new long[mat1.length][mat2[0].length];
		for(int i = 0; i < mat1.length; i++) {
			for(int j = 0; j < mat2[0].length; j++) {
				for(int k = 0; k < mat1[0].length; k++)
					ans[i][j] = (ans[i][j] + mat1[i][k]*mat2[k][j]% MOD) % MOD;
			}
		}
		return ans;
	}
	class Pair implements Comparable<Pair> {
		long a, b;
		int r;
		public Pair(int r, long a, long b) {
			this.a = a;
			this.b = b;
			this.r = r;
		}
		public int compareTo(Pair p) {
			if(a != p.a) return Long.compare(a, p.a);
			else return Long.compare(b, p.b);
		}
		public Pair getComp() {
			return new Pair(r,b,a);
		}
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