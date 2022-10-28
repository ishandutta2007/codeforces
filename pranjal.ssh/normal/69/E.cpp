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
#define rz resize()
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}

int a[100001];
map<int,int> mp;
set<int> s;
int main()
{
    boost;
    int n,k;cin>>n>>k;
    FOR(i,0,n-1){
    	cin>>a[i];
    	if(i<k){mp[a[i]]++;if(mp[a[i]]==1)s.insert(a[i]);else if(mp[a[i]]==2)s.erase(a[i]);}
    	else{
    		mp[a[i]]++;if(mp[a[i]]==1)s.insert(a[i]);else if(mp[a[i]]==2)s.erase(a[i]);
    		mp[a[i-k]]--;if(mp[a[i-k]]==0)s.erase(a[i-k]);else if(mp[a[i-k]]==1)s.insert(a[i-k]);
    	}
    	if(i>=k-1)cout<<(s.empty()?"Nothing":to_string(*s.rbegin()))<<"\n";
    }
	return 0;
}