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

const int mod=1e9+7,N=2e5+5;
int mul(int a,int b)
{
    return (ll)a*b%mod;
}
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b)
{
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int powmod(int x,int k=mod-2)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
vector<int> fact,ifact(N);
int nCk(int n,ll k)
{
    if(n<k)
        return 0;
    return mul(mul(fact[n],ifact[k]),ifact[n-k]);
}
int main()
{
    fact.pb(1);
    for(int i=1;i<N;i++)
        fact.pb(mul(fact.back(),i));
    ifact[N-1]=powmod(fact[N-1]);
    for(int i=N-2;i>=0;i--)
        ifact[i]=mul(ifact[i+1],i+1);
	int n;
	ll t;
	scanf("%i %lld",&n,&t);
	int ans=0;
	vector<ll> a(n+1);
	for(int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        if(i)
            a[i]+=a[i-1];
    }
    a[n]=t+1;
	for(int i=0;i<n;i++)
    {
        for(ll k=min((ll)i+1,t-a[i]);k>max((ll)-1,t-a[i+1]);k--)
            ans=add(ans,mul(mul(nCk(i+1,k),powmod(powmod(2,i+2))),i+1));
        for(ll k=min((ll)i+1,t-a[i]);k>=max((ll)0,t-a[i+1]);k--)
            ans=add(ans,mul(mul(nCk(i+1,k),powmod(powmod(2,i+2))),i+1));
    }
    printf("%i\n",ans);
    return 0;
}