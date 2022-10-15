
// Problem : C. Necklace
// Contest : Codeforces - Codeforces Round #339 (Div. 1)
// URL : https://codeforces.com/problemset/problem/613/C
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
int n;
int a[33];
int main()
{
	fio;
	cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1)
    {
        cout<<a[1]<<endl;
        for(int i=1;i<=a[1];i++) cout<<"a";
        return 0;
    }
    int odd=0,ned;
    string rep;
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)
        {
            odd++;
            ned=i;
            if(odd>1)
            {
            	cout<<0<<endl;
                for(int j=1;j<=n;j++)
                {
                    for(int k=1;k<=a[j];k++) cout<<char('a'+j-1);
                }
                return 0;
            }
        }
        for(int j=0;j<a[i]/2;j++) rep.push_back(i+'a'-1);
    }
    int ans=0;
    rep.clear();
    for(int i=1;i<=n;i++)
    {
        ans=__gcd(ans,a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int t=a[i]/ans;
        if(odd)t/=2;
        for(int j=0;j<t;j++)rep.push_back('a'+i-1);
    }
    string tp=rep;
    reverse(tp.begin(),tp.end());
    cout<<ans<<endl;
    if(odd)
    {
        rep.push_back('a'+ned-1);
        rep+=tp;
        for(int i=0;i<ans;i++)cout<<rep;
        cout<<endl;
    }
    else
    {
        for(int i=0;i<ans;i++)
        {
            if(i%2==0)cout<<rep;
            else cout<<tp;
        }
        cout<<endl;
    }
}