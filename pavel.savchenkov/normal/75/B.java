import java.io.*;
import java.util.*;

public class Main {
    static String my;
    static String[] name=new String[200];
    static int[] fr=new int[200]; 
    static int names=1,h;
   
    static void add(String s,int x) {
        for (int i=1;i<names;i++)
            if (name[i].equals(s)) {fr[i]+=x;return;}
        name[names]=s;
        fr[names]=x;
        names++;
    }
    
    static void heapify(int i) {
        int g;
        String s;
        
      do { 
       if (2*i+1<=h) 
        if ((fr[2*i+1]<fr[i])&fr[2*i+1]<fr[2*i]) {
         g=fr[i]; fr[i]=fr[2*i+1]; fr[2*i+1]=g;
         s=name[i]; name[i]=name[2*i+1]; name[2*i+1]=s;
         i=2*i+1;
         continue;
        }  
          
       if (2*i<=h) 
        if (fr[2*i]<fr[i]) {
         g=fr[i]; fr[i]=fr[2*i]; fr[2*i]=g;
         s=name[i]; name[i]=name[2*i]; name[2*i]=s;
         i=2*i;
         continue;
        }  
       
       break;
      }  while (1==1);
              
    }
    
    
    static boolean ok() {
        for (int i=1;i<names-1;i++)
            if (fr[i]==fr[i+1]&name[i].compareTo(name[i+1])>=0) return false;
        return true;
    }
            
            
    public static void main(String[] args) throws FileNotFoundException {
      Scanner in=new Scanner(System.in);
      my=in.nextLine();
      int n=in.nextInt();
      int j,j1,j2,x;
      String s=in.nextLine();
      String s1="",s2="",s3="";
      for (int i=1;i<=n;i++) {
          s=in.nextLine();
          s1="";s2="";s3="";
          
           for (j=1;j<=s.length();j++)
               if (s.charAt(j-1)!=' ') s1+=s.charAt(j-1); else break;
          
           for (j1=j+1;j1<=s.length();j1++)
               if (s.charAt(j1-1)!=' ') s2+=s.charAt(j1-1); else break;
           
           if (!s2.equals("likes")) j1+=3;
          
           for (j2=j1+1;j2<=s.length();j2++)
               if (s.charAt(j2-1)!=39) s3+=s.charAt(j2-1); else break;// 
           
           if (!s1.equals(my)&!s3.equals(my)) {add(s1,0);add(s3,0);continue;}
          
           if (s2.equals("posted")) x=15; else if (s2.equals("commented")) x=10; else x=5;
          
          if (s1.equals(my)) add(s3,x); else add(s1,x); 
          
      }//

      h=names-1;
      //if (my.equals("ou")) for (int i=1;i<=names-1;i++) System.out.println("0 "+name[i]+" "+fr[i]);
      for (int i=h;i>=1;i--) heapify(i);
     // if (my.equals("ou")) for (int i=1;i<=names-1;i++) System.out.println("1 "+name[i]+" "+fr[i]);
      do {
       int g;
       String r;
        g=fr[1]; fr[1]=fr[h]; fr[h]=g;
        r=name[1]; name[1]=name[h]; name[h]=r;
        h--;
        heapify(1);
       } while (h>1);
      
      do {
          String r;
      for (int i=1;i<names-1;i++)
          if (fr[i]==fr[i+1]&name[i].compareTo(name[i+1])>0) {r=name[i]; name[i]=name[i+1]; name[i+1]=r;}
      } while (!ok());        
      
    //  if (my.equals("ou")) for (int i=1;i<=names-1;i++) System.out.println(name[i]+" "+fr[i]); else
      for (int i=1;i<=names-1;i++)
          System.out.println(name[i]);

    }

}