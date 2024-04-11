#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mod 1000000007
#define reset(s,val) memset(s,val,sizeof(s))
#define eps 1e-9
#define pi acos(-1)
#define sqr(x) (x)*(x)
#define two(x) (1<<(x))

long long n,m,lis[300005],pos[300005],val,a,b;
set<long long> foe[300005];

int main( ){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    For(i,0,n)
    {
        cin>>val;
        lis[i]=val;
        pos[val]=i;
    }
    while(m--)
    {
        cin>>a>>b;
        a=pos[a];
        b=pos[b];
        foe[a].insert(b);
        foe[b].insert(a);
    }
    long long l=0;
    long long ans=1;
    For(r,1,n)
    {
        if(foe[r].empty())
        {
            ans+=r-l+1;
            continue;
        }
        auto it = foe[r].upper_bound(r);
        if(it==foe[r].begin()) ans+=r-l+1;
        else
        {
            it--;
            l=max(l,(*it)+1);
            ans+=r-l+1;
        }
        //cout<<l<<' '<<r<<endl;
    }
    cout<<ans;
}