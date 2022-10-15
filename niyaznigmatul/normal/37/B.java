import java.io.*;
import java.util.*;
import java.math.*;

public class B implements Runnable {
	public static void main(String[] args) {
		new B().run();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;
		boolean eof;
		String buf;

		public FastScanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
			nextToken();
		}

		public FastScanner(InputStream stream) {
			br = new BufferedReader(new InputStreamReader(stream));
			nextToken();
		}

		String nextToken() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (Exception e) {
					eof = true;
					break;
				}
			}
			String ret = buf;
			buf = eof ? "-1" : st.nextToken();
			return ret;
		}

		int nextInt() {
			return Integer.parseInt(nextToken());
		}

		long nextLong() {
			return Long.parseLong(nextToken());
		}

		double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		BigInteger nextBigInteger() {
			return new BigInteger(nextToken());
		}

		void close() {
			try {
				br.close();
			} catch (Exception e) {

			}
		}

		boolean isEOF() {
			return eof;
		}
	}

	FastScanner sc;
	PrintWriter out;

	public void run() {
		Locale.setDefault(Locale.US);
		try {
			sc = new FastScanner(System.in);
			out = new PrintWriter(System.out);
			solve();
			sc.close();
			out.close();
		} catch (Throwable e) {
			e.printStackTrace();
			System.exit(1);
		}
	}

	int nextInt() {
		return sc.nextInt();
	}

	String nextToken() {
		return sc.nextToken();
	}

	long nextLong() {
		return sc.nextLong();
	}

	double nextDouble() {
		return sc.nextDouble();
	}

	BigInteger nextBigInteger() {
		return sc.nextBigInteger();
	}

	class Item {
		int pow;
		int dmg;
		int num;

		public Item(int pow, int dmg, int num) {
			this.pow = pow;
			this.dmg = dmg;
			this.num = num;
		}

	}

	class Answer {
		int t;
		int n;

		public Answer(int t, int n) {
			this.t = t;
			this.n = n;
		}

	}

	void solve() {
		int n = nextInt();
		int hp = nextInt();
		int reg = nextInt();
		Item[] a = new Item[n];
		for (int i = 0; i < a.length; i++) {
			a[i] = new Item(nextInt(), nextInt(), i + 1);
		}
		Arrays.sort(a, new Comparator<Item>() {
			@Override
			public int compare(Item o1, Item o2) {
				return o1.pow < o2.pow ? 1 : o1.pow > o2.pow ? -1 : 0;
			}
		});
		int cur = 0;
		int curHP = hp;
		int dmg = 0;
		int q = 0;
		ArrayList<Answer> ans = new ArrayList<B.Answer>();
		TreeSet<Item> tree = new TreeSet<B.Item>(new Comparator<Item>() {
			@Override
			public int compare(Item o1, Item o2) {
				return o1.dmg < o2.dmg ? -1 : o1.dmg > o2.dmg ? 1 : (o1.num - o2.num);
			}
		});
		while (cur < n && a[cur].pow * hp >= 100 * curHP) {
			tree.add(a[cur++]);
		}
		if (!tree.isEmpty()) {
			Item e = tree.pollLast();
			dmg += e.dmg;
			ans.add(new Answer(q, e.num));
		}
		while (true) {
			++q;
			int was = curHP;
			curHP -= dmg;
			curHP += reg;
			curHP = Math.min(curHP, hp);
			if (curHP <= 0) {
				out.println("YES");
				out.println(q + " " + ans.size());
				for (Answer e : ans) {
					out.println(e.t + " " + e.n);
				}
				return;
			}
			while (cur < n && a[cur].pow * hp >= 100 * curHP) {
				tree.add(a[cur++]);
			}
			if (was <= curHP && tree.isEmpty()) {
				out.println("NO");
				return;
			}
			if (!tree.isEmpty()) {
				Item e = tree.pollLast();
				dmg += e.dmg;
				ans.add(new Answer(q, e.num));
			}			
		}
	}
}