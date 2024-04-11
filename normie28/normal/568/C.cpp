
// Problem : C. New Language
// Contest : Codeforces - Codeforces Round #315 (Div. 1)
// URL : https://codeforces.com/problemset/problem/568/C
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
typedef long long LL;
//---------END-------//
 
LL n,e[405][405];
void floyd(){
	for(LL k = 1;k <= n + n;k ++){
		for(LL i = 1;i <= n + n;i ++){
			for(LL j = 1;j <= n + n;j ++){
				e[i][j] |= (e[i][k] && e[k][j]);
			}
		}
	}
}
 
LL acv[405],tcv[405];
LL mxp[2],vc[35],nxt[35],nxu[35];
string s;
LL chk(LL pos,LL now,LL x,LL id){
	LL tmp;
	if(acv[pos] != -1 && acv[pos] != vc[now]) return 0;
	for(LL i = 1;i <= n;i ++) if(e[x][i] && e[x][i + n]) return 0;
	for(LL i = 1;i <= n;i ++){
		tcv[i] = -1;
		if(e[x][i]) tcv[i] = 0;
		if(e[x][i + n]) tcv[i] = 1;
	}
	if(!id){
		for(LL i = 1;i <= n;i ++){
			if(pos + i > n) break;
			tmp = max(tcv[pos + i],acv[pos + i]);
			if(tmp == -1) break;
			if(mxp[tmp] < s[pos + i] - 'a' + 1) return 0;
			if(mxp[tmp] > s[pos + i] - 'a' + 1) break;
		}
	}
	for(LL i = 1;i <= n;i ++) acv[i] = max(acv[i],tcv[i]);
	return 1;
}
 
LL ans[405];
int main(){
	LL len,m,l1,l2,c1,c2,fla;
	char ch1,ch2;
	cin >> s; len = s.length(); s = ' ' + s;
	for(LL i = 1;i <= len;i ++) vc[i] = (s[i] == 'C' ? 0 : 1);
	mxp[0] = mxp[1] = -1; for(LL i = 1;i <= len;i ++) mxp[vc[i]] = i;
	for(LL i = 1;i <= len;i ++){
		nxt[i] = 0;
		for(LL j = i + 1;j <= len;j ++){
			if(vc[i] != vc[j]){ nxt[i] = j; break; }
		}
	}
	for(LL i = 1;i <= len;i ++){
		nxu[i] = 0;
		for(LL j = i + 1;j <= len;j ++){
			if(vc[i] == vc[j]){ nxu[i] = j; break; }
		}
	}
	
	memset(acv,-1,sizeof(acv));
	memset(tcv,-1,sizeof(tcv));
	cin >> n >> m;
	while(m --){
		cin >> l1 >> ch1 >> l2 >> ch2;
		c1 = (ch1 == 'C') ? 0 : 1;
		c2 = (ch2 == 'C') ? 0 : 1;
		e[l1 + c1 * n][l2 + c2 * n] = 1;
		e[l2 + (!c2) * n][l1 + (!c1) * n] = 1;
	} floyd();
	
	cin >> s; s = ' ' + s;
	fla = 0;
	for(LL i = 1;i <= n;i ++){
		LL mi = fla ? 1 : s[i] - 'a' + 1;
		if(chk(i,mi,i + vc[mi] * n,fla)) ans[i] = mi;
		else if(vc[mi] == vc[mi + 1] && chk(i,mi + 1,i + vc[mi + 1] * n,1)) ans[i] = mi + 1,fla = 1;
		else if(nxt[mi] && chk(i,nxt[mi],i + vc[nxt[mi]] * n,1)) ans[i] = nxt[mi],fla = 1;
		else if(nxu[mi] > nxt[mi] && nxu[mi] && chk(i,nxu[mi],i + vc[nxu[mi]] * n,1)) ans[i] = nxu[mi],fla = 1;
		else{ cout << -1 << '\n'; return 0; }
	}
	for(LL i = 1;i <= n;i ++)
		if(ans[i] > len){
			cout << -1 << '\n';
			return 0;
		}
	for(LL i = 1;i <= n;i ++) cout << (char)(ans[i] + 'a' - 1); cout << '\n';
}