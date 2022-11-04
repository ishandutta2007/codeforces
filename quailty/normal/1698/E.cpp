#include<bits/stdc++.h>
using namespace std;
const int MAXN=200005;
const int Mod=998244353;
int solve()
{
    int n,s;
    scanf("%d%d",&n,&s);
    vector<int> a(n),p(n,-1),q(n,-1);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    {
        int b;
        scanf("%d",&b);
        if(b>0)p[a[i]-1]=b-1,q[b-1]=a[i]-1;
    }
    int res=1,tot=0,cnt=0;
    for(int i=n-1,j=n-1;i>=0;i--)
    {
        if(p[i]>=0)
        {
            if(p[i]<i-s)return 0*printf("0\n");
        }
        else
        {
            cnt++;
            while(j>=0 && j>=i-s)tot+=(q[j]<0),j--;
            res=1LL*res*(tot-cnt+1)%Mod;
        }
    }
    return 0*printf("%d\n",res);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}