
// Problem : C. Subset Sums
// Contest : Codeforces - Codeforces Round #202 (Div. 1)
// URL : https://codeforces.com/problemset/problem/348/C
// Memory Limit : 256 MB
// Time Limit : 3000 ms
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
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
/*
The whole thing literally dented the LCL's reputation, like seriously why the fuck were they 
allowed to compete in the first place, they were literally a bunch of diamonds, i remember when this roster was first announced, 
some people already predicted that its gonna flop, yet you had some morons arguing that people are being sexist lol
*/
const int maxn=100005,maxblo=305 ;
int n,m,k,c[501],pos[100001],t,t1,i,j;
ll tag[305],val[maxn] ;
int times[maxn][305] ;
ll sum[305];
int idx ;
vector<int> v[maxn] ;
int blo[maxn] ;
bool f[maxn][305] ;
int N,M,Q ;
int block ;
inline void minit(){
	for(int i=1;i<=M;i++){
		if(v[i].size()<=block) continue ;
		blo[i]=++idx ;
		for(int j=0;j<=v[i].size()-1;j++){
			f[v[i][j]][idx]=1 ;
			sum[idx]+=val[v[i][j]] ; 
		}
	}
	for(int i=1;i<=M;i++){
		for(int j=1;j<=idx;j++){
			for(int k=0;k<=v[i].size()-1;k++){
				times[i][j]+=f[v[i][k]][j] ;
			} 
		}
	}
} 
inline void add(int pos,ll c){
	if(blo[pos]){
		tag[blo[pos]]+=c ;
		return ;
	} 
	else {
		for(int i=0;i<=v[pos].size()-1;i++){
			val[v[pos][i]]+=c ;
		}
	}
	for(int i=1;i<=idx;i++) sum[i]+=(1ll)*times[pos][i]*c ;
}
inline ll query(int pos){
	ll ans=0 ;
	if(blo[pos]) ans+=sum[blo[pos]] ;
	else {
		for(int i=0;i<=v[pos].size()-1;i++){
			ans+=val[v[pos][i]] ;
		}
	}
	for(int i=1;i<=idx;i++) ans+=tag[i]*times[pos][i] ;
	return ans ;
}
int main(){
	char flag[5] ;
	int pos ;
	ll c ;
	cin>>N>>M>>Q;
	for(int i=1;i<=N;i++) cin>>val[i];
	for(int i=1;i<=M;i++){
		int k,a;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			v[i].push_back(a) ;
		}
		block+=k ;
	}
	block=sqrt(block) ;
	minit() ; 
	while(Q--){
		cin>>flag;
		if(flag[0]=='+') cin>>pos>>c,add(pos,c) ;
		else {
			cin>>pos;
			cout<<query(pos)<<endl ;
		}
	}
}