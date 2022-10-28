#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define rz resize
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
#define mid ((l+r)>>1)
const int N = 1e5;
vector<ii> a;
int main()
{
    boost;
    string s;cin>>s;
    int n = s.length();
    set<char> v = {'a','e','i','o','u','A','E','I','O','U'};
    a.resize(n+1);
    a[0]={0,0};
    FOR(i,1,n){
    	if(v.find(s[i-1])==v.end())
    	a[i].F=3;
    	a[i].S=i;
    }
    FOR(i,1,n)a[i].F=a[i-1].F+a[i].F;
    FOR(i,1,n)a[i].F=a[i].F-i;
    sort(all(a));
    ii ans = {0,0};
    int sm=INF;
    FOR(i,0,n){
    	if(sm<=a[i].S-1)
    	{
    		if(ans.F==a[i].S-sm)++ans.S;
    		else if(ans.F<a[i].S-sm)ans={a[i].S-sm,1};
    	}
    	sm=min(sm,a[i].S);
    }
    if(ans.F==0){cout<<"No solution";return 0;}
    else cout<<ans.F<<" "<<ans.S;
	return 0;
}