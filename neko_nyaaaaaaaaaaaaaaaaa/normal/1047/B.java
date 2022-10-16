import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class B{
	public static void main (String[] args) throws java.lang.Exception {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int ans = 0;
		while (n > 0) {
			n--;
			int x = scan.nextInt();
			int y = scan.nextInt();
			ans = (x+y > ans ? x+y : ans);
		}
		System.out.print(ans);
	}
}