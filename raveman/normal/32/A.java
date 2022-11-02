import java.io.File;
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
		PrintWriter pw = new PrintWriter(System.out);
		
		int n ,d;
		n=in.nextInt();
		d=in.nextInt();
		
		int[] a = new int[n];
		for(int i=0;i<n;i++)
			a[i] = in.nextInt();
		
		int num = - n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(Math.abs(a[i]-a[j])<=d)
					num++;

		pw.println(num);
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}