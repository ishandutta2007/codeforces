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
		a= new String[n][m];
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				a[i][j]="";
		for(int i=0;i<k;i++){
			String type = in.next();
			if(type.equals("+1")){
				int x = in.nextInt();
				int y = in.nextInt();
				x--;y--;
				String s = in.next();
				
				boolean f = false;
				for(int X=x;X<n;X++){
					for(int Y=0;Y<m;Y++) if(X>x || Y>=y){
						if(a[X][Y].length()==0){
							a[X][Y] = s;
							f=true;
							break;
						}
					}
					if(f) break;
				}	
			}else{
				String s = in.next();
				int X =-1,Y=-1;
				for(int x =0;x<n;x++)for(int y = 0;y<m;y++)
					if(a[x][y].equals(s)){
						a[x][y]="";
						X=x+1;
						Y=y+1;
					}
				
				pw.println(X+" "+Y);
			}
		}

		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}