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

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
const int mod=998244353;
int pwrmod(int x,int k){int ans=1;for(;k>0;k>>=1,x=(ll)x*x%mod)if(k&1>0)ans=(ll)ans*x%mod;return ans;}
vector<int> ntt(vector<int> p,int inv)
{
    int n=p.size();
    if(n==1)
        return p;
    vector<int> l,r;
    for(int i=0;i<n;i++)
        if(i%2==0)
            l.pb(p[i]);
        else
            r.pb(p[i]);
    l=ntt(l,inv);
    r=ntt(r,inv);
    int ang=pwrmod(3,(mod-1)/n);
        if(inv) ang=pwrmod(ang,mod-2);
    vector<int> ans(n);
    int cur=1;
    for(int k=0;k<n/2;k++)
    {
        ans[k]=(l[k]+(ll)cur*r[k]%mod)%mod;
        ans[k+n/2]=(l[k]-(ll)cur*r[k]%mod+mod)%mod;
        cur=(ll)cur*ang%mod;
    }
    return ans;
}
int main()
{
    int n,k,p,sz=1;
    scanf("%i %i",&n,&k);
    vector<int> x(10);
    while(k--)scanf("%i",&p),x[p]++;
    while(sz<5*n)
        sz<<=1;
    x.resize(sz);
    x=ntt(x,0);
    for(int i=0;i<x.size();i++) x[i]=pwrmod(x[i],n/2);
    x=ntt(x,1);
    int ii=pwrmod(sz,mod-2);
    for(auto &p:x)
        p=(ll)p*ii%mod;
    int sol=0;
    for(auto p:x)
        sol+=(ll)p*p%mod,sol%=mod;
    printf("%i\n",sol);
    return 0;
}