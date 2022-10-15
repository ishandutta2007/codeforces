
// Problem : D. Unambiguous Arithmetic Expression
// Contest : Codeforces - Codeforces Beta Round #87 (Div. 1 Only)
// URL : https://codeforces.com/problemset/problem/115/D
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
const int N=2100;
char txt[N];
string presolve(string s)
{
	string res;
	int n=s.size();
	int i=0;
	while(i<n)
	{
		if(s[i]=='+'||s[i]=='-')
		{
			res+='+';
			i++;
			continue;
		}
		if(s[i]=='*'||s[i]=='/')
		{
			res+='*';
			i++;
			continue;
		}
		res+='x';
		while(i<n&&isdigit(s[i]))
			i++;
	}
	return res;
}
const int mod=1000003;
int dp1[N][N],dp2[N][N];
int main()
{
	fio;
	cin>>txt;
	string s=presolve(txt);
	if(s=="x")
	{
		cout<<1<<endl;
		return 0;
	}
	dp1[0][0]=1;
	int n=s.size();
	for(int i=0;i<=n;i++)
	{
		for(int j=N-1;j>=0;j--)
		{
			if(dp2[i][j])
			{
				dp1[i+1][j+1]=(dp1[i+1][j+1]+dp2[i][j])%mod;
				if(j>0)
					dp2[i][j-1]=(dp2[i][j-1]+dp2[i][j])%mod;
			}
		}
		for(int j=0;j<N;j++)
		{
			if(dp1[i][j])
			{
				if(s[i]=='+')
					dp1[i+1][j+1]=(dp1[i+1][j+1]+dp1[i][j])%mod;
				if(s[i]=='x')
					dp1[i+2][j+1]=(dp1[i+2][j+1]+dp1[i][j])%mod;
				if(s[i]=='x'&&j>0)
					dp2[i+1][j-1]=(dp2[i+1][j-1]+dp1[i][j])%mod;
			}
		}
	}
	cout<<dp2[n][0]<<endl;
}