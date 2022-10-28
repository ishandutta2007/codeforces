#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 

using namespace std;
using namespace __gnu_pbds;

#define INF 1000000007

typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int> > vvi;
typedef pair<int,int> ii;
typedef vector<pair<int,int> > vii;
typedef vector<vector<pair<int,int> > > vvii;

#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define tr(x,it) for(auto it = (x).begin();it!=(x).end();++it)
#define ntr(x,it) for(auto it = (x).rbegin();it!=(x).rend();++it)
#define ufy(v) sort(all(v));(v).erase(unique(all((v))),(v).end())
#define sz(a) int((a).size()) 
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back 
#define PB pop_back
#define pf push_front
#define PF pop_front
#define MP make_pair
#define clr clear
#define rz resize
#define C(a,b) memset(a,b,sizeof(a))
#define ia(a,n) FOR(i,0,n-1)cin>>a[i]
#define ia1(a,n) FOR(i,1,n)cin>>a[i]
#define fpresent(c,x) ((c).find(x) != (c).end())  // set,map
#define present(c,x) (find(all(c),x) != (c).end())  //vector
#define F first
#define S second
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define NFOR(i,a,b) for(int i=a;i>=b;--i)
#define rep(i,n) FOR(i,0,n-1)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}
inline int norm(int x,int m=INF){if(x>=m)x%=m;if(x<0)x+=m;return x;}
inline int neg(int x,int m=INF){x=-x;return norm(x);}

const int N =2e5+10;
int a[N];
ii q[N];
map<int,ii> mp;
multiset<int> s;
vi ans;
int main()
{
    boost;
    int n,m;
    cin>>n>>m;
    
    
    FOR(i,0,n-1)cin>>a[i],s.insert(a[i]);
    FOR(i,0,m-1){
    	cin>>q[i].S>>q[i].F;
    	--q[i].F;
    	mp[q[i].F]=MP(i,q[i].S);
    }
    int boobs=false;	//:(
    int prv=-1;
    NFOR(i,n-1,0){
    	auto it = mp.find(i);
    	if(it==mp.end()){
    		if(!boobs)	ans.pb(a[i]),s.erase(s.find(a[i]));
    		else if (boobs==1) ans.pb(*s.rbegin()),s.erase(--s.end());
    		else ans.pb(*s.begin()),s.erase(s.begin());
    		continue;
    	}
    	if(it->S.F>prv)	boobs=it->S.S,prv=it->S.F;
    	if(!boobs)	ans.pb(a[i]),s.erase(s.find(a[i]));
    	else if (boobs==1) ans.pb(*s.rbegin()),s.erase(--s.end());
    	else ans.pb(*s.begin()),s.erase(s.begin());
    	
    }
    ntr(ans,it)cout<<*it<<" ";
    
	return 0;
}