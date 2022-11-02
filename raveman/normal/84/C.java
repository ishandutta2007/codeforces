import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class Main {     
        public class C implements Comparable<C>{
                public int x;
                public int r;
                public int p;
                C(int _x,int _r,int _p){
                        x=_x;
                        r=_r;
                        p=_p;
                }
                public int compareTo(C s){
                        if(x==s.x) return 0;
                        if(x<s.x) return -1;
                        return 1;
                }
        }
        public void run () throws Exception {
                Scanner in = new Scanner(System.in);//new File("input.txt"));
                PrintWriter pw = new PrintWriter(System.out);//;//new  File("output.txt"));
                
                int n = in.nextInt();
                int[] r = new int[n];
                for(int i=0;i<n;i++) r[i]=-1;
                
                C[] q = new C[n];
                for(int i=0;i<n;i++){
                        int x = in.nextInt();
                        int rr = in.nextInt();
                        q[i] = new C(x,rr,i);
                }
                        
                Arrays.sort(q);
                
                int m = in.nextInt();
                for(int i=1;i<=m;i++){
                        int x = in.nextInt();
                        long y = in.nextInt();
                        
                        int a = 0;
                        int b = n-1;
                        int best = n-1;
                        while(a<=b){
                                int s = (a+b)/2;
                                if(q[s].x >= x){
                                        best = s;
                                        b = s - 1;
                                }else a = s + 1;
                        }
                        for(int dx=-10;dx<=10;dx++){
                                int pos = best + dx;
                                if(pos>=0 && pos<n && r[q[pos].p]==-1){
                                        if((q[pos].x - x)*(q[pos].x - x) + y *y <= q[pos].r*q[pos].r)
                                                r[q[pos].p] = i;
                                }
                        }
                }
                
                int res =0 ;
                for(int i=0;i<n;i++) if(r[i]!=-1) res++;
                pw.println(res);
                for(int i=0;i<n;i++){
                        if(i>0) pw.print(" ");
                        pw.print(r[i]);
                }
                pw.println();

                pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }

}