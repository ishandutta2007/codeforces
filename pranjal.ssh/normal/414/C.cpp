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


ll MRG[22],IMRG[22];
vi T[1<<21];
int N;
int a[1+(1<<20)];
int q;
#define mid ((l+r)>>1)
void build(int no,int l,int r,int level){
	if(l==r){T[no]={a[l]};return;}
	build(2*no,l,mid,level+1);build(2*no+1,mid+1,r,level+1);
	
	T[no].resize(r-l+1);
	merge(all(T[2*no]),all(T[2*no+1]),T[no].begin());
	
	int j=0;int n = T[2*no].size();
	for(auto it:T[2*no]){
		while(j<n and T[2*no+1][j]<it)++j;
		MRG[level]+=j;
	}
	j=0;
	for(auto it:T[2*no+1]){
		while(j<n and T[2*no][j]<it)++j;
		IMRG[level]+=j;
	}
}
bool mark[21];
int main()
{
    boost;
    int n;cin>>n;N=(1<<n);
    FOR(i,1,N)cin>>a[i];
    build(1,1,N,1);
    
    TCASE{
    	cin>>q;
    	ll ans=0;
    	FOR(i,n-q+1,n+1)mark[i]^=1;
    	FOR(i,1,n+1)ans+=mark[i]?IMRG[i]:MRG[i];
    	cout<<ans<<"\n";
    }
	return 0;
}