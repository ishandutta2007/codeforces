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




string s[2]={"Alice","Bob"};
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,mx=-INF;
    cin>>n;
    vi a(n);
    FOR(i,0,n-1)cin>>a[i],mx=max(mx,a[i]);
    int g=a[0];
    FOR(i,1,n-1)g=__gcd(g,a[i]);
    
    int x=mx/g-n;
    cout<<s[!(x&1)];
    return 0;
}