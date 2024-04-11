
// Problem : D. Yui and Mahjong Set
// Contest : Codeforces - Codeforces Round #635 (Div. 1)
// URL : https://codeforces.com/problemset/problem/1336/D
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
typedef vector<int> vi;
typedef vector<vi> vvi;
//---------END-------//
const int MN = 110;
ll res[MN];
ll ch[MN];
vi oof;
int sz;
void pre() {
	for(int i=0;i<MN;i++) {
		ch[i] = i*(i-1)*(i-2)/6;
	}
}
vi ba,bb;
ll wa[3],wb[3];
int main() {
	fio;
	int n;
	cin >> n;
	int pa,pb;
	cin >> pa >> pb;
	ba.push_back(pa);
	bb.push_back(pb);
	sz = n;
	pre();
	for(int i=n-1;i>=3;i--) {
		cout << "+ " << i << '\n';
		cout.flush();
		int a,b;
		cin >> a >> b;
		ba.push_back(a);
		bb.push_back(b);
	}
	int p[3] = {1,2,1};
	for(int i=0;i<3;i++) {
		cout << "+ " << p[i] << '\n';
		cout.flush();
		cin >> wa[i] >> wb[i];
	}
	for(int i=2;i<MN;i++) {
		if(wa[2]-wa[1] == ch[i]-ch[i-1]) {
			res[0] = i-2;
		}
	}
	res[2] = ((wb[2]-wb[1])-(wb[0]-bb.back()))-1;
	res[1] = ((wb[2]-wb[1]))/(res[2]+1)-1;
	res[3] = ((wb[1]-wb[0])/(res[2]+1))-res[0]-1-1;
	for(int i=4;i<n;i++) {
		int idx = bb.size()-(i-4)-1;
		int dif = bb[idx]-bb[idx-1];
		res[i] = (dif-res[i-4]*res[i-3] - res[i-3]*(res[i-1]+1))/(res[i-1]+1)-1;
	}
	res[n-1]++;
	cout << "!";
	for(int i=0;i<n;i++) {
		cout << " " << res[i];
	}
	cout << '\n';
	cout.flush();
}