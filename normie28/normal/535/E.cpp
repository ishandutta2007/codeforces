
// Problem : E. Tavas and Pashmaks
// Contest : Codeforces - Codeforces Round #299 (Div. 2)
// URL : https://codeforces.com/problemset/problem/535/E
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
#define index indexx
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
//---------END-------//
struct Freg{
	long long y, x;
	bool operator <(Freg t){
		return (double)y*t.x < (double)x*t.y;
	}
};
struct  Node
{
	int u;
	Freg dif;
};
int N;
int a[200005];
int b[200005];
int index[200005];
list <Node> ll;
int cmp(int x, int y){
	if (a[x] != a[y])
		return a[x]>a[y];
	else
		return b[x] > b[y];
}
int cmp2;
Freg diff(int former, int latter){
	Freg res;
	res.y = (long long)b[former] * b[latter] * (a[former] - a[latter]);
	res.x = (long long)a[former] * a[latter] * (b[latter] - b[former]);
	return res;
}

	int i, j;
	int u;
	int lastb;
	int lasta;
	Node temp;
	Node t;
int main()
{
	fio;
	cin >> N;
	for (i = 0; i < N; ++i){
		cin>>a[i]>>b[i];
		index[i] = i;
	}
	
	sort(index, index + N, cmp);
	temp.u = index[0];
	temp.dif.y = 0;
	temp.dif.x = 1;
	ll.push_back(temp);
	lastb = b[index[0]];
	lasta = a[index[0]]; 
	
	int xxx = 0;
	for (i = 1; i < N; ++i){
		u = index[i];
		t = ll.back();
		if (a[u] == a[t.u] && b[u] == b[t.u]){
			t.u = u;
			ll.push_back(t);
		}
		if (b[u] <= lastb)
			continue;
		lastb = b[u];
		lasta = a[u];
		while (1){
			t = ll.back();
			temp.dif = diff(t.u, u);
			if (!( temp.dif<t.dif)){
				temp.u = u;
				ll.push_back(temp);
				break;
			}
			else{
				ll.pop_back();
			}
		}
	}
	list  <Node>::iterator it, end;
	it = ll.begin();
	end = ll.end();
	i = 0;
	N = ll.size();
	for (; it != end; ++it){
		index[i++] = it->u;
	}
	sort(index, index + N);
	cout<<index[0]+1;
	for (i = 1; i < N; ++i)
		cout<<' '<<index[i]+1;
	cout<<endl;
}