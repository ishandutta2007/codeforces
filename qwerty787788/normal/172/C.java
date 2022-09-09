import java.util.*;
import java.io.*;

public class Solution {
	FastScanner in;
	PrintWriter out;

	class Student implements Comparable<Student>{
		int t;
		int x;
		int id;
		Student(int x, int t, int id) {
			this.x = x;
			this.t = t;
			this.id = id;
		}
		@Override
		public int compareTo(Student arg0) {
			if (this.x < arg0.x) return -1;
			if (this.x > arg0.x) return 1;
			return 0;
		}
		
		
	}
	
	public void solve() throws IOException {
		int n = in.nextInt();
		int m = in.nextInt();
		long t = 0;
		long ans[] = new long[n];
		ArrayList <Student> ma = new ArrayList<Solution.Student>();
		for (int i = 0; i < n; i++) {
			int ti = in.nextInt();
			int xi = in.nextInt();
			ma.add(new Student(xi, ti, i));
			if (ma.size() == m || i == n - 1) {
				if (ti > t) t = ti;
				long x = 0;
				Student arr[] = new Student[ma.size()];
				for (int j = 0; j < ma.size(); j++) {
					arr[j] = ma.get(j);
				}
				Arrays.sort(arr);
				for (int j = 0; j < arr.length; j++) {
					t += (arr[j].x - x);
					x = arr[j].x;
					ans[arr[j].id] = t;
					int j1 = j;
					int k = 0;
					while (j < arr.length && arr[j].x == arr[j1].x) {
						ans[arr[j].id] = t;
						k++;
						j++;
					}
					t += 1 + (k / 2);
					if (j < arr.length) j--;
				}
				t += x;
				ma.clear();
			}
		}
		for (int i = 0; i < n; i++) {
			out.print(ans[i]);
			out.print(" ");
		}
	}

	public void run() {
		try {
			//in = new FastScanner(new File("input.txt"));
			//out = new PrintWriter(new File("ouput.txt"));

			in = new FastScanner(System.in);
			out = new PrintWriter(System.out);

			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		FastScanner(File f) {
			try {
				br = new BufferedReader(new FileReader(f));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		FastScanner(InputStream f) {
			br = new BufferedReader(new InputStreamReader(f));
		}

		String next() {
			while (st == null || !st.hasMoreTokens()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}
	}

	public static void main(String[] arg) {
		new Solution().run();
	}
}