#include<bits/stdc++.h>
using namespace std;
const int MAXN=2005;
int a[MAXN],idx[MAXN];
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)
        idx[i]=i;
    sort(idx+1,idx+n+1,[](int x,int y){return a[x]>a[y];});
    int sum=0;
    vector<int> loc(1,0);
    for(int i=1;i<=k;i++)
        loc.push_back(idx[i]),sum+=a[idx[i]];
    sort(loc.begin(),loc.end());
    printf("%d\n",sum);
    for(int i=1;i<k;i++)
        printf("%d ",loc[i]-loc[i-1]);
    printf("%d\n",n-loc[k-1]);
    return 0;
}