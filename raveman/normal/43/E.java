import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class Main {
		Scanner in;
		PrintWriter pw;
		
		public void run () throws Exception {
            in = new Scanner(System.in);
            pw = new PrintWriter(System.out);

            int n = in.nextInt(); int s = in.nextInt();
            int[][] v,t;
            v = new int[n][];
            t = new int[n][];
            
            for(int i=0;i<n;i++){
            	int k =in.nextInt();
            	v[i] = new int[k];
            	t[i] = new int[k];
            	for(int j=0;j<k;j++){
            		v[i][j] = in.nextInt();
            		t[i][j] = in.nextInt();
            	}
            }
            
            int res = 0;

            for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(j!=i){
            	int d1 = 0;
            	int T1 = 0;
            	
            	for(int i1=0;i1<v[i].length; i1++){
            		int V1 = v[i][i1];
            		
            		int d2 = 0;
            		int T2 = 0;
            		for(int i2=0;i2<v[j].length; i2++){
            			int V2 = v[j][i2];
            			
            			int c = d2-d1-T2*V2+T1*V1;
            			int z = V1 - V2;
            			if(z>0 && c>0 && c>z*T1 && c>z*T2 && c<=z*(T1+t[i][i1]) && c<=z*(T2+t[j][i2])){
            				int v1n = V1;
            				if(c==z*(T1+t[i][i1])){
            					if(i1==v[i].length-1)continue;
            					v1n = v[i][i1+1];
            				}
            				
            				int v2n = V2;
            				if(c==z*(T2+t[j][i2])){
            					if(i2==v[j].length-1)continue;
            					v2n = v[j][i2+1];
            				}
            				
            				if(v1n > v2n) res++;
            			}
            			
            			T2 += t[j][i2];
            			d2 += t[j][i2] * v[j][i2];
            		}
            		
            		T1 += t[i][i1];
            		d1 += t[i][i1]*v[i][i1];
            	}
            }
            
            pw.println(res);
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main().run();
        }
}