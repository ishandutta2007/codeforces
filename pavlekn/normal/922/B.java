import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				if ((i ^ j) >= j && (i ^ j) <= n && i + j > (i ^ j)) {
					++ans;
				}
			}
		}
		System.out.println(ans);
	}
}