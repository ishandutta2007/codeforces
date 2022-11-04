#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
ll peg[200005];
map<ll,int>x;
int get(int a,ll l,int d)
{
    if(d==0)return (*--x.upper_bound(peg[a]+l)).second;
    else return (*x.lower_bound(peg[a]-l)).second;
}
int solve(int a,ll l,int d,int la)
{
    if(l==0)return a;
    int nex=get(a,l,d);
    if(nex==a && la==a)return a;
    if(nex==la && l>=2*(abs(peg[nex]-peg[a])))solve(a,l%(2*abs(peg[nex]-peg[a])),d,la);
    else solve(nex,l-abs(peg[nex]-peg[a]),d^1,a);
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&peg[i]);
        x[peg[i]]=i;
    }
    int a;
    ll l;
    while(m--)
    {
        scanf("%d%I64d",&a,&l);
        printf("%d\n",solve(a,l,0,0));
    }
    return 0;
}