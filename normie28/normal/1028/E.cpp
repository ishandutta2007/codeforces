
// Problem : E. Restore Array
// Contest : Codeforces - AIM Tech Round 5 (rated, Div. 1 + Div. 2)
// URL : https://codeforces.com/contest/1028/problem/E
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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
typedef long double ld;
typedef unsigned long long ull;
 
int main(){
	fio;
	cout<<setprecision(32);
 
	int n;
	cin>>n;
	vector<ll> b(n);
	ll mx = 0;
	for(ll &x : b){
		cin>>x;
		mx = max(mx, x);
	}
	if(mx == 0){
		cout<<"YES\n";
		for(int i = 0; i < n; i++){
			cout<<1<<" ";
		}
		cout<<'\n';
		exit(0);
	}
	int ind = -1;
	for(int i = 0; i < n; i++){
		if(b[i] == mx && b[(i + n - 1)%n] != mx){
			ind = i;
			break;
		}
	}
	if(ind == -1){
		cout<<"NO\n";
		exit(0);
	}
	if(b[(ind + n - 1)%n] == 0)b[(ind + n - 1)%n] = b[ind];
	for(int i = 1; i < n; i++){
		b[(ind + n - i)%n] += b[(ind + n - i + 1)%n];
	}
	cout<<"YES\n";
	for(int i = 0; i < n; i++){
		cout<<b[i]<<" ";
	}
}