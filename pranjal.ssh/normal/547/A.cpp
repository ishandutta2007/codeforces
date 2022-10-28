#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<vector<ll> > vvi;
typedef pair<ll,ll> ii;
typedef vector<pair<ll,ll> > vii;
typedef vector<vector<pair<ll,ll> > > vvii;
typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
 

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define sz(a) ll((a).size()) 
#define pb push_back 
#define mp make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(ll i=a;i<=b;++i)
#define ROF(i,a,b) for(ll i=a;i>=b;--i)
#define endl '\n'


int main() 
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll m;
    cin>>m;
    ll h1,a1;
    ll x1,y1;
    cin>>h1>>a1>>x1>>y1;
    ll t0,t1;
    FOR(i,0,m)
    {
        if(h1==a1){t0=i;break;}
        h1=((ll)x1*h1+(ll)y1)%m;
    }
    if(h1!=a1){cout<<"-1";return 0;}
    FOR(i,t0+1,t0+m)
    {
        h1=((ll)x1*h1+(ll)y1)%m;
        if(h1==a1){t1=i-t0;break;}
    }
    ll h2,a2;
    ll x2,y2;
    cin>>h2>>a2>>x2>>y2;
    ll T0,T1;
    FOR(i,0,m)
    {
        if(h2==a2){T0=i;break;}
        h2=((ll)x2*h2+(ll)y2)%m;
    }
    if(h2!=a2){cout<<"-1";return 0;}
    FOR(i,T0+1,T0+m)
    {
        h2=((ll)x2*h2+(ll)y2)%m;
        if(h2==a2){T1=i-T0;break;}
    }
/*  cout<<t0<<endl;
    cout<<t1<<endl;
    cout<<T0<<endl;
    cout<<T1<<endl;*/
   
    FOR(i,0,m)
    {
        if((t0+i*t1-T0)%T1==0&&(t0+i*t1-T0)>=0)
        {cout<<t0+i*t1;return 0;}
    }
    cout<<"-1";
    return 0;
}