
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
ll ans=0;
string s;
ll cal(int L, int R, bool g)
{
	ll U=0, A=0, M=1;
	if (!g) U = cal(L, R, 1);
	int i1=(g?L:0), i2=(g?R+1:s.size());
	for (int i=i1; i<i2; i++) {
		if (!g&&i==L) {
			M*=U; i=R;
		}
		else if (s[i]=='+') {
			A+=M; M=1;
		}
		else if (s[i]<='9'&&s[i]>='0') {
			M*=s[i]-'0';
		}
	}
	return A+M;
}
int main()
{
    fio;
	cin>>s;
	ans=cal(0,0,0);
	for (int i=0; i<s.size(); i++) if (s[i]=='*') {
		for (int j=0; j<i; j+=2) {
			ll t=cal(j,i-1,0);
			ans = max(ans , t);
		}
		for (int j=i+1; j<s.size(); j+=2) {
			ll t=cal(i+1,j,0);
			ans = max(ans , t);
		}
	}
	cout<<ans<<endl;
}