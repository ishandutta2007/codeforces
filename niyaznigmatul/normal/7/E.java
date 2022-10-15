import java.io.*;
import java.util.*;

public class Solution {

	static final int PAR = 0;
	static final int DIV = 1;
	static final int MUL = 2;
	static final int SUB = 3;
	static final int ADD = 4;
	static Map<String, Integer> types;
	static Set<String> suspicious;
	static char[] str;
	static int current;

	static class SuspiciousException extends RuntimeException {

	}

	static int parse() {
		int ret = parseFactor();
		while (current < str.length && "+-".indexOf(str[current]) >= 0) {
			int c = str[current++];
			int type = parseFactor();
			if (c == '-') {
				if (type >= SUB) {
					throw new SuspiciousException();
				}
			}
			ret = ADD;
		}
		return ret;
	}

	static int parseFactor() {
		int ret = parseTerm();
		while (current < str.length && "*/".indexOf(str[current]) >= 0) {
			int c = str[current++];
			int type = parseTerm();
			if (ret >= SUB)
				throw new SuspiciousException();
			if (c == '/') {
				if (type >= DIV) {
					throw new SuspiciousException();
				}
			} else if (type >= SUB) {
				throw new SuspiciousException();
			}
			ret = MUL;
		}
		return ret;
	}

	static int parseTerm() {
		if (str[current] == '(') {
			++current;
			parse();
			++current;
			return PAR;
		}
		if (str[current] >= '0' && str[current] <= '9') {
			while (current < str.length && str[current] >= '0'
					&& str[current] <= '9') {
				++current;
			}
			return PAR;
		}
		String f = "";
		while (current < str.length && Character.isLetter(str[current])) {
			f += str[current++];
		}
		if (suspicious.contains(f)) {
			throw new SuspiciousException();
		}
		if (types.containsKey(f)) {
			return types.get(f);
		} else {
			return PAR;
		}
	}

	static void solve() throws IOException {
		int n = Integer.parseInt(br.readLine());
		suspicious = new HashSet<String>();
		types = new HashMap<String, Integer>();
		for (int i = 0; i < n; i++) {
			String line = br.readLine();
			int pos = line.indexOf("define");
			line = line.substring(pos + 6);
			while (line.startsWith(" "))
				line = line.substring(1);
			pos = line.indexOf(' ');
			String name = line.substring(0, pos);
			line = line.substring(pos).replaceAll(" ", "");
			str = line.toCharArray();
			current = 0;
			try {
				int type = parse();
				types.put(name, type);
			} catch (SuspiciousException e) {
				suspicious.add(name);
			}
		}
		String line = br.readLine().replaceAll(" ", "");
		try {
			str = line.toCharArray();
			current = 0;
			parse();
			out.println("OK");
		} catch (SuspiciousException e) {
			out.println("Suspicious");
		}
	}

	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter out;

	public static void main(String[] args) throws IOException {
		InputStream input = System.in;
		PrintStream output = System.out;
		File file = new File("s.in");
		if (file.exists() && file.canRead()) {
			input = new FileInputStream(file);
			output = new PrintStream("s.out");
		}
		br = new BufferedReader(new InputStreamReader(input));
		out = new PrintWriter(output);
		solve();
		out.close();
		br.close();
	}

	static boolean hasNext() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			String line = br.readLine();
			if (line == null) {
				return false;
			}
			st = new StringTokenizer(line);
		}
		return true;
	}

	static String next() throws IOException {
		return hasNext() ? st.nextToken() : null;
	}

	static int nextInt() throws IOException {
		return Integer.parseInt(next());
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static long nextLong() throws IOException {
		return Long.parseLong(next());
	}
}