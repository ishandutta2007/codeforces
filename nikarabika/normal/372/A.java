import java.util.Scanner;
import java.util.Arrays;

public class A{
	public static void main(String[] args){
		Scanner inp = new Scanner(System.in);
		int n = inp.nextInt();
		int[] s = new int[n];
		for(int i = 0; i < n; i++)
			s[i] = inp.nextInt();
		Arrays.sort(s);
		int lo = 0, hi = n / 2 + 1;
		while(hi - lo > 1){
			int mid = (lo + hi) >> 1;
			boolean is = true;
			for(int i = 0; i < mid; i++)
				if(s[i] * 2 > s[n - mid + i])
					is = false;
			if(is)
				lo = mid;
			else
				hi = mid;
		}
		System.out.println(n - lo);
	}
}