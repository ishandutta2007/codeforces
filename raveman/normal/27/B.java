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
		boolean[][] u = new boolean[n][n];
		for(int i=0;i<n*(n-1)/2-1;i++){
			int x,y;
			x=in.nextInt();
			y=in.nextInt();
			x--;y--;
			u[x][y]=u[y][x]=true;
			a[x]++;
		}

		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)if(i!=j && !u[i][j] && a[i] >= a[j]){
				u[i][j]=u[j][i]=true;
				pw.println((i+1)+" "+(j+1));
			}
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}