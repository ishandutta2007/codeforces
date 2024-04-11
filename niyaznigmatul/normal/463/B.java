import java.util.*;
import java.io.*;

public class MyFirstProgram {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		int[] d = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			d[i] = in.nextInt();			
		}
		int cur = 0, res = 0;
		for (int i = 1; i <= n; i++) {
			if (cur < 0) {
				res += (0 - cur);
				cur = 0;
			}
			cur += d[i - 1] - d[i];
		}
		if (cur < 0) {
			res += (0 - cur);
			cur = 0;
		}
		System.out.println(res);
 		in.close();
		out.close();
	}

}