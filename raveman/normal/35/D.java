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
	public String[][] a;
	public void run () throws Exception {
		Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(new  File("output.txt"));

		int n = in.nextInt();
		int m = in.nextInt();

		int[] x = new int[n];
		for(int i=0;i<n;i++){
			int y = in.nextInt();
			
			y *= (n-i);
			x[i] = y;
		}
		Arrays.sort(x);
		
		int res = 0;
		int sum = 0;
		for(int i=0;i<x.length;i++){
			sum += x[i];
			if(sum<=m) res = i + 1;
		}
		pw.println(res);
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}