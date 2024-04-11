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

	public int h,w,n;
	public int[][] xx;
	public int[][] yy;
	public boolean[][] u;
	
	public int dfs(int x,int y){
		if(u[x][y]) return 0;
		int res = 1;
		u[x][y]=true;
		for(int dx = -1;dx<=1;dx++)
			for(int dy=-1;dy<=1;dy++)if(dx==0 || dy==0)if(dx!=0 || dy!=0){
				int nx = x + dx;
				int ny = y + dy;
				if(nx<0 || nx>=w || ny<0 || ny>=h) continue;
				boolean good = true;
				
				if(dx==0){
					for(int i=0;i<n;i++){
						if(yy[i][0]==yy[i][1] && yy[i][0] == Math.max(y, ny)){
							if(xx[i][0]<=x && xx[i][1]>x)
								good = false;
						}
					}
				}
				if(dy==0){
					for(int i=0;i<n;i++){
						if(xx[i][0]==xx[i][1] && xx[i][0] == Math.max(x, nx)){
							if(yy[i][0]<=y && yy[i][1]>y)
								good = false;
						}
					}
				}
				
				
				if(good) res += dfs(nx,ny);
			}
		return res;
	}
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		w=in.nextInt();h=in.nextInt();n=in.nextInt();
		xx =new int[n][2];
		yy = new int[n][2];
		for(int i=0;i<n;i++){
			xx[i][0]= in.nextInt();
			yy[i][0] = in.nextInt();
			xx[i][1] = in.nextInt();
			yy[i][1] = in.nextInt();
		}
		ArrayList<Integer> s = new ArrayList<Integer>();
		u = new boolean[111][111];
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				if(!u[j][i])
					s.add(dfs(j,i));
		Collections.sort(s);
		for(int i=0;i<s.size();i++){
			if(i>0) pw.print(" ");
			pw.print(s.get(i));
		}
		pw.println();
		
			

		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}