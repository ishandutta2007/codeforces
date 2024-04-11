
// Problem : B. PIN Codes
// Contest : Codeforces - Codeforces Round #603 (Div. 2)
// URL : https://codeforces.com/contest/1263/problem/B
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
int n,m,k,c[501],pos[100001],t,t1,i,j;
vector<pair<string,int>> lis;
int main()
{
//  ofile;
    fio;
    cin>>t;
    for (t1=0;t1<t;t1++)
    {
    	cin>>n;
    	lis.clear();
    		string s;
    	for (i=0;i<n;i++)
    	{
    		cin>>s;
    		lis.push_back({s,i});
    	}
    	sort(lis.begin(),lis.end(),[](pair<string,int> a, pair<string,int> b){
    		return (a.fi<b.fi);
    	});
    	j=0; m=0;
    	for (i=1;i<n;i++)
    	{
    		if (lis[j].fi==lis[i].fi)
    		{
    			m++;
    			for (k=0;k<10;k++)
    			{
    				s=lis[i].fi;
    				s[3]=char((s[3]-48+1)%10+48);
    				ll fail=0;
    				for (int ii=0;ii<n;ii++)
    				{
    					if (lis[ii].fi==s){
    						fail=1;
    						break;
    					}
    				}
    				if (fail==0)
    				{
    					lis[i].fi=s;
    					break;
    				}
    				else
    				{
    					lis[i].fi=s;
    				}
    			}
    		}
    		else j=i;
    	}
    	cout<<m<<endl;
    	sort(lis.begin(),lis.end(),[](pair<string,int> a, pair<string,int> b){
    		return (a.se<b.se);
    	});
    	for (i=0;i<n;i++) cout<<lis[i].fi<<endl;
    }
}