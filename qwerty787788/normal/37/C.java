import java.io.*;
import java.util.*;

public class CF {

	class Word implements Comparable<Word> {
		int id, len;
		ArrayList<Integer> word;

		Word(int id, int len) {
			this.id = id;
			this.len = len;
		}

		@Override
		public int compareTo(Word o) {
			return Integer.compare(len, o.len);
		}
	}

	void solve() {
		int n = in.nextInt();
		Word[] a = new Word[n];
		for (int i = 0; i < n; i++)
			a[i] = new Word(i, in.nextInt());
		Arrays.sort(a);
		ArrayList<Integer> nowWord = new ArrayList<>();
		int first = a[0].len;
		for (int i = 0; i < first; i++) {
			nowWord.add(0);
		}
		a[0].word = (ArrayList<Integer>) nowWord.clone();
		for (int i = 1; i < n; i++) {
			boolean newOne = false;
			while (true) {
				int last = nowWord.get(nowWord.size() - 1);
				nowWord.remove(nowWord.size() - 1);
				if (last == 0) {
					nowWord.add(1);
					newOne = true;
					break;
				} else {
					if (nowWord.size() == 0)
						break;
				}
			}
			if (!newOne) {
				out.println("NO");
				return;
			}
			while (nowWord.size() < a[i].len)
				nowWord.add(0);
			a[i].word = (ArrayList<Integer>) nowWord.clone();
		}
		out.println("YES");
		ArrayList<Integer>[] ans = new ArrayList[n];
		for (int i = 0; i < n; i++)
			ans[a[i].id] = a[i].word;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < ans[i].size(); j++) {
				out.print(ans[i].get(j));
			}
			out.println();
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