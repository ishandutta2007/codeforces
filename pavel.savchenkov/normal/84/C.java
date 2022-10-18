import java.io.*;
import java.util.*;


public class Main {
    static int[] x=new int[10001];
    static int[] r=new int[10001];
    static int[] ind=new int[10001];//   
    static int[] s=new int[10001];//
    static int h;// 
    static int j=0;
    
    
    static void heapify(int i) {// 
        int f;
     do {
         if (2*i+1<=h)
             if ((x[2*i+1]>x[i])&(x[2*i+1]>x[2*i])) {
              f=x[2*i+1]; x[2*i+1]=x[i]; x[i]=f;
              f=r[2*i+1]; r[2*i+1]=r[i]; r[i]=f;
              f=ind[2*i+1]; ind[2*i+1]=ind[i]; ind[i]=f;
              i=2*i+1;
              continue;
             }       
         if (2*i<=h)
             if (x[2*i]>x[i]) {
              f=x[2*i]; x[2*i]=x[i]; x[i]=f;
              f=r[2*i]; r[2*i]=r[i]; r[i]=f;
              f=ind[2*i]; ind[2*i]=ind[i]; ind[i]=f;
              i=2*i;
              continue;
             }
         break;         
        }
     while (i<=h);    
    }
    
    static void binary(int a,int b,int i) {//       
     int le=1; int ri=h; int g1;
     if (a>x[h]) {ok(a,b,h,i); return;}
     if (a<x[1]) {ok(a,b,1,i);return;}
     do {
      g1=le+(ri-le)/2;
      if (ri-le<=1) {ok(a,b,le,i); ok(a,b,ri,i); break;}
      
      if (x[g1]==a) {ok(a,b,g1,i);break;} else
          if (x[g1]<a) le=g1; else ri=g1;
      
      
     } while (le<=ri);
     
     
    }
    
    static void ok(int a,int b,int k,int i) {//  (a,b)   (x,r);
                                             //i -  ; k -      
     double a1=a,b1=b;
      if ( Math.sqrt(b*b + (a-x[k])*(a-x[k]))<=r[k]&s[ind[k]]==0) {s[ind[k]]=i;j++;}   
    }
 
    public static void main(String[] args)  throws FileNotFoundException {
     Scanner in=new Scanner(System.in);
     int n=in.nextInt();
     for (int i=1;i<=n;i++) {
         x[i]=in.nextInt();
         r[i]=in.nextInt();
         ind[i]=i;
     }
     h=n;
     for (int i=n;i>=1;i--) {
         heapify(i);
     }

          
     while (h>1) {
         int f;
         f=x[1];x[1]=x[h]; x[h]=f;
         f=r[1];r[1]=r[h]; r[h]=f;
         f=ind[1];ind[1]=ind[h]; ind[h]=f;
         h--;
         heapify(1);
     }//x  r 
     h=n;
     

     
     int m=in.nextInt();
     int a,b;
     for (int i=1;i<=m;i++) {
      a=in.nextInt();
      b=in.nextInt();
      binary(a,b,i);//    (a,b); i -  
     }
     
     System.out.println(j);
     for (int i=1;i<=n;i++) 
         if (s[i]==0) System.out.print("-1 "); else System.out.print(s[i]+" ");
     
    }

}