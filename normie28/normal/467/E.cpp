
// Problem : E. Alex and Complicated Task
// Contest : Codeforces - Codeforces Round #267 (Div. 2)
// URL : https://codeforces.com/problemset/problem/467/E
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
#define pb push_back
#define mp make_pair
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
struct SegmentTree
{
	vector<int> mn;
	int sz;
	SegmentTree(){}
	void init(int n){ sz=n;mn.clear();mn.assign(n*2,MOD);}
	void Set(int i, int f){ i+=sz-1;mn[i]=f;for(i>>=1;i;i>>=1) mn[i]=min(mn[i<<1],mn[i<<1|1]);}
	int Get(int l, int r)
	{
		int ret=MOD;
		for(l+=sz-1,r+=sz-1;l<=r;l>>=1,r>>=1)
		{
			if(l%2==1) ret=min(ret,mn[l]),l++;
			if(r%2==0) ret=min(ret,mn[r]),r--;
		}
		return ret;
	}
} Tree;
const int N=500050;
int a[N],l[N],r[N],ss[N],se[N];
pair<pair<int,int> ,pair<int,int> > ans[N];
int main()
{
	int n,i,j;map<int,int> lst;
	cin>>n;Tree.init(n);
	for(i=1;i<=n;i++) cin>>a[i],l[i]=lst[a[i]],lst[a[i]]=i;
	lst.clear();for(i=n;i>=1;i--) r[i]=lst[a[i]],lst[a[i]]=i;
	for(i=1;i<=n;i++)
	{
		if(l[i])
		{
			Tree.Set(l[i],MOD);
			ss[i]=l[i];
			se[i]=Tree.Get(l[i]+1,i-1);
			if(se[i]!=MOD) ans[i]=mp(mp(ss[i],l[se[i]]),mp(i,se[i]));
		}
		else se[i]=MOD,ss[i]=0;
		if(r[i]) Tree.Set(i,r[i]);
	}
	vector<int> sol;
	for(i=1;i<=n;i=j)
	{
		int mn=n+1,taj=0;
		for(j=i;j<mn;j++)
		{
			if(se[j]<mn && ss[j]>=i) mn=se[j],taj=j;
			if(r[r[r[j]]] && r[r[r[j]]]<mn) mn=r[r[r[j]]],taj=j,ans[j]=mp(mp(j,r[j]),mp(r[r[j]],r[r[r[j]]]));
		}
		j++;
		if(taj) sol.pb(taj);
	}
	cout<<sol.size()*4<<endl;
	for(ll i:sol) cout<<a[ans[i].first.first]<<' '<<a[ans[i].first.second]<<' '<<a[ans[i].second.first]<<' '<<a[ans[i].second.second]<<' ';
}
/*
D:/Users/PC/Desktop/work/A13/467E.cpp:19: warning: ignoring #pragma comment  [-Wunknown-pragmas]
   19 | #pragma comment(linker, "/stack:200000000")
      | 
D:/Users/PC/Desktop/work/A13/467E.cpp: In function 'int main()':
D:/Users/PC/Desktop/work/A13/467E.cpp:102:7: error: expected ';' before ':' token
  102 |  for(i:sol) cout<<a[ans[i].first.first]<<' '<<a[ans[i].first.second]<<' '<<a[ans[i].second.first]<<' '<<a[ans[i].second.second];
      |       ^
      |       ;
D:/Users/PC/Desktop/work/A13/467E.cpp:102:6: warning: statement has no effect [-Wunused-value]
  102 |  for(i:sol) cout<<a[ans[i].first.first]<<' '<<a[ans[i].first.second]<<' '<<a[ans[i].second.first]<<' '<<a[ans[i].second.second];
      |      ^
D:/Users/PC/Desktop/work/A13/467E.cpp:103:1: error: expected primary-expression before '}' token
  103 | }
      | ^
D:/Users/PC/Desktop/work/A13/467E.cpp:102:129: error: expected ';' before '}' token
  102 |  for(i:sol) cout<<a[ans[i].first.first]<<' '<<a[ans[i].first.second]<<' '<<a[ans[i].second.first]<<' '<<a[ans[i].second.second];
      |                                                                                                                                 ^
      |                                                                                                                                 ;
  103 | }
      | ~                                                                                                                                
D:/Users/PC/Desktop/work/A13/467E.cpp:103:1: error: expected primary-expression before '}' token
  103 | }
      | ^
D:/Users/PC/Desktop/work/A13/467E.cpp:102:129: error: expected ')' before '}' token
  102 |  for(i:sol) cout<<a[ans[i].first.first]<<' '<<a[ans[i].first.second]<<' '<<a[ans[i].second.first]<<' '<<a[ans[i].second.second];
      |     ~                                                                                                                           ^
      |                                                                                                                                 )
  103 | }
      | ~                                                                                                                                
D:/Users/PC/Desktop/work/A13/467E.cpp:103:1: error: expected primary-expression before '}' token
  103 | }
      | ^
]
*/