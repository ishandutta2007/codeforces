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

		int n = in.nextInt();
		
		int[] x = new int[n];
		int[] d = new int[n];
		for(int i=0;i<n;i++){
			x[i] = in.nextInt();
			d[i] = in.nextInt();
		}
		
		boolean f = false;
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++)
				if(x[i] + d[i] == x[j] && x[j] + d[j] == x[i])
					f=true;
		
		if(f) pw.println("YES");
		else pw.println("NO");
		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}