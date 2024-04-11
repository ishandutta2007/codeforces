
// Problem : E. Champions' League
// Contest : Codeforces - Codeforces Round #145 (Div. 2, ACM-ICPC Rules)
// URL : https://codeforces.com/problemset/problem/234/E
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
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "input.txt"
#define FILE_OUT "output.txt"
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
typedef pair<int,string> is;
int gen_rand(int&x, int a, int b, int c, int sz){
	x = (x*a+b)%c;
	return x%sz;
}
int main(){
	ofile;
	fio;
	int n,x,a,b,c; cin>>n>>x>>a>>b>>c;
	int m=n/4;
	vector<vector<is>>baskets(4, vector<is>(m));
	vector<is>teams(n);
	for(int i=0;i<n;i++)
		cin>>teams[i].second>>teams[i].first;
	sort(teams.begin(),teams.end(),[&](const is& a, const is& b){
		if(a.first!=b.first)
			return a.first>b.first;
		else
			return a.second<b.second;
	});
	for(int cnt=0;cnt<n;cnt++)
		baskets[cnt/m][cnt%m]=teams[cnt];
	vector<vector<is>>groups(m,vector<is>(4));
	int cur=0;
	for(int i=0;i<m;i++){
		int sz=baskets[0].size();
		for(int j=0;j<4;j++){
			int rnd=gen_rand(x,a,b,c,sz);
			groups[i][j]=baskets[j][rnd];
			baskets[j].erase(baskets[j].begin()+rnd);
		}
	}
	for(int i=0;i<m;i++){
		char group_tag= i+'A';
		cout<<"Group "<<group_tag<<":\n";
		for(int j=0;j<4;j++){
			cout<<groups[i][j].second<<endl;
		}
	}
}