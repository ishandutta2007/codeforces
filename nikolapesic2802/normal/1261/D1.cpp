#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()

using namespace std;
using namespace __gnu_pbds;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}

const int N=2e3+5,mod=998244353;
int add(int a,int b){a+=b;if(a>=mod)a-=mod;return a;}
int sub(int a,int b){a-=b;if(a<0)a+=mod;return a;}
int mul(int a,int b){return (ll)a*b%mod;}
vector<int> a(N);
int n,k;
int dp[N][2*N];
int calc(int tr,int o)
{
    if(tr==n)
        return o==N;
    if(dp[tr][o]!=-1)
        return dp[tr][o];
    if(a[tr]==a[tr+1])
        return dp[tr][o]=mul(k,calc(tr+1,o));
    return dp[tr][o]=add(add(mul(k-2,calc(tr+1,o)),calc(tr+1,o-1)),calc(tr+1,o+1));
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
    scanf("%i %i",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    a[n]=a[0];
    int sol=0;
    for(int i=1;i<=n;i++)
        sol=add(sol,calc(0,i+N));
    printf("%i\n",sol);
    return 0;
}