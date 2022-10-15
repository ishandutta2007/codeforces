
// Problem : C. The Great Mixing
// Contest : Codeforces - Codeforces Round #407 (Div. 1)
// URL : https://codeforces.com/problemset/problem/788/C
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
//---------END-------//
ll n,m,k,used[501],arr[1000001],t,t1,i,j,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
map<int, int> mp1, mp2;
queue<int> que;
 
int main(void)
{
	fio;
	int aver, n;
	cin>>aver>>n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin>>a;
		mp1[a - aver] = 1;
	}
	que.push(0);
	bool isexist = false;
	while(!que.empty())
	{
		int a = que.front();
		que.pop();
		for (int i = -1000; i <= 1000; i++)
		{
			if (mp1[i] && !mp2[a + i])
			{
				mp2[a + i] = mp2[a] + 1;
				if (a + i == 0)
				{
					isexist = true;
					cout<<mp2[a+i];
					return 0;
				}
				if (a + i >= -1000 && a + i <= 1000)
					que.push(a + i);
			}
		}
	}
	cout<<-1;
}