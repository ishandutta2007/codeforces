import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		int n = in.nextInt();
		int[] a = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		boolean found = false;
		
		int mx = 0, mn = 0;
		for(int i=1;i<n;i++){
			if(a[i]!=a[i-1]){
				if(a[i] >  a[i-1]){
					if(a[mx] > a[i-1]){
						pw.println(3);
						pw.println((mx+1)+" "+(i)+" "+(i+1));
						found = true;
						break;
					}
				}else{
					if(a[mn] < a[i-1]){
						pw.println(3);
						pw.println((mn+1)+" "+i+" "+(i+1));
						found = true;
						break;
					}
					
				}
			}
			if(a[i] > a[mx]) mx = i;
			if(a[i] < a[mn]) mn = i;
		}
		if(!found) pw.println(0);
	
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}