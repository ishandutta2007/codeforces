#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<bitset>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
int nxt[200010],p[100010];
void work(int n)
{
    if(n<0)return;
    int x=nxt[n]-n;
    for(int i=x;i<=n;i++)p[n-i+x]=i;
    work(x-1);
}
int main()
{
    int x=(int)sqrt(1e5)+1;
    rep(i,x)for(int j=(i-1)*(i-1)+1;j<=i*i;j++)nxt[j]=i*i;
    int T;
    for(scanf("%d",&T);T--;)
    {
        int n;
        scanf("%d",&n);
        work(n-1);
        rep(i,n)printf("%d%c",p[i-1]," \n"[i==n]);
    }
    return 0;
}