#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=100005;
int k[MAXN],l[MAXN],id[MAXN];
int main()
{
    int n,f;
    scanf("%d%d",&n,&f);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&k[i],&l[i]),id[i]=i;
    sort(id+1,id+n+1,[](int a,int b)
    {
        return min(2*k[a],l[a])-min(k[a],l[a])>min(2*k[b],l[b])-min(k[b],l[b]);
    });
    ll res=0;
    for(int i=1;i<=f;i++)
        res+=min(2*k[id[i]],l[id[i]]);
    for(int i=f+1;i<=n;i++)
        res+=min(k[id[i]],l[id[i]]);
    return 0*printf("%lld",res);
}