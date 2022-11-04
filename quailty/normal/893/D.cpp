#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
int a[MAXN],pr[MAXN],mx[MAXN];
int L[MAXN],R[MAXN];
int main()
{
    int n,d;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pr[i]=pr[i-1]+a[i];
    }
    mx[n]=pr[n];
    for(int i=n-1;i>=1;i--)
        mx[i]=max(mx[i+1],pr[i]);
    if(mx[1]>d)return 0*printf("-1\n");
    int cnt=0;
    for(int i=1;i<=n;i++)if(a[i]==0)
        cnt++,L[cnt]=0-pr[i],R[cnt]=d-mx[i];
    for(int i=1;i<=cnt;i++)
    {
        L[i]=max(L[i],L[i-1]);
        if(L[i]>R[i])return 0*printf("-1\n");
    }
    int res=-1;
    for(int i=0;i<=cnt;res++)
    {
        int now=R[i];
        while(i<=cnt && L[i]<=now)i++;
    }
    return 0*printf("%d\n",res);
}