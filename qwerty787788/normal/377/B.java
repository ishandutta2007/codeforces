import java.io.*;
import java.util.*;

public class CF {

	class Bug implements Comparable<Bug> {
		int id;
		int cost;

		Bug(int id, int cost) {
			this.id = id;
			this.cost = cost;
		}

		@Override
		public int compareTo(Bug o) {
			return -Integer.compare(cost, o.cost);
		}
	}

	class Student {
		int id;
		int can;
		int cost;

		Student(int id, int can, int cost) {
			this.id = id;
			this.can = can;
			this.cost = cost;
		}
	}

	void solve() {
		int m = in.nextInt();
		int n = in.nextInt();
		int s = in.nextInt();
		Bug[] bugs = new Bug[n];
		for (int i = 0; i < n; i++) {
			bugs[i] = new Bug(i, in.nextInt());
		}
		int[] b = new int[m];
		int[] c = new int[m];
		for (int i = 0; i < m; i++)
			b[i] = in.nextInt();
		for (int i = 0; i < m; i++)
			c[i] = in.nextInt();
		Student[] a = new Student[m];
		for (int i = 0; i < m; i++)
			a[i] = new Student(i, b[i], c[i]);
		int maxB = -1;
		for (int i = 0; i < m; i++) {
			if (a[i].cost <= s)
				maxB = Math.max(maxB, a[i].can);
		}
		Arrays.sort(bugs);
		if (bugs[0].cost > maxB) {
			out.println("NO");
			return;
		}
		Arrays.sort(a, new Comparator<Student>() {

			@Override
			public int compare(Student o1, Student o2) {
				return -Integer.compare(o1.can, o2.can);
			}
		});
		int l = 0, r = n + 1;
		int[] ans = null;
		while (r - l > 1) {
			int days = (l + r) / 2;
			TreeSet<Student> allStudents = new TreeSet<>(
					new Comparator<Student>() {

						@Override
						public int compare(Student o1, Student o2) {
							if (o1.cost == o2.cost)
								return Integer.compare(o1.id, o2.id);
							return Integer.compare(o1.cost, o2.cost);
						}
					});
			int need = 0;
			int stIt = 0;
			long totalCost = 0;
			int[] nowAns = new int[n];
			while (need != n) {
				int curCost = bugs[need].cost;
				while (stIt != m && a[stIt].can >= curCost) {
					allStudents.add(a[stIt++]);
				}
				if (allStudents.size() == 0) {
					break;
				}
				Student xx = allStudents.pollFirst();
				totalCost += xx.cost;
				for (int i = 0; i < days; i++) {
					if (need == n)
						break;
					nowAns[bugs[need++].id] = xx.id;
				}
				if (need > n)
					need = n;
			}
			if (need == n && totalCost <= s) {
				ans = nowAns;
				r = days;
			} else {
				l = days;
			}
		}
		out.println("YES");
		for (int i = 0; i < n; i++) {
			out.print((ans[i] + 1) + " ");
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