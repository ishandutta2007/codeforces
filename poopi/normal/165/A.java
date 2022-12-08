import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigDecimal;
import java.util.Scanner;

public class Code1 {

	public static void main (String[] args){
		
			
			Scanner scan = new Scanner(System.in);
			int n= Integer.parseInt(scan.nextLine());
					
			
            int [][]ab=new int[n][2];
            int []a=new int[n];
            int []b=new int[n];
            int []c=new int[n];
            int []d=new int[n];
			int sum=0;
			
				for(int i=0;i<n;i++){
					// Scanner scan1 = new Scanner(System.in);
					 int t=0;
					 
					 String a1=scan.nextLine();
					 for (int k=0;k<a1.length();k++){
						 if(a1.charAt(k)==' ')
							 t=k;
							  
					 }
					
					 String s1=a1.substring(0,t);
					 String s2=a1.substring(t+1);
					 //Scanner scan2 = new Scanner(System.in);
					 //int b1=scan2.nextInt();
					ab[i][0]=Integer.parseInt(s1);
					ab[i][1]=Integer.parseInt(s2);
					//System.out.println(b1); 
					 
			}
				for (int i=0;i<n;i++){
					for(int j=0;j<n;j++){
						if (ab[i][0]==ab[j][0] && ab[i][1]>ab[j][1]){
								a[i]=a[i]+1;
							
						}
						if(ab[i][0]==ab[j][0] && ab[i][1]<ab[j][1]){
						
								b[i]=b[i]+1;
							
						}
						if(ab[i][1]==ab[j][1] && ab[i][0]>ab[j][0]){
						
								c[i]=c[i]+1;
							
						}
						if(ab[i][1]==ab[j][1] && ab[i][0]<ab[j][0]){
							d[i]=d[i]+1;
							
						}
					}
				}
				for (int i=0;i<n;i++){
					if(a[i]>0 && b[i]>0 && c[i]>0 && d[i]>0)
						sum=sum+1;	
				}
		    System.out.println(sum);		
	}	
}