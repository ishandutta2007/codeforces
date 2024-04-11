
// Problem : C. Little Elephant and Furik and Rubik
// Contest : Codeforces - Codeforces Round #129 (Div. 1)
// URL : https://codeforces.com/problemset/problem/204/C
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
ll n,m,k,c[501],pos[100001],t1,i,j; double res,tar;
vector<ll> buc[26],presum[26];
string s,t;
int main()
{
//  ofile;
    fio;
    cin>>n;
    cin>>s>>t;
    for (i=1;i<=n;i++) tar+=i*i;
    for (i=0;i<26;i++) presum[i].push_back(0);
    for (i=0;i<n;i++)
    {
    	m=t[i]-65;
    	buc[m].push_back(i);
    	presum[m].push_back(presum[m][presum[m].size()-1]+i);
    }
    for (i=0;i<n;i++)
    {
    	m=s[i]-65;
    	k=upper_bound(buc[m].begin(),buc[m].end(),i)-buc[m].begin();
    	ll l=presum[m][k],r=presum[m][buc[m].size()]-presum[m][k];
    	res+=double(l+k)*(n-i)/tar;
    	res+=double(n*(buc[m].size()-k)-r)*(i+1)/tar;
    }
    
//    cout<<res<<endl;
    cout<<fixed<<setprecision(9)<<double(res);
}