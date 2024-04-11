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


ll a[100001];
struct bit_trie{
	int len;
	struct node{
		int N[2];
		node(){N[0]=N[1]=0;}
	};
	vector<node> T;
	bit_trie(int len):len(len),T(2){};
	void insert(int no, ll x){
		NFOR(i,len,0){
			int b = (x>>i)&1;
			if(!T[no].N[b])
			T.push_back(node()),T[no].N[b]=T.size()-1;
			no=T[no].N[b];
		}
	}
	ll query(int no,ll x){
		ll ans=0;
		NFOR(i,len,0){
			int b = (x>>i)&1;
			if(T[no].N[!b])
				ans^=(1LL<<i),no=T[no].N[!b];
			else
				no=T[no].N[b];
		}
		return ans;
	}

};
int main()
{
    boost;
   	int n;cin>>n;
   	bit_trie T(40);
   	T.insert(1,0);
   	ll ans=0;
   	FOR(i,1,n){
   		cin>>a[i];a[i]^=a[i-1];
   	}

   	FOR(i,1,n){
   		T.insert(1,a[i]);
   		ans=max(ans,T.query(1,a[i]^a[n]));
   	}
   	cout<<ans;
	return 0;
}