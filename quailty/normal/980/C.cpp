#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
const int MAXP=265;
int p[MAXN],q[MAXN],t[MAXP],b[MAXP];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&p[i]);
    for(int i=0;i<256;i++)t[i]=1;
    for(int i=1;i<=n;i++)
    {
        if(b[p[i]])
        {
            for(int j=0;j<=p[i];j++)
                if(t[j])q[i]=j;
        }
        else
        {
            int l=p[i];
            for(int j=p[i];j>=0 && j>=p[i]-k+1;j--)if(t[j])l=j;
            for(int j=p[i];j>l;j--)t[j]=0;
            for(int j=p[i];j>=l;j--)b[j]=1;
            q[i]=l;
        }
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",q[i]," \n"[i==n]);
    return 0;
}