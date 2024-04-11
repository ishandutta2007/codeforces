import java.util.*;
import java.io.*;
import java.math.*;
import java.text.*;
public class Main
{
    static public void main(String[] args)
    {
        Scanner cin=new Scanner(System.in);
        int t=cin.nextInt();
        int m=cin.nextInt();
        int a[]=new int[m+1];
        a[m]=t+1;
        int tot=0;
        boolean ex[]=new boolean[t+1];
        while(t-->0)
        {
            String op=cin.next();
            if(op.charAt(0)=='a')
            {
                int n=cin.nextInt();
                boolean isok=false;
                for(int i=0;i<=m;i++)
                {
                    if(a[i]>0 || (i>0 && a[i-1]==0))continue;
                    int cnt=0;
                    for(int j=i;j<=m;j++)
                    {
                        if(a[j]==0)cnt++;
                        else break;
                    }
                    if(cnt>=n)
                    {
                        ex[++tot]=true;
                        for(int j=i,k=1;k<=n;j++,k++)
                            a[j]=tot;
                        isok=true;
                        break;
                    }
                }
                if(isok)System.out.println(tot);
                else System.out.println("NULL");
            }
            else if(op.charAt(0)=='e')
            {
                int x=cin.nextInt();
                if(x<=0 || x>tot || !ex[x])System.out.println("ILLEGAL_ERASE_ARGUMENT");
                else
                {
                    ex[x]=false;
                    for(int i=0;i<m;i++)
                        if(a[i]==x)a[i]=0;
                }
            }
            else
            {
                int b[]=new int[m];
                int cur=0;
                for(int i=0;i<m;i++)
                    if(a[i]>0)b[cur++]=a[i];
                for(int i=0;i<m;i++)
                    a[i]=b[i];
            }
        }
    }
}