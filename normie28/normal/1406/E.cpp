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
//#define endl "\n"
#define bi BigInt
typedef long long ll;
//---------END-------//
ll n,m,k,c[501],pos[100001],t,t1,i,j,res=1;
ll sv[100001];
vector<ll> pr,facs;
void proc(ll g)
{
	ll mul=1;
	for (mul=g;mul<=n;mul*=g)
	{
		cout<<"A "<<mul<<endl;
		cin>>t;
		if (!t) break;
	}
	res*=mul/g;
}
int main()
{
//  ofile;
    fio;
    cin>>n;
    for (i=2;i<=n;i++) sv[i]=1;
    for (i=2;i<=n;i++) if (sv[i])
    {
    	pr.push_back(i);
    	for (j=i*i;j<=n;j+=i) sv[j]=0;
    }
    for (ll g :pr) if (g*g<=n)
    {
    	cout<<"B "<<g<<endl;
    	cin>>t;
    }
    for (ll g :pr) if (g*g<=n)
    {
    	cout<<"A "<<g<<endl;
    	cin>>t;
    	{
    		if (t>0) facs.push_back(g);
    	}
    }
    if (facs.size())
    {
    for (ll g :pr) if (g*g>n)
    {
    	cout<<"A "<<g<<endl;
    	cin>>t;
    	{
    		if (t>1) facs.push_back(g);
    	}
    }
    }
    else
    {
    	vector<ll> pr2;
    	random_shuffle(pr.begin(),pr.end());
    for (ll g :pr) if (g*g>n)
    {
    	pr2.push_back(g);
    }
    	ll sectsz=floor(sqrt(pr2.size()));
    	ll prev;
    	cout<<"A "<<1<<endl;
    	cin>>prev;
    	for (i=0;i<pr2.size();i+=sectsz)
    	{
    		for (j=i;j<min(pr2.size(),i+sectsz);j++) {
			cout<<"B "<<pr2[j]<<endl; cin>>t;}
			cout<<"A "<<1<<endl;
			cin>>t;
			if (t+min(pr2.size(),i+sectsz)-i!=prev)
			for (j=i;j<min(pr2.size(),i+sectsz);j++) 
			{
			cout<<"A "<<pr2[j]<<endl; cin>>t;
			if (t) 
			{
				cout<<"C "<<pr2[j]<<endl;
				return 0;
			}
			}
			prev=t;
		}
    }
    for (ll g : facs) proc(g);
    cout<<"C "<<res<<endl;
}