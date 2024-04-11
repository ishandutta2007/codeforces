import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	
	
	public int go(int v,int n){
		if(n==2) return v;
		if(n==v) return 2;
		return n;
	}
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		int n = in.nextInt();
		int m = in.nextInt();
		int v = in.nextInt();
		

		int mx = 1 + (n-1) *(n-2)/2;
		if(m<n-1 || mx < m) pw.println(-1);
		else{
			for(int i=0;i<n-1;i++)
				pw.println(go(v,i+1)+" "+go(v,i+2));
			m -= (n-1);
			for(int i=1;i<n;i++){
				for(int j=i+2;j<n;j++)
					if(m>0){
						pw.println(go(v,i+1)+" "+go(v,j+1));
						m--;
					}
				if(m==0) break;
			}
		}

		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}