import java.io.*;
import java.util.*;


public class Main {
    public static void main(String[] args) {
	new Main().solve();
    }
    void solve() {
	Reader reader = new Reader(System.in);
	int N = reader.nextInt();

	if (N<4) {
	    System.out.println("NO");
	} else {
	    System.out.println("YES");
	    int one;

	    if (N % 2 == 0) {
		one = 1;
		for (int i=5; i<N; i+=2) {
		    one++;
		    System.out.println(i+1 + " - " + i + " = " + 1);
		}
	    } else {
		System.out.println("5 - 3 = 2");
		System.out.println("2 + 1 = 3");
		one = 0;
		for (int i=6; i<N; i+=2) {
		    one++;
		    System.out.println(i+1 + " - " + i + " = " + 1);
		}
	    }

	    System.out.println("2 * 3 = 6");
	    System.out.println("4 * 6 = 24");
	    for (int i=0; i<one; i++) 
		System.out.println("24 * 1 = 24");
	}
    }
}
class Reader {
    public BufferedReader br;
    public StringTokenizer st;
    public Reader(InputStream is) {
	br = new BufferedReader(new InputStreamReader(is));
	st = null;
    }
    public String next() {
	while (st == null || !st.hasMoreTokens()) {
	    try {
		st = new StringTokenizer(br.readLine());
	    } catch (Exception e) {
		e.printStackTrace();
	    }
	}
	return st.nextToken();
    }
    public int nextInt() {
	return Integer.parseInt(next());
    }
}