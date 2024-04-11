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
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)
inline int add(int a,int b, int m=INF){a+=b;if(a>=m)a-=m;return a;}
inline int mul(int a,int b, int m=INF){return (int)(((ll)a*(ll)b)%m);}

map<int,vector<ii>> mp[4];
map<ii,int> ans;
vii yo;
int main()
{
    boost;
	int n,m;
	cin>>n>>m;
	FOR(i,0,m-1){
		int x,y;cin>>x>>y;int ctr=0;
		yo.push_back(MP(x,y));
		mp[0][x].push_back(MP(y,x));
		mp[1][y].push_back(MP(x,y));
		mp[2][x+y].push_back(MP(x,y));
		mp[3][x-y].push_back(MP(x,y));
	}
	FOR(i,0,3){
		for(auto &it:mp[i]){
			sort(all(it.S));
		}
	}
	
	for(auto itt:yo){
		int x=itt.F;int y=itt.S;int ctr=0;
		
		auto it = upper_bound(all(mp[0][x]),MP(y,x));if(it!=mp[0][x].end())ans[MP(it->S,it->F)]++,ctr++;
		
		it = upper_bound(all(mp[1][y]),MP(x,y));if(it!=mp[1][y].end())ans[*it]++,ctr++;
		
		it = upper_bound(all(mp[2][x+y]),MP(x,y));if(it!=mp[2][x+y].end())ans[*it]++,ctr++;
		
		it = upper_bound(all(mp[3][x-y]),MP(x,y));if(it!=mp[3][x-y].end())ans[*it]++,ctr++;
		ans[itt]+=ctr;
	}
	vi anss(9);
	for(auto it:ans){
		anss[it.S]++;
	}
	for(auto it:anss)cout<<it<<" ";
	return 0;
}