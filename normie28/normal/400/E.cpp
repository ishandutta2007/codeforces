
// Problem : E. Inna and Binary Logic
// Contest : Codeforces - Codeforces Round #234 (Div. 2)
// URL : https://codeforces.com/problemset/problem/400/E
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
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
#define MOD 1000000007
#define MOD2 1000000009
#define INF 2000000000
#define DESPACITO 1000000000000000000
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
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
int n,m,k,c[501],pos[100001],t,t1,i,j;
 
using namespace std;
 
set<int>bits[20]; 
 
int main()
{
	fio;
	int n,m;
	cin >> n >> m;
	int arr[n+1];
	REP(i,1,n)
	{
		cin >> arr[i];
		REP(j,0,19)
			if(!(arr[i]&(1<<j)))
				bits[j].insert(i);
	}
	REP(j,0,19)
	{
		bits[j].insert(0);
		bits[j].insert(n+1);
	}
	ll sum=0;
	REP(i,1,n)
	{
		REP(j,0,19)
		{
			auto it=bits[j].lower_bound(i);
			sum+=1LL * ((*it)-i) * (1<<j);
		}
	}
	while(m--)
	{
		int p,v;
		cin >> p >> v;
		REP(j,0,19)
		{
			if(v&(1<<j) && (!(arr[p]&(1<<j))))
			{
				auto it1=bits[j].find(p);
				it1--;
				int l=(*it1)+1;
				it1++;
				it1++;
				int r=(*it1)-1;
				sum+=1LL * (r-p+1) * (p-l+1) * (1<<j); 
				bits[j].erase(p);
 
			}
			else if((!(v&(1<<j))) && (arr[p]&(1<<j)))
			{
				auto it1=bits[j].upper_bound(p);
				int r=(*it1)-1;
				it1--;
				int l=(*it1)+1;
				sum-=1LL * (r-p+1) * (p-l+1) * (1<<j);
				bits[j].insert(p);
			}
		}
		arr[p]=v;
		cout << sum  << "\n";
	}
}