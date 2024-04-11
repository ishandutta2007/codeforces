import java.io.*;
import java.util.*;

public class CF {

	Random rnd = new Random(123);

	String getRandomString() {
		int n = rnd.nextInt(100) + 1;
		char[] res = new char[n];
		for (int i = 0; i < n; i++)
			res[i] = (char) (rnd.nextInt(126 - 32) + 32);
		return new String(res);
	}

	void realSolve() throws IOException {
		for (int iter = 0; iter < 1; iter++) {
			//System.err.println(iter);
			String p = in.br.readLine();
			String s = in.br.readLine();
			int k = in.nextInt();
			// String p = getRandomString();
			// String s = getRandomString();
			// int k = rnd.nextInt(100) + 1;
			ArrayList<ArrayList<Character>> a = new ArrayList<>();
			for (int i = 0; i < k; i++) {
				ArrayList<Character> tmp = new ArrayList<>();
				for (int j = i; j < p.length(); j += k)
					tmp.add(p.charAt(j));
				a.add(tmp);
			}
			String best = null;
			for (int cntOnes = 1; cntOnes <= k; cntOnes++) {
				int small = (p.length() / k - 1) * cntOnes;
				int big = (p.length() / k + 1) * cntOnes;
				if (small > s.length() || big < s.length())
					continue;
				ArrayList<ArrayList<Character>> b = new ArrayList<>();
				for (int i = 0; i < cntOnes; i++) {
					ArrayList<Character> tmp = new ArrayList<>();
					for (int j = i; j < s.length(); j += cntOnes)
						tmp.add(s.charAt(j));
					b.add(tmp);
				}
				boolean[] get = new boolean[k];
				int it1 = cntOnes - 1;
				for (int i = k - 1; i >= 0; i--) {
					boolean same = true;
					if (b.get(it1).size() != a.get(i).size())
						same = false;
					if (same) {
						for (int j = 0; j < b.get(it1).size(); j++)
							if (b.get(it1).get(j) != a.get(i).get(j)) {
								same = false;
								break;
							}
					}
					if (same) {
						get[i] = true;
						it1--;
					}
					if (it1 == -1)
						break;
				}
				if (it1 == -1) {
					char[] res = new char[k];
					for (int i = 0; i < k; i++)
						if (get[i])
							res[i] = '1';
						else
							res[i] = '0';
					String curAns = new String(res);
					if (best == null || best.compareTo(curAns) > 0)
						best = curAns;
				}
			}
			if (best == null) {
				out.println(0);
			} else {
				out.println(best);
			}
		}
	}

	private class InputReader {
		StringTokenizer st;
		BufferedReader br;

		public InputReader(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public InputReader(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return null;
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

		double nextDouble() {
			return Double.parseDouble(next());
		}

		boolean hasMoreElements() {
			while (st == null || !st.hasMoreElements()) {
				String s;
				try {
					s = br.readLine();
				} catch (IOException e) {
					return false;
				}
				st = new StringTokenizer(s);
			}
			return st.hasMoreElements();
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}

	InputReader in;
	PrintWriter out;

	void solveIO() throws IOException {
		in = new InputReader(System.in);
		out = new PrintWriter(System.out);

		realSolve();

		out.close();

	}

	public static void main(String[] args) throws IOException {
		new CF().solveIO();
	}
}