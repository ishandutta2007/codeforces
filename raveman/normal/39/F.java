import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
		Scanner in;
		PrintWriter pw;
		
		public void run () throws Exception {
            in = new Scanner(System.in);
            pw = new PrintWriter(System.out);
            
            int n = in.nextInt();
            int m = in.nextInt();
            int k = in.nextInt();
            
            int[] d = new int[m];
            for(int i=0;i<m;i++)
            	d[i] = in.nextInt();
            
            int[] p = new int[k];
            for(int i=0;i<k;i++)
            	p[i] = in.nextInt();
            
            List<Integer> res = new ArrayList<Integer>(); 
            int best = k + 1;
            
            for(int i=0;i<m;i++){
            	int num = 0;
            	
            	for(int j=0;j<k;j++) if(p[j]%d[i]==0) num++;
            	
            	if(num < best){
            		best = num;
            		res.clear();
            	}
            	if(num==best) res.add(i+1);
            }
            
            pw.println(res.size());
            for(int i=0;i<res.size();i++){
            	if(i>0) pw.print(" ");
            	pw.print(res.get(i));
            }
            pw.println();

            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}