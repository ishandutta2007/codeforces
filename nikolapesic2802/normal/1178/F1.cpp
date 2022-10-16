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
#define D(x) cerr << #x << " is " << (x) << "\n";

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=501,mod=998244353;
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int mul(int a,int b)
{
    return (ll)a*b%mod;
}
int dp[N][N];
int c[N];
int n;
int calc(int l,int r)
{
    if(l>r)
        return 1;
    if(dp[l][r]!=-1)
        return dp[l][r];
    int minn=INT_MAX,gde=0;
    for(int i=l;i<=r;i++)
        if(c[i]<minn)
            minn=c[i],gde=i;
    int sum=calc(gde+1,r);
    for(int i=gde+1;i<=r;i++)
        sum=add(sum,mul(calc(i,r),calc(gde+1,i-1)));
    dp[l][r]=mul(sum,calc(l,gde-1));
    for(int i=l;i<gde;i++)
        dp[l][r]=add(dp[l][r],mul(sum,mul(calc(l,i),calc(i+1,gde-1))));
    return dp[l][r];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    scanf("%i %i",&n,&n);
    for(int i=0;i<n;i++)
        scanf("%i",&c[i]);
    printf("%i\n",calc(0,n-1));
}