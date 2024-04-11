import java.io.*;
import java.util.*;

public class E implements Runnable {
	public static void main(String[] args) {
		new Thread(new E()).start();
	}

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return "0";
			}
		}
		return st.nextToken();
	}

	public void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);
			solve();
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
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

	TreeMap<Integer, Integer> g;

	void add(int x) {
		if (g.containsKey(x)) {
			g.put(x, g.get(x) + 1);
		} else {
			g.put(x, 1);
		}
	}

	void remove(int x) {
		if (g.get(x) - 1 == 0)
			g.remove(x);
		else
			g.put(x, g.get(x) - 1);
	}

	void solve() {
		int n = nextInt();
		int k = nextInt();
		int[] h = new int[n + 1];
		for (int i = 0; i < h.length - 1; i++) {
			h[i] = nextInt();
		}
		h[n] = 1000000000;
		int j = 1;
		g = new TreeMap<Integer, Integer>();
		TreeMap<Integer, ArrayList<Integer>> ans = new TreeMap<Integer, ArrayList<Integer>>();
		add(h[0]);
		for (int i = 0; i < n; i++) {
			while (j < n + 1) {
				if (g.lastKey() - g.firstKey() > k) {
					break;
				}
				add(h[j++]);
			}
			if (ans.containsKey(j - i - 1)) {
				ans.get(j - i - 1).add(i);
			} else {
				ArrayList<Integer> e = new ArrayList<Integer>();
				e.add(i);
				ans.put(j - i - 1, e);
			}
			remove(h[i]);
		}
		int len = ans.lastEntry().getKey();
		ArrayList<Integer> toPrint = ans.lastEntry().getValue();
		Collections.sort(toPrint);
		out.println(len + " " + toPrint.size());
		for (int i : toPrint) {
			out.println((i + 1) + " " + (i + len));
		}
	}
}