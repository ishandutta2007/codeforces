#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=25;
struct node
{
    ll a,b;
    bool operator < (const node &t)const
    {
        return b>t.b;
    }
}p[MAXN];
int main()
{
    ll n,m;
    scanf("%I64d%I64d",&n,&m);
    for(int i=0;i<m;i++)
        scanf("%I64d%I64d",&p[i].a,&p[i].b);
    sort(p,p+m);
    ll res=0;
    for(int i=0;i<m;i++)
    {
        if(n>=p[i].a)res+=p[i].a*p[i].b,n-=p[i].a;
        else res+=n*p[i].b,n=0;
    }
    printf("%I64d",res);
    return 0;
}