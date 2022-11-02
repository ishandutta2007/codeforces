import java.io.PrintWriter;
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

            int n,m,x;
            n=in.nextInt();
            m=in.nextInt();
            x=in.nextInt();
            String s[] = new String[n];
            for(int i=0;i<n;i++)
            	s[i] = in.next();
            int sm[] = new int[26];
            int SM[] = new int[26];
            boolean has = false;
            for(int i=0;i<n;i++)
            	for(int j=0;j<m;j++)
            		if(s[i].charAt(j)=='S') has =true;
            for(int i=0;i<26;i++)
            	sm[i]=SM[i]=-1;
            for(int i=0;i<n;i++)
            	for(int j=0;j<m;j++){
            		char c = s[i].charAt(j);
            		if(c=='S') continue;
            		sm[c-'a'] = 0;
            
            		for(int ii=0;ii<n;ii++)
                    	for(int jj=0;jj<m;jj++)if(s[ii].charAt(jj)=='S')
                    		if((ii-i)*(ii-i)+(jj-j)*(jj-j)<=x*x) SM[c-'a']=0;
                   }
            int q;
            q=in.nextInt();
            String t = in.next();
            int res = 0;
            for(int i=0;i<q;i++){
            	char c = t.charAt(i);
            	if(c<='z' && c>='a' && sm[c-'a']==-1){res=-1;break;}
            	if(c<='z' && c>='a' ) continue;
            	if(sm[c-'A']==-1 || !has) {res=-1;break;}
            	if(SM[c-'A']==-1) res++;
            }
            pw.println(res);
            pw.close();
        }
        public static void main(String[] args) throws Exception {
                new Main ().run();
        }
}