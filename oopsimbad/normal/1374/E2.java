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
		int n = f.nextInt(), m = f.nextInt(), k = f.nextInt();
		ArrayList<Pair> _00 = new ArrayList<>();
		ArrayList<Pair> _01 = new ArrayList<>();
		ArrayList<Pair> _10 = new ArrayList<>();
		ArrayList<Pair> _11 = new ArrayList<>();
		Pair[] p = new Pair[n];
		for(int i = 0; i < n; i++) {
			int t = f.nextInt(), a = f.nextInt(), b = f.nextInt();
			p[i] = new Pair(t, i);
			if(a == 0 && b == 0) _00.add(new Pair(t, i));
			if(a == 0 && b == 1) _01.add(new Pair(t, i));
			if(a == 1 && b == 0) _10.add(new Pair(t, i));
			if(a == 1 && b == 1) _11.add(new Pair(t, i));
		}
		Arrays.sort(p);
		int[] to = new int[n];
		for(int i = 0; i < n; i++) to[p[i].b] = i;
		BIT b = new BIT(n);
		Collections.sort(_11);
		Collections.sort(_01);
		Collections.sort(_10);
		for(Pair i : _00) b.add(to[i.b], i.a);
		for(Pair i : _01) b.add(to[i.b], i.a);
		for(Pair i : _10) b.add(to[i.b], i.a);
		for(Pair i : _11) b.add(to[i.b], i.a);
		if(Math.min(_10.size(),_01.size()) + _11.size() < k) {
			out.println(-1);
			out.flush();
			return;
		}
		int ans = 2147483647;
		int cur = 0;
		int cnt = 0;
		for(Pair i : _11) {
			cur += i.a;
			b.remove(to[i.b], i.a);
			cnt++;
		}
		for(int i = 0; i < k-_11.size(); i++) {
			cur += _01.get(i).a+_10.get(i).a;
			cnt += 2;
			b.remove(to[_01.get(i).b], _01.get(i).a);
			b.remove(to[_10.get(i).b], _10.get(i).a);
		}
		int besti = _11.size();
		if(cnt <= m) ans = cur+b.get(m-cnt);
		for(int c = _11.size()-1; c >= 0; c--) {
			cur -= _11.get(c).a;
			cnt--;
			b.add(to[_11.get(c).b], _11.get(c).a);
			if(c < k) {
				if(k-c-1 >= Math.min(_01.size(), _10.size())) break;
				cur += _01.get(k-c-1).a+_10.get(k-c-1).a;
				b.remove(to[_01.get(k-c-1).b], _01.get(k-c-1).a);
				b.remove(to[_10.get(k-c-1).b], _10.get(k-c-1).a);
				cnt += 2;
			}
			int a = cur+b.get(m-cnt);
			if(a < ans && m-cnt >= 0) {
				ans = a;
				besti = c;
			}
		}
		if(ans == 2147483647) {
			out.println(-1);
			out.flush();
			return;
		}
		out.println(ans);
		PriorityQueue<Pair> ts = new PriorityQueue<>();
		cnt = m;
		for(int i = 0; i < _11.size(); i++)
			if(i < besti) {
				out.print(_11.get(i).b + 1 + " ");
				cnt--;
			} else ts.add(_11.get(i));
		for(int i = 0; i < _10.size(); i++)
			if(i < k-besti) {
				out.print(_10.get(i).b + 1 + " ");
				cnt--;
			} else ts.add(_10.get(i));
		for(int i = 0; i < _01.size(); i++)
			if(i < k-besti) {
				out.print(_01.get(i).b + 1 + " ");
				cnt--;
			} else ts.add(_01.get(i));
		ts.addAll(_00);
		while(cnt-->0) out.print(ts.poll().b + 1 + " ");
		out.println();
///
		out.flush();
	}
	class Pair implements Comparable<Pair> {
		int a, b;
		public Pair(int a, int b) {
			this.a = a;
			this.b = b;
		}
		public int compareTo(Pair p) {
			if(a == p.a) return Integer.compare(b, p.b);
			return Integer.compare(a, p.a);
		}
	}
	class BIT {
		int[] a, b;
		public BIT(int sz) {
			a = new int[sz+1];
			b = new int[sz+1];
		}
		public void add(int i, int v) {
			i++;
			while(i < a.length) {
				a[i]++;
				b[i] += v;
				i += i & -i;
			}
		}
		public void remove(int i, int v) {
			i++;
			while(i < a.length) {
				a[i]--;
				b[i] -= v;
				i += i & -i;
			}
		}
		public int get(int cnt) {
			int i = 0;
			int v = 0;
			int v2 = 0;
			for(int bit = 1 << 20; bit > 0; bit >>= 1) {
				if(i+bit >= a.length) continue;
				if(v+a[i+bit] <= cnt) {
					i += bit;
					v += a[i];
					v2 += b[i];
				}
			}
			return v2;
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