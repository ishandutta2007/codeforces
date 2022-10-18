import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.*;

public class Main{
	public static void main (String[] args) throws java.lang.Exception {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();

		int petr = 0;
		for (int i = 1; i <= n; i++) {
			int x = scan.nextInt();
			if (x > petr) {
				System.out.println(i); return;
			}
			if (x == petr) petr++;
		}
		System.out.println("-1");
	}
}