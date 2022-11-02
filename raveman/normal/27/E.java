import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	
	public int getP(int pos){
		if(pos==0) return 2;
		if(pos==1) return 3;
		if(pos==2) return 5;
		if(pos==3) return 7;
		if(pos==4) return 11;
		if(pos==5) return 13;
		if(pos==6) return 17;
		if(pos==7) return 19;
		if(pos==8) return 23;
		return 29;
	}
	public BigInteger solve(int n,int to,int pos){
		if(n==1) return BigInteger.ONE;
		BigInteger res = new BigInteger("1000000000000000000");
		for(int i=2;i<=to;i++)if((n%i)==0){
			BigInteger temp = solve(n/i,i,pos+1);
			for(int j=1;j<i;j++)
				temp = temp.multiply(new BigInteger(""+getP(pos)));
			if(temp.compareTo(res) < 0)
				res=temp;
		}
		return res;
	}
	
	public void run () throws Exception {
		Scanner in = new Scanner(System.in);
		//Scanner in = new Scanner(new File("input.txt"));
		PrintWriter pw = new PrintWriter(System.out);

		int n = in.nextInt();
		
		pw.println(solve(n,61,0));
		
		in.close();
		pw.close();
	}
	public static void main(String[] args) throws Exception {
		new Main ().run();
	}

}