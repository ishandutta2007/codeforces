#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<cassert>
#include<string>
using namespace std;
#define pb push_back
#define mp make_pair
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
const int M=300000;
LL c[2][M+10],ans;
int n;
void add(LL c[],int x,int y){for(;x<=M;x+=x&(-x))c[x]+=y;}
LL get(LL c[],int x){LL s=0;for(;x;x-=x&(-x))s+=c[x];return s;}
int main()
{
    scanf("%d",&n);
    LL sum=0;
    rep(i,n)
    {
        int x;scanf("%d",&x);
        ans+=1ll*(i-1)*x-get(c[0],x);
        ans+=sum;
        for(int j=1;j<=M/x;j++)ans+=get(c[1],j*x-1)*x;
        ans-=1ll*(i-1)*x*(M/x);
        add(c[1],x,1);
        sum+=x;
        for(int j=x;j<=M;j+=x)add(c[0],j,x);
        printf("%lld%c",ans," \n"[i==n]);
    }
    return 0;
}