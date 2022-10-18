    import java.io.*;
    import java.util.*;


    public class Main {
        static long nod(long a,long b) {
           
            if (b==0) return a; else
                return nod(b,a%b);
        }
       
        static long nok(long a,long b) {
            return a*b/nod(a,b);
        }
     
        public static void main(String[] args) {
           Scanner in=new Scanner(System.in);
           long a=in.nextLong();
           long b=in.nextLong();
           long m=0;          
           m=nod(a,b);
           a=a/m; b=b/m;
           if (Math.abs(a-b)==1) {System.out.println("Equal"); return;}
           if (a<b) System.out.println("Dasha"); else System.out.println("Masha");
           
        }

    }