import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class A {
	FastScanner in;
	PrintWriter out;

	TreeMap<Integer, ArrayList<Integer>> hm = new TreeMap<Integer, ArrayList<Integer>>();

	void addFriend(int fr, int to) {
		ArrayList<Integer> all = hm.get(fr);
		if (all == null) {
			all = new ArrayList<>();
			hm.put(fr, all);
		}
		all.add(to);
		allC.add(getId(fr, to));
	}

	long getId(int x, int y) {
		return ((x + 0L) << 31) | y;
	}

	HashSet<Long> allC = new HashSet<>();

	void solve() {
		int n = in.nextInt();
		int k = in.nextInt();
		TreeSet<Integer> allUsers = new TreeSet<>();
		for (int i = 0; i < n; i++) {
			int fr = in.nextInt(), to = in.nextInt();
			addFriend(fr, to);
			addFriend(to, fr);
			allUsers.add(fr);
			allUsers.add(to);
		}
		for (Entry<Integer, ArrayList<Integer>> entry : hm.entrySet()) {
			out.print(entry.getKey() + ": ");
			ArrayList<Integer> friend = new ArrayList<>();
			for (int newFriend : allUsers) {
				if (newFriend != entry.getKey()
						&& !allC.contains(getId(entry.getKey(), newFriend))) {
					int same = 0;
					for (int to : entry.getValue()) {
						if (allC.contains(getId(to, newFriend))) {
							same++;
						}
					}
					if (same * 100 >= entry.getValue().size() * k) {
						// out.print(newFriend + " ");
						friend.add(newFriend);
					}
				}
			}
			out.print(friend.size());
			Collections.sort(friend);
			for (int t : friend) {
				out.print(" " + t);
			}
			out.println();
		}
	}

	void run() {
		try {
			in = new FastScanner(new File("A.in"));
			out = new PrintWriter(new File("A.out"));

			solve();

			out.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	void runIO() {

		in = new FastScanner(System.in);
		out = new PrintWriter(System.out);

		solve();

		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
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

		boolean hasMoreTokens() {
			while (st == null || !st.hasMoreTokens()) {
				String s = null;
				try {
					s = br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
				if (s == null)
					return false;
				st = new StringTokenizer(s);
			}
			return true;
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

	public static void main(String[] args) {
		new A().runIO();
	}
}