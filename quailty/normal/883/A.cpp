#include<bits/stdc++.h>
#define sc scanf
#define pr printf
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;

typedef double db;
typedef unsigned long long ll;

const int N=1e5+5;

ll t[N];

int main()
{
    ll n,m,a,d;
    sc("%llu%llu%llu%llu",&n,&m,&a,&d);
    for(int i=1;i<=m;i++) sc("%llu",&t[i]);
    ll dd=(d/a+1)*a;///
    ll ans=0,now=0,id=1;
    // now -> last close time
    while(1)
    {
        ll pre=(now/a+1)*a;///
        if(id>m)
        {
            if(pre>a*n) break;
            ans+=(a*n-pre)/dd+1;///
            break;
        }
        else
        {
            if(t[id]<pre || pre>a*n) now=t[id];
            else
            {
                ll time=(min(t[id],n*a)-pre)/dd;///
                ans+=time;
                now=pre+time*dd;
            }
            now+=d;
            ans++;
            while(id<=m && t[id]<=now) id++;
        }
    }
    pr("%llu\n",ans);
    return 0;
}