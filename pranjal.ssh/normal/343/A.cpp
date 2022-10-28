#include <bits/stdc++.h>
using namespace std;

#define INF 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) x.begin(), x.end()
#define tr(x,it) for(auto it = x.begin();it!=x.end();++it)
#define ntr(x,it) for(auto it = x.rbegin();it!=x.rend();++it)
#define sz(a) int((a).size()) 
#define pb push_back 
#define MP make_pair
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)





int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll a,b;
    cin>>a>>b;
    ll ans=0;
    while(a&&b)
    {
        if(a>b)
        {
            ll x=a/b;
            ans+=x;
            a=a-x*b;
            continue;
        }
        ll x=b/a;
        ans+=x;
        b=b-a*x;
    }
    cout<<ans<<"\n";
    return 0;
}