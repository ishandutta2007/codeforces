import java.io.File;
import java.io.PrintWriter;
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
		for(int i=0;i<n;i++)
			for(int j=i+1;j<n;j++){
				boolean good = true;
				
				int c = 0;
				while(i+c<=j-c){
					if(a[i+c]!=j-c+1){good=false;break;}
					if(a[j-c]!=i+c+1){good=false;break;}
					c++;
				}
				if(good) for(int k=0;k<i;k++)if(a[k]!=k+1){good=false;break;}
				if(good) for(int k=j+1;k<n;k++)if(a[k]!=k+1){good=false;break;}
				
				if(good){
					pw.println((i+1)+" "+(j+1));
					pw.close();
					return;
				}
			}
		pw.println("0 0");
		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}