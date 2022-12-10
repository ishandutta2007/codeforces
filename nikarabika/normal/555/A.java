import java.util.Scanner;

public class A{
	static int n, k, ans;
	public static void main(String[] args){
		Scanner inp = new Scanner(System.in);
		n = inp.nextInt();
		k = inp.nextInt();
		for(int i = 0; i < k; i++){
			int cnt = inp.nextInt();
			boolean x = false;
			int last = inp.nextInt();
			if(last != 1)
				x = true;
			int now;
			for(int j = 0; j < cnt - 1; j++){
				now = inp.nextInt();
				if(now != last + 1)
					x = true;
				ans += (x) ? 1 : -1;
				last = now;
			}
		}
		System.out.println(ans + n - 1);
	}
}