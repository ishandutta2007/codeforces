#include<bits/stdc++.h>
using namespace std;
const int MAXN=1005;
inline int query(int n,int a[MAXN])
{
    static char buf[MAXN];
    for(int i=0;i<n;i++)
        buf[i]=(a[i] ? 'T' : 'F');
    printf("%s\n",buf);
    fflush(stdout);
    int res;
    scanf("%d",&res);
    if(res==n)exit(0);
    return res;
}
int cur[MAXN],res[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)cur[i]=1;
    int ans_a=query(n,cur);
    for(int i=0;i<n;i++)cur[i]=~i&1;
    int ans_b=query(n,cur);
    for(int c=0;c<n/3;c++)
    {
        for(int i=0;i<n;i++)cur[i]=1;
        cur[2*c]=cur[2*c+1]=0;
        int now=query(n,cur);
        if(now==ans_a)
        {
            for(int i=0;i<n;i++)cur[i]=~i&1;
            cur[2*c]^=1,cur[2*c+1]^=1,cur[n/3*2+c]^=1;
            now=query(n,cur);
            if(now==ans_b-3)res[2*c]=1,res[2*c+1]=0,res[n/3*2+c]=cur[n/3*2+c]^1;
            else if(now==ans_b-1)res[2*c]=1,res[2*c+1]=0,res[n/3*2+c]=cur[n/3*2+c];
            else if(now==ans_b+1)res[2*c]=0,res[2*c+1]=1,res[n/3*2+c]=cur[n/3*2+c]^1;
            else res[2*c]=0,res[2*c+1]=1,res[n/3*2+c]=cur[n/3*2+c];
        }
        else
        {
            res[2*c]=res[2*c+1]=(now<ans_a);
            for(int i=0;i<n;i++)cur[i]=(i!=n/3*2+c);
            res[n/3*2+c]=(query(n,cur)<ans_a);
        }
    }
    for(int c=n/3*3;c<n;c++)
    {
        for(int i=0;i<n;i++)cur[i]=(i!=c);
        res[c]=(query(n,cur)<ans_a);
    }
    query(n,res);
    return 0;
}