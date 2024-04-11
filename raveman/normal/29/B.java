import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		int l = in.nextInt();
		int d = in.nextInt();
		int v = in.nextInt();
		int g = in.nextInt();
		int r = in.nextInt();
		
		double res = ((double)l)/v;
		
		while( d >= v * (r + g))
			d -= v * (r+g);
		if( d >= g*v )
			res += r - d / ((double)v) + g; 
		pw.println(String.format("%.6f", res));
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}