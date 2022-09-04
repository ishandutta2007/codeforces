import java.lang.*;
import java.math.*;
import java.util.*;

public class sample {
	public static void main(String[] args) {
		int v = 0;
		Scanner read = new Scanner(System.in);
		int n = read.nextInt();
		int m = read.nextInt();
		List<Integer> q = new ArrayList<>();
		for (int i = 0; i < n; i++){
			int w = read.nextInt();
			q.add(w);
			v = Math.max(v, w);
		}
		int s = 0;
		for (int i = 0; i < n; i++){
			s += v - q.get(i);
		}
		System.out.print(v + Math.max(0, (m - s + n - 1) / n) + " " + (v + m));
	}
}