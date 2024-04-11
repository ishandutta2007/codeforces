/*
	Normie's Template v2.0
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
 
// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Custom min/max, so I dont have to deal with nasty compile errors.
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//Constants.
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
//--------------------------//
//---------END-------//
ll n,m,i,j,u,t,k,v,arr[100001],cash,po,len,xl,xr,yl,yr,res=0;
ll cnt[2001][2001];
ll pre[2001][2001];
ll fac[2001],inv[2001];
ll xx[2001],yy[2001],ss[2001];
vector<ll> lis;
ll bow (ll a, ll x)
{
    if (!x) return 1;
    ll res=bow(a,x/2);
    res*=res;
    res%=MOD;
    if (x%2) res*=a;
    return res%MOD;
}
int main()
{
	fio;
	cin>>n>>m>>k;
	for (i=1;i<=n;i++)
	{
	    cin>>xx[i]>>yy[i]>>ss[i];
	    cnt[xx[i]][yy[i]]++;
	}
	for (i=1;i<=1000;i++)
	{
	for (j=1;j<=1000;j++)
	{
	    pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+cnt[i][j];
	//    cout<<pre[i][j]<<' ';
	}
//	cout<<endl;
	}
	fac[0]=1;
	inv[0]=1;
	for (i=1;i<=2000;i++)
	{
	    fac[i]=fac[i-1]*i;
	    fac[i]%=MOD;
	    inv[i]=bow(fac[i],MOD-2);
	}
	for (i=1;i<=n;i++)
	{
	    xl=max(xx[i]-k,1);
	    yl=max(yy[i]-k,1);
	    xr=min(xx[i]+k,1000);
	    yr=min(yy[i]+k,1000);
//	    cout<<xl<<' '<<yl<<' '<<xr<<' '<<yr<<endl;
	    ll cnt=(pre[xr][yr]-pre[xl-1][yr]-pre[xr][yl-1]+pre[xl-1][yl-1]);
	    ll cur1=1;
//	    cout<<"cnt="<<cnt<<endl;
	    cur1*=fac[n]; cur1%=MOD;
	    cur1*=inv[n-m]; cur1%=MOD;
	    cur1*=inv[m]; cur1%=MOD;
//	        cout<<"+ "<<i<<' '<<cur1<<endl;
	        cur1*=ss[i]; cur1%=MOD;
	    res+=(cur1*ss[i])%MOD;
	        res%=MOD;
	    if (n-cnt>=m)
	    {
	        cur1=1;
	        cur1*=fac[n-cnt]; cur1%=MOD;
	        cur1*=inv[n-cnt-m]; cur1%=MOD;
	        cur1*=inv[m]; cur1%=MOD;
//	        cout<<"- "<<i<<' '<<cur1<<endl;
	        cur1*=ss[i]; cur1%=MOD;
	        res-=(cur1*ss[i])%MOD;
	        res+=MOD;
	        res%=MOD;
	    }
	}
	for (i=1;i<=n;i++) for (j=i+1;j<=n;j++)
	{
//	    cout<<i<<' '<<j<<endl;
	    ll cnt1,cnt2,cnt00,cnt01,cnt10,cnt11;
	    ll cur1=0;
	    xl=max(xx[i]-k,1);
	    yl=max(yy[i]-k,1);
	    xr=min(xx[i]+k,1000);
	    yr=min(yy[i]+k,1000);
	    cnt1=(pre[xr][yr]-pre[xl-1][yr]-pre[xr][yl-1]+pre[xl-1][yl-1]);
	    
	    xl=max(xx[j]-k,1);
	    yl=max(yy[j]-k,1);
	    xr=min(xx[j]+k,1000);
	    yr=min(yy[j]+k,1000);
	    cnt2=(pre[xr][yr]-pre[xl-1][yr]-pre[xr][yl-1]+pre[xl-1][yl-1]);
	    
	    
	    xl=max(xx[i]-k,xl);
	    yl=max(yy[i]-k,yl);
	    xr=min(xx[i]+k,xr);
	    yr=min(yy[i]+k,yr);
	    if ((xl<=xr)and(yl<=yr))
	    cnt11=(pre[xr][yr]-pre[xl-1][yr]-pre[xr][yl-1]+pre[xl-1][yl-1]);
	    else cnt11=0;
//	    cout<<cnt1<<' '<<cnt2<<endl;
	    cnt10=cnt1-cnt11;
	    cnt01=cnt2-cnt11;
	    cnt00=n-cnt01-cnt10-cnt11;
//	    cout<<cnt00<<' '<<cnt01<<endl;
//	    cout<<cnt10<<' '<<cnt11<<endl;
	    
	    if (n>=m)
	    {
	        cur1=1;
	        cur1*=fac[n]; cur1%=MOD;
	        cur1*=inv[n-m]; cur1%=MOD;
	        cur1*=inv[m]; cur1%=MOD;
//	        cout<<"+ "<<' '<<cur1<<endl;
	        cur1*=ss[i]; cur1%=MOD;
	        res+=(cur1*2*ss[j])%MOD;
	        res+=MOD;
	        res%=MOD;
	    }
	    
	    
	    if (cnt10+cnt00>=m)
	    {
	        cur1=1;
	        cur1*=fac[cnt10+cnt00]; cur1%=MOD;
	        cur1*=inv[cnt10+cnt00-m]; cur1%=MOD;
	        cur1*=inv[m]; cur1%=MOD;
//	        cout<<"- "<<' '<<cur1<<endl;
	        cur1*=ss[i]; cur1%=MOD;
	        res-=(cur1*2*ss[j])%MOD;
	        res+=MOD;
	        res%=MOD;
	    }
	    
	    
	    if (cnt01+cnt00>=m)
	    {
	        cur1=1;
	        cur1*=fac[cnt01+cnt00]; cur1%=MOD;
	        cur1*=inv[cnt01+cnt00-m]; cur1%=MOD;
	        cur1*=inv[m]; cur1%=MOD;
//	        cout<<"- "<<' '<<cur1<<endl;
	        cur1*=ss[i]; cur1%=MOD;
	        res-=(cur1*2*ss[j])%MOD;
	        res+=MOD;
	        res%=MOD;
	    }
	    
	    
	    if (cnt00>=m)
	    {
	        cur1=1;
	        cur1*=fac[cnt00]; cur1%=MOD;
	        cur1*=inv[cnt00-m]; cur1%=MOD;
	        cur1*=inv[m]; cur1%=MOD;
//	        cout<<"+ "<<' '<<cur1<<endl;
	        cur1*=ss[i]; cur1%=MOD;
	        res+=(cur1*2*ss[j])%MOD;
	        res+=MOD;
	        res%=MOD;
	    }
	    
	}
	cout<<res;
}