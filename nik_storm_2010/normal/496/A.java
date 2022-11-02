import java.util.*;

public class A {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int numbers;
		numbers = in.nextInt();
		int[] value = new int[numbers];
		for (int it = 0; it < numbers; it++) value[it] = in.nextInt();
		int answer = 1 << 30;
		for (int bad = 1; bad < numbers - 1; bad++) {
			int current = 0, lastHeight = value[0];
			for (int it = 1; it < numbers; it++) {
				if (it == bad) continue;
				current = Math.max(current, value[it] - lastHeight);
				lastHeight = value[it];
			}
			answer = Math.min(answer, current);
		}
		System.out.println(answer);
	}
}