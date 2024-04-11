
// Problem : C. XOR Inverse
// Contest : Codeforces - Codeforces Round #673 (Div. 1)
// URL : https://codeforces.com/contest/1416/problem/C
// Memory Limit : 512 MB
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
int n,m,k,c[501],arr[300001],t,t1,i,j;
int lef[10000001],rig[10000001];
vector<int> poss[10000001];
ll prof[2][33];
void build(int curn,int dep,int ind,int elm)
{
	poss[curn].push_back(elm);
	if (dep==-1) return;
	if ((ind>>dep)%2==0)
	{
		if (!lef[curn]) 
		{
			t++;
			lef[curn]=t;
		}
		build(lef[curn],dep-1,ind,elm);
	}
	else
	{
		if (!rig[curn]) 
		{
			t++;
			rig[curn]=t;
		}
		build(rig[curn],dep-1,ind,elm);
	}
}
void check (int curn, int dep)
{
	if (dep<0) return;
	int j=0;
	for (int g : poss[lef[curn]])
	{
		while ((j<poss[rig[curn]].size())and(poss[rig[curn]][j]<g)) 
		{
			j++;
		}
		prof[0][dep]+=j;
	}
	j=0;
	for (int g : poss[rig[curn]])
	{
		while ((j<poss[lef[curn]].size())and(poss[lef[curn]][j]<g)) 
		{
			j++;
		}
		prof[1][dep]+=j;
	}
	if (lef[curn]) check(lef[curn],dep-1);
	if (rig[curn]) check(rig[curn],dep-1);
}
int main()
{
//  ofile;
    fio;
    cin>>n;
    t=1;
    for (i=1;i<=n;i++)
    {
    	cin>>arr[i];
    	build(1,29,arr[i],i);
    }
    check(1,29);
    ll fin=0;
    for (i=29;i>=0;i--)
    {
    	if (prof[0][i]<=prof[1][i]) fin+=prof[0][i];
    	else
    	{
    		t1+=(1<<i);
    		fin+=prof[1][i];
    	}
    }
    cout<<fin<<' '<<t1<<endl;
}