import java.io.*;
import java.util.*;

public class Main {
    static int n,hh;
    static int[] w=new int[1000001];
    static int[] h=new int[1000001];
    static int[] ind=new int[1000001];
    static int[] sol=new int[1000001];
    static int[] pr=new int[1000001];
    
    static void heapify(int i) {
        int g;
        do {
         if (2*i+1<=hh) 
             if (w[2*i+1]>w[i]&w[2*i+1]>w[2*i]) {
                 g=w[i]; w[i]=w[2*i+1]; w[2*i+1]=g;
                 g=h[i]; h[i]=h[2*i+1]; h[2*i+1]=g;
                 g=ind[i]; ind[i]=ind[2*i+1]; ind[2*i+1]=g;
                 i=2*i+1;
                 continue;
             }
          if (2*i<=hh) 
             if (w[2*i]>w[i]) {
                 g=w[i]; w[i]=w[2*i]; w[2*i]=g;
                 g=h[i]; h[i]=h[2*i]; h[2*i]=g;
                 g=ind[i]; ind[i]=ind[2*i]; ind[2*i]=g;
                 i=2*i;
                 continue;
             }
            
         break;   
        } while (1==1);
    }
    
    public static void main(String[] args) throws FileNotFoundException {
       Scanner in=new Scanner(/*new FileReader("input.txt"));*/System.in);
       n=in.nextInt();
       int w2,h2;
       int w1=in.nextInt();
       int h1=in.nextInt();
       int[] a=new int[n+2];
       int j=0,max=1;
       for (int i=1;i<=n;i++) {           
           w2=in.nextInt();
           h2=in.nextInt();
           if (w2>w1&h2>h1) {j++;w[j]=w2;h[j]=h2;ind[j]=i;}
       }
       n=j;
       hh=n;
       for (int i=n;i>=1;i--)
           heapify(i);
       do {
       w2=w[1]; w[1]=w[hh]; w[hh]=w2;
       w2=h[1]; h[1]=h[hh]; h[hh]=w2;
       w2=ind[1]; ind[1]=ind[hh]; ind[hh]=w2;
       hh--;
       heapify(1);
       }
       while (hh>=1);//
       
       //if (w1==6134) {for (int i=1;i<=n;i++) System.out.println(w[i]+" "+h[i]+" "+ind[i]);}
       
       a[1]=1;
       int maxj=0;
       for (int i=2;i<=n;i++) {
           a[i]=1;
            for (j=1;j<i;j++)               
                if (h[j]<h[i]&a[maxj]<a[j]&w[j]!=w[i]) maxj=j;          
           a[i]=a[maxj]+1;
           pr[i]=maxj;
           if (a[i]>a[max]) max=i;
           maxj=0;
       }
       if (n==0) a[max]=0;      
       System.out.println(a[max]);
       if (a[max]==1) {System.out.println(ind[1]);return;}
       
       //if (w1==6134) { System.out.println();for (int i=1;i<=n;i++) System.out.print("a["+i+"]="+a[i]+" ");System.out.println();}
       
       int q=max;
       for (int i=1;i<=a[max];i++) {           
           sol[i]=ind[q];
           q=pr[q];
       }            
       
       for (int i=a[max];i>=1;i--)
           System.out.print(sol[i]+" ");
    }

}