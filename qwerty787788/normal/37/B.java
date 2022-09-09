import java.io.*;
import java.util.*;

public class CF {

	class Mag implements Comparable<Mag> {
		int pow;
		int dmg, id;

		Mag(int pow, int dmg, int id) {
			this.pow = pow;
			this.dmg = dmg;
			this.id = id;
		}

		@Override
		public int compareTo(Mag o) {
			return -Integer.compare(dmg, o.dmg);
		}
	}

	void solve() {
		int n = in.nextInt();
		int max = in.nextInt();
		int reg = in.nextInt();
		Mag[] a = new Mag[n];
		for (int i = 0; i < n; i++) {
			a[i] = new Mag(in.nextInt(), in.nextInt(), i);
		}
		Arrays.sort(a, new Comparator<Mag>() {

			@Override
			public int compare(Mag o1, Mag o2) {
				return Integer.compare(o1.pow, o2.pow);
			}
		});
		PriorityQueue<Mag> canUse = new PriorityQueue<>();
		int alrRem = 0, nowMove = 0;
		int it = a.length - 1;
		int ITER = 0;
		int nowHP = max;
		ArrayList<Integer> what = new ArrayList<>();
		ArrayList<Integer> when = new ArrayList<>();
		while (true) {
			if (ITER >= 1e5) {
				out.println("NO");
				return;
			}
			while (it != -1) {
				int needPow = a[it].pow;
				if (needPow * max >= nowHP * 100) {
					canUse.add(a[it--]);
				} else {
					break;
				}
			}
			if (canUse.size() > 0) {
				Mag nowUse = canUse.poll();
				what.add(nowUse.id + 1);
				when.add(ITER);
				alrRem += nowUse.dmg;
			}
			ITER++;
			nowHP -= alrRem;
			nowHP += reg;
			if (nowHP <= 0)
				break;
			if (nowHP > max)
				nowHP = max;
		}
		out.println("YES");
		out.println(ITER +" " + what.size());
		for (int i = 0; i < what.size(); i++) {
			out.println(when.get(i)+ " " + what.get(i));
		}
	}

	FastScaner in;
	PrintWriter out;

	void run() {
		in = new FastScaner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	void runWithFiles() {
		in = new FastScaner(new File("input.txt"));
		try {
			out = new PrintWriter(new File("output.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}

		solve();

		out.close();
	}

	public static void main(String[] args) {
		Locale.setDefault(Locale.US);
		new CF().run();
	}

	class FastScaner {
		BufferedReader br;
		StringTokenizer st;

		FastScaner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
		}

		FastScaner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return null;
				st = new StringTokenizer(s);
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}
	}
}