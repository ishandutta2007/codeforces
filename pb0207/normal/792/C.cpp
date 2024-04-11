#include <bits/stdc++.h>

using namespace std;
const int maxn=1e5+5;
char a[maxn];
int b[maxn];
char ans[maxn];
int check()
{
    int res=0, i=0;
    
    for(; a[i] ; i++)if(b[i]!=-1)if(a[i]!='0')break;
    for(; a[i]; i++)if(b[i]!=-1)res++;
    if(res==0)res=1;
    return res;
}
int main()
{
    scanf("%s", a);
    int i, j, k;
    int sum=0;
    for(i=0; a[i]; i++)sum+=a[i]-'0';
    for(i=0; a[i]; i++)b[i]=(a[i]-'0')%3;
    sum%=3;
    if(sum==0)
    {
        for(i=0; a[i] && a[i]=='0'; i++);
        if(!a[i])printf("0\n");
        else for(; a[i]; i++)printf("%c", a[i]);
        return 0;
    }
    else if(sum==1)
    {
        int l1=0, l2=0, x;
        int len=strlen(a);
        for(i=len-1; i>=0; i--)if(b[i]==1){b[i]=-1;break;}
        if(i>=0)
        {
            l1=check();
            b[i]=1;
        }
            j=0;
            
            for( k=len-1; k>=0; k--)
            {
                if(b[k]==2)
                {

                    b[k]=-1;
                    j++;
                    if(j==2)break;
                    x=k;
                }
            }
            if(k>=0)
            {
             l2=check(); 
            }
 //           cout<<l1<<" "<<l2<<endl;
            if(l2<l1)
            {
       //     cout<<x<<" "<<k<<" "<<j<<endl;
            if(j==2)b[k]=b[x]=1, b[i]=-1;
            else if(j==1)b[i]=-1, b[x]=1;
            else if(j==0)b[i]=-1;
            }

    }
    else if(sum==2)
    {
        int len=strlen(a);
        int x, flag=0, l1=0, l2=0;
        for(i=len-1; i>=0; i--)
        {
            if(b[i]==2)
            {
                b[i]=-1;
                break;
            }
        }
        if(i>=0)
        {
        l1=check();
        b[i]=2;
        }
            j=0;
            
            for( k=len-1; k>=0; k--)
            {
                if(b[k]==1)
                {

                    b[k]=-1;
                    j++;
                    if(j==2)break;
                    x=k;
                }
            }
            if(k>=0)
            {
             l2=check(); 
            }
      //      cout<<l1<<" "<<l2<<endl;
            if(l2<l1)
            {
       //     cout<<x<<" "<<k<<" "<<j<<endl;
            if(j==2)b[k]=b[x]=1, b[i]=-1;
            else if(j==1)b[i]=-1, b[x]=1;
            else if(j==0)b[i]=-1;
            }

    
    }
    j=0;
    for(i=0; a[i]; i++)if(b[i]!=-1)ans[j++]=a[i];
    ans[j]='\0';
//    printf("%s\n", ans);
    for(i=0; ans[i] && ans[i]=='0'; i++);
    if(!ans[i])
    {
        if(i==0)return 0*printf("-1\n");
        else return 0*printf("0\n");
    }
    for(; ans[i]; i++)printf("%c", ans[i]);
    return 0;
}