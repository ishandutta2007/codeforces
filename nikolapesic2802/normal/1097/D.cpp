#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

#define ll long long
#define pb push_back
#define sz(x) (int)(x).size()
#define mp make_pair
#define f first
#define s second
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a) {
	os << '{';
	for(int i=0;i<sz(a);i++)
	{
		if(i>0&&i<sz(a)-1)
			os << ", ";
		os << a[i];
	}
	os << '}';
    return os;
}
const int mod=1e9+7;
int add(int x,int y){x+=y;if(x>=mod)x-=mod;return x;}
int mul(int x,int y){return (ll)x*y%mod;}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,x=mul(x,x))if(k&1)ans=mul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}
int main()
{
    ll n;
    int k;
    scanf("%lld %i",&n,&k);
    vector<pair<ll,int> > fact;
    for(int i=2;(ll)i*i<=n;i++)
    {
        int cnt=0;
        while(n%i==0)
        {
            cnt++;
            n/=i;
        }
        if(cnt)
        fact.pb({i,cnt});
    }
    if(n>1)
        fact.pb({n,1});
    int ans=1;
    for(auto p:fact)
    {
        int cnt=p.second;
        vector<vector<int> > dp(k+1,vector<int>(cnt+1,0));
        dp[0][cnt]=1;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<=cnt;j++)
            {
                int a=mul(dp[i][j],inv(j+1));
                for(int k=0;k<=j;k++)
                {
                    dp[i+1][k]=add(dp[i+1][k],a);
                }
            }
        }
        int x=p.first%mod;
        int t=1;
        int br=0;
        for(int i=0;i<=cnt;i++)
        {
            br=add(br,mul(dp[k][i],t));
            t=mul(t,x);
        }
        ans=mul(ans,br);
    }
    printf("%i\n",ans);
    return 0;
}