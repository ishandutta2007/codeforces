import java.io.*;
import java.util.*;
public class Main {

    public static void main(String[] args) {
	    Scanner s=new Scanner(System.in);
	    int n=s.nextInt();
	    int m=s.nextInt();
	    String[] str=new String[n];
	    s.nextLine();
	    for(int i=0;i<n;i++)
	        str[i]=s.nextLine();
	    int mnn=n+1,mxn=-1,mnm=m+1,mxm=-1;
	    for(int i=0;i<n;i++)
	        for(int j=0;j<m;j++){
	            if(str[i].charAt(j)=='B'){
	                mnn=Integer.min(mnn,i);
	                mxn=Integer.max(mxn,i);
                    mnm=Integer.min(mnm,j);
                    mxm=Integer.max(mxm,j);
                }
            }
        System.out.print((mnn+mxn)/2+1);
        System.out.print(' ');
        System.out.print((mnm+mxm)/2+1);
    }
}