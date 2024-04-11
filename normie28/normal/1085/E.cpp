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
#define FILE_IN "ming.inp"
#define FILE_OUT "ming.out"
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
string s , a , b;
int to[27] , k , T;
bool vis[27];
 
bool up(int dir){
	if(dir == s.size())
		return 1;
	if(to[s[dir] - 'a'] != -1){
		int t = to[s[dir] - 'a'];
		if(t > a[dir] - 'a')
			return 1;
		if(t < a[dir] - 'a')
			return 0;
		return up(dir + 1);
	}
	for(int i = a[dir] - 'a' + 1 ; i < k ; ++i)
		if(!vis[i])
			return vis[to[s[dir] - 'a'] = i] = 1;
	if(!vis[a[dir] - 'a']){
		vis[a[dir] - 'a'] = 1;
		to[s[dir] - 'a'] = a[dir] - 'a';
		if(up(dir + 1))
			return 1;
		to[s[dir] - 'a'] = -1;
		vis[a[dir] - 'a'] = 0;
	}
	return 0;
}
 
bool down(int dir){
	if(dir == s.size())
		return 1;
	if(to[s[dir] - 'a'] != -1){
		int t = to[s[dir] - 'a'];
		if(t > b[dir] - 'a')
			return 0;
		if(t < b[dir] - 'a')
			return 1;
		return down(dir + 1);
	}
	for(int i = 0 ; i < b[dir] - 'a' ; ++i)
		if(!vis[i])
			return vis[to[s[dir] - 'a'] = i] = 1;
	if(!vis[b[dir] - 'a']){
		vis[b[dir] - 'a'] = 1;
		to[s[dir] - 'a'] = b[dir] - 'a';
		if(down(dir + 1))
			return 1;
		to[s[dir] - 'a'] = -1;
		vis[b[dir] - 'a'] = 0;
	}
	return 0;
}
 
bool dfs(int dir){
	if(dir == s.size())
		return 1;
	if(to[s[dir] - 'a'] != -1){
		int t = to[s[dir] - 'a'];
		if(t > a[dir] - 'a' && t < b[dir] - 'a')
			return 1;
		if(t < a[dir] - 'a' || t > b[dir] - 'a')
			return 0;
		if(t == a[dir] - 'a' && t == b[dir] - 'a')
			return dfs(dir + 1);
		if(t == a[dir] - 'a')
			return up(dir + 1);
		if(t == b[dir] - 'a')
			return down(dir + 1);
	}
	for(int i = a[dir] - 'a' + 1 ; i < b[dir] - 'a' ; ++i)
		if(!vis[i])
			return vis[to[s[dir] - 'a'] = i] = 1;
	if(!vis[a[dir] - 'a']){
		vis[a[dir] - 'a'] = 1;
		to[s[dir] - 'a'] = a[dir] - 'a';
		if(a[dir] - 'a' == b[dir] - 'a')
			return dfs(dir + 1);
		if(up(dir + 1))
			return 1;
		vis[a[dir] - 'a'] = 0;
		to[s[dir] - 'a'] = 0;
	}
	if(!vis[b[dir] - 'a']){
		vis[b[dir] - 'a'] = 1;
		to[s[dir] - 'a'] = b[dir] - 'a';
		if(down(dir + 1))
			return 1;
	}
	return 0;
}
 
int main(){
    fio;
	for(cin >> T ; T ; --T){
		cin >> k >> s >> a >> b;
		memset(to , -1 , sizeof(to));
		memset(vis , 0 , sizeof(vis));
		if(dfs(0)){
			cout << "YES" << '\n';
			for(int i = 0 ; i < k ; ++i)
				if(to[i] == -1){
					for(int j = 0 ; j < k ; ++j)
						if(!vis[j]){
							vis[j] = 1;
							cout << (char)('a' + j);
							break;
						}
				}
				else
					cout << (char)('a' + to[i]);
			cout << '\n';
		}
		else
			cout << "NO" << '\n';
	}
}