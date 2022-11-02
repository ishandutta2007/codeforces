import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;
import java.util.Dictionary;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Queue;
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
		
		boolean f = false;
		
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				for(int k=j+1;k<n;k++)if(a[i] ==a[j] + a[k]){
					pw.println((i+1)+" "+(j+1)+" "+(k+1));
					f=true;
					break;
				}
				if(f) break;
			}
			if(f) break;
		}
		if(!f) pw.println("-1");

		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}