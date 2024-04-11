import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public int n,m;
	public int[] a,b;
	public int[] c;

	public boolean inter(int i1,int i2){
		int A = a[i1];
		int B = b[i1];
		if(A>B){
			int C = A;
			A=B;
			B=C;
		}
		
		if(a[i2] > A && a[i2] < B && !(b[i2]>=A && b[i2]<=B)) return true;
		if(b[i2] > A && b[i2] < B && !(a[i2]>=A && a[i2]<=B)) return true;
		return false;
	}
	public boolean dfs(int ver,int col){
		if(c[ver]>0) return c[ver]==col;
		c[ver] = col;
	
		for(int i=0;i<m;i++)
			if(inter(ver,i))
				if(!dfs(i,3-col))
					return false;
		return true;
	}
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		n=in.nextInt();m=in.nextInt();
		a = new int[m]; b = new int [m];
		for(int i=0;i<m;i++){
			a[i] = in.nextInt();
			b[i] = in.nextInt();
		}
		c=new int[m];
		boolean s = false;
		for(int i=0;i<m;i++)if(c[i]==0){
			if(!dfs(i,1)){
				pw.println("Impossible");
				s=true;
				break;
			}
		}
		
		if(!s){
			for(int i=0;i<m;i++)
				pw.print(c[i]==1?'i':'o');
		}
			
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}