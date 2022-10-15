
// Problem : E. The Last Fight Between Human and AI
// Contest : Codeforces - Codeforces Round #354 (Div. 2)
// URL : https://codeforces.com/problemset/problem/676/E
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
ll n,m,k,c[501],pos[100001],t,t1,i,j,qm;
ll coeff[100001];
int main()
{
//  ofile;
    fio;
    cin>>n>>k;
    if (k==0)
    {
    	int isqm=0;
    	string s0; cin>>s0;
    	if (s0=="?")
    	{
    		qm++;
    		isqm=1;
    	}
    	for (i=1;i<=n;i++)
    	{
    		
    	string s; cin>>s;
    	if (s=="?")
    	{
    		qm++;
    	}
    	}
    	if (isqm)
    	{
    		if ((n+1-qm)%2) cout<<"Yes"; else cout<<"No";
    	}
    	else
    	if (s0=="0") cout<<"Yes"; else cout<<"No";
    }
    else
    {
    	for (i=0;i<=n;i++)
    	{
    		string s;
    		cin>>s;
    		if (s=="?")
    		{
    			if ((n+1)%2) cout<<"No"; else cout<<"Yes";
    			return 0;
    		}
    		else
    		{
    			coeff[i]=stoi(s);
    		}
    	}
    	ll val=0;
    	for (i=n;i>=0;i--)
    	{
    		if (abs(val)>=1e9)
    		{
    			cout<<"No"; return 0;
    		}
  //  		cout<<coeff[i]<<' ';
    		val*=k;
    		val+=coeff[i];
    		if (abs(val)>=1e9)
    		{
    			cout<<"No"; return 0;
    		}
    	}
    	if (val) cout<<"No"; else cout<<"Yes";
    }
}