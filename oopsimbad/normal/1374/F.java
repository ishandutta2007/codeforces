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
		while(asdf-->0) {
			int n = f.nextInt();
			int[] arr = new int[n];
			HashMap<Integer,Integer> hm = new HashMap<>();
			ArrayList<Integer> moves = new ArrayList<>();
			int[] cnt = new int[500];
			boolean flip = false;
			for(int i = 0; i < n; i++) {
				int a = f.nextInt();
				hm.put(a, hm.getOrDefault(a, 0)+1);
				arr[i] = 1000*a+hm.get(a);
				cnt[a-1] ^= 1;
				for(int j = 499; j >= a; j--) if(cnt[j] % 2 == 1) flip ^= true;
			}
			if(flip) {
				int a = -1;
				for(int i : hm.keySet())
					if(hm.get(i) >= 2) {
						a = i;
						break;
					}
				if(a == -1) {
					out.println(-1);
					continue;
				}
				for(int i = 0; i < n; i++)
					if(arr[i] == a*1000+1) arr[i]++;
					else if(arr[i] == a*1000+2) arr[i]--;
			}
			for(int e = n-1; e >= 2; e--) {
				int max = arr[0], loc = 0;
				for(int i = 1; i <= e; i++)
					if(arr[i] >= max) {
						max = arr[i];
						loc = i;
					}
				if(loc == 0) {
					moves.add(1);
					loc++;
					int t = arr[2];
					arr[2] = arr[1];
					arr[1] = arr[0];
					arr[0] = t;
				}
				for(; loc < e; loc++) {
					moves.add(loc);
					int t = arr[loc+1];
					arr[loc+1] = arr[loc];
					arr[loc] = arr[loc-1];
					arr[loc-1] = t;
				}
			}
			boolean ok = true;
			for(int i = 0; i < n-1; i++) ok &= arr[i] <= arr[i+1];
			if(!ok) {
				
			}
			if(ok) {
				out.println(moves.size());
				for(int i : moves) out.print(i + " ");
				out.println();
			} else out.println(-1);
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