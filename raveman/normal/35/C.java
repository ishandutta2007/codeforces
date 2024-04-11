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
		int k = in.nextInt();
		
		int[] xx = new int[k];
		int[] yy = new int[k];
		for(int i=0;i<k;i++){
			xx[i] = in.nextInt();
			yy[i]= in.nextInt();
		}
		int x=0,y=0,r;
		r=-1;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				int rr = 1000000;
				for(int q=0;q<k;q++)
					rr = Math.min(rr, Math.abs(xx[q]-1-i)+Math.abs(yy[q]-1-j));
				if(rr>r){
					r=rr;
					x=i;
					y=j;
				}
			}
		pw.print((x+1)+" "+(y+1));

		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}