
// Problem : C. Boboniu and String
// Contest : Codeforces - Codeforces Round #664 (Div. 1)
// URL : https://codeforces.com/contest/1394/problem/C
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
#define pii pair<ll,ll>
#define piii pair<ll,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,c[501],pos[100001],t,t1,i,j;
string s;
vector<pii> points;
pii check (ll dis)
{
//	cout<<"check "<<dis<<endl;
	ll lx=0,rx=1e9,ly=0,ry=1e9,ld=-1e9,rd=1e9;
	for (pii pp : points)
	{
		rx=min(rx,pp.fi+dis);
		lx=max(lx,pp.fi-dis);
		ry=min(ry,pp.se+dis);
		ly=max(ly,pp.se-dis);
		rd=min(rd,pp.fi-pp.se+dis);
		ld=max(ld,pp.fi-pp.se-dis);
	//	cout<<lx<<' '<<rx<<' '<<ly<<' '<<ry<<' '<<ld<<' '<<rd<<endl;
	}
	if (lx>rx) return pii({-1,-1});
	if (ly>ry) return pii({-1,-1});
	ld=max(ld,lx-ry);
	rd=min(rd,rx-ly);
	if (ld>rd) return pii({-1,-1});
	ll choice;
	if (ld<0) choice=ld;
	else if (rd>0) choice=rd;
	else choice=0;
	if (choice==0)
	{
	lx=max(lx,ly+choice);
	rx=min(rx,ry+choice);
	if (lx<0)
	return pii({lx,lx-choice});
	else if (rx>0)
	return pii({rx,rx-choice});
	else return pii({-1,-1});
	}
	else
	{
		
	lx=max(lx,ly+choice);
	rx=min(rx,ry+choice);
	return pii({lx,lx-choice});
	}
}
piii bs (ll l, ll r)
{
	if (l==r) return piii({l,check(l)});
	ll mid=(l+r)/2;
	pii test=check(mid);
	if (test.fi>=0) return bs(l,mid); else return bs(mid+1,r);
}
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=1;i<=n;i++)
    {
    	cin>>s;
    	ll px=0,py=0;
    	for (j=1;j<=s.length();j++)
    	{
    		if (s[j-1]=='B') px++;
    		else py++;
    	}
    	points.push_back({px,py});
 //   	cout<<px<<' '<<py<<endl;
    }
    piii res=bs(0,500000);
    cout<<res.p1<<endl;
//    cout<<res.p2<<' '<<res.p3<<endl;
    for (i=0;i<res.p2;i++) cout<<"B";
    for (i=0;i<res.p3;i++) cout<<"N";
}