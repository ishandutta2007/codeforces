import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
	public static void main (String[] args)
	{
		Scanner scan = new Scanner(System.in);
		long n = scan.nextLong();
		long k = scan.nextLong();
		System.out.print((k + n - 1)/n);
	}
}