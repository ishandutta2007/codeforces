
// Problem : B. Multihedgehog
// Contest : Codeforces - Codeforces Round #518 (Div. 1) [Thanks, Mail.Ru!]
// URL : https://codeforces.com/contest/1067/problem/B
// Memory Limit : 256 MB
// Time Limit : 1000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

/*
 A Submission by $%U%$
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$
*/
#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define fef(i,a,b) for(ll i=a;i<=b;i++)
#define rer(i,a,b) for(ll i=b;i>=a;i--)
#define wew while(true)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
#define N 100009
set<int> l[N],verts,leaves,nextleaves;
int deg[N];
 
int main(){	
    fio;
	int i,j,t1,t2,t3,t4,n,k,cur,tots;
	bool fail=false;
	cin>>n>>k;
	for(i=0;i<n-1;i++){
		cin>>t1>>t2;
		l[t1].insert(t2);
		l[t2].insert(t1);
	}
	for(i=1;i<=n;i++){
		verts.insert(i);
	}
	if(n<=3){
		cout<<"No";
		return 0;
	}
	cur=0;
	tots=n;
	while(tots>1){
		leaves.clear();
		nextleaves.clear();
		cur++;
		for(auto it : verts){
			if((int)l[it].size()==1){
				leaves.insert(it);
			}
		}
		for(auto it : leaves){
			auto it2=l[it].begin();
			t1=*it2;
			deg[t1]++;
			nextleaves.insert(t1);
			l[t1].erase(it);
			l[it].erase(t1);
			verts.erase(it);
			tots--;
		}
		for(auto it : nextleaves){
			if(deg[it]<3){
				cout<<"No";
				return 0;
			}
			deg[it]=0;
		}
	}
	if(cur==k){
				cout<<"Yes";
	}
	else{
				cout<<"No";
	}
}