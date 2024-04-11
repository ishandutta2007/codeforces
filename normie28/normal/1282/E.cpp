
// Problem : F. Vicky's Delivery Service
// Contest : Codeforces - Codeforces Round #561 (Div. 2)
// URL : https://codeforces.com/problemset/problem/1166/F
// Memory Limit : 256 MB
// Time Limit : 4000 ms
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
pair<int,int> p(int a, int b){
	return {min(a,b),max(a,b)};
}
 
struct Triangle{
	int a,b,c;
	int neis;
	vector<int>V;
};
int aloneVertex(const Triangle &t1, const Triangle &t2){
	if(t1.a!=t2.a && t1.a!=t2.b && t1.a!=t2.c)
		return t1.a;
	if(t1.b!=t2.a && t1.b!=t2.b && t1.b!=t2.c)
		return t1.b;
	return t1.c;
}
 
int main(){
    fio;
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		map<pair<int,int>,int>Mp;
		vector<Triangle>Vec(n-2);
		for(int i=0;i<n-2;i++){
			cin >> Vec[i].a >> Vec[i].b >> Vec[i].c;
			
			auto f = [&](int x, int y)->void{
				if(Mp.count(p(x,y))){
					int ii=Mp[p(x,y)];
					Vec[i].V.push_back(ii);
					Vec[ii].V.push_back(i);
					Mp.erase(Mp.find(p(x,y)));
				}
				else
					Mp[p(x,y)]=i;
			};
			
			f(Vec[i].a,Vec[i].b);
			f(Vec[i].b,Vec[i].c);
			f(Vec[i].c,Vec[i].a);
		}
		for(int i=0;i<n-2;i++)
			Vec[i].neis = Vec[i].V.size();
		vector<vector<int>>Hull(n+1);
		for(auto x : Mp){
			Hull[x.first.first].push_back(x.first.second);
			Hull[x.first.second].push_back(x.first.first);
		}
		function<void(int,int)> dfs = [&](int v, int p)->void{
			cout << v << " ";
			for(int nei : Hull[v])
				if(nei!=p && nei!=1)
					dfs(nei, v);
		};
		dfs(1, Hull[1][0]);
		cout << "\n";
		
		vector<bool>Used(n-2, false);
		queue<int>Q;
		for(int i=0;i<n-2;i++)
			if(Vec[i].neis<=1)
				Q.push(i);
		while(!Q.empty()){
			int q = Q.front();
			Q.pop();
			Used[q]=true;
			cout << q+1 << " ";
			
			for(int nei : Vec[q].V)
				if(!Used[nei] && --Vec[nei].neis==1)
					Q.push(nei);
		}
		cout << "\n";
	}
	
	return 0;
}