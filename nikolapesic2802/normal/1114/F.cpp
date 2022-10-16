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
const int mod=1e9+7;
int powmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=(ll)x*x%mod)
    {
        if(k&1)
            ans=(ll)ans*x%mod;
    }
    return ans;
}
vector<int> primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293};
vector<int> inv(64);
int N=4e5+5;
struct segTree{
    vector<ll> primes;
    vector<ll> lazy;
    void init()
    {
        primes.resize(4*N);
        lazy.resize(4*N);
    }
    void prop(int i)
    {
        primes[2*i]|=lazy[i];
        primes[2*i+1]|=lazy[i];
        lazy[2*i]|=lazy[i];
        lazy[2*i+1]|=lazy[i];
        lazy[i]=0;
    }
    void update(int i)
    {
        primes[i]=primes[2*i]|primes[2*i+1];
    }
    void add(int qs,int qe,ll x,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            lazy[i]|=x;
            primes[i]|=x;
            return;
        }
        int m=(l+r)>>1;
        prop(i);
        add(qs,qe,x,l,m,2*i);
        add(qs,qe,x,m+1,r,2*i+1);
        update(i);
    }
    ll get(int qs,int qe,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return 0;
        if(qs<=l&&qe>=r)
        {
            return primes[i];
        }
        int m=(l+r)>>1;
        prop(i);
        return get(qs,qe,l,m,2*i)|get(qs,qe,m+1,r,2*i+1);
    }
}st;
struct mulsegTree{
    vector<int> mul;
    vector<int> lazy_mul;
    void init()
    {
        mul.resize(4*N,1);
        lazy_mul.resize(4*N,1);
    }
    void prop(int i,int l,int r)
    {
        int m=(l+r)>>1;
        mul[2*i]=(ll)mul[2*i]*powmod(lazy_mul[i],m-l+1)%mod;
        lazy_mul[2*i]=(ll)lazy_mul[2*i]*lazy_mul[i]%mod;
        mul[2*i+1]=(ll)mul[2*i+1]*powmod(lazy_mul[i],r-m)%mod;
        lazy_mul[2*i+1]=(ll)lazy_mul[2*i+1]*lazy_mul[i]%mod;
        lazy_mul[i]=1;
    }
    void update(int i)
    {
        mul[i]=(ll)mul[2*i]*mul[2*i+1]%mod;
    }
    void add(int qs,int qe,int x,int l=0,int r=N-1,int i=1)
    {

        if(qs>r||qe<l)
            return;
        if(qs<=l&&qe>=r)
        {
            lazy_mul[i]=(ll)lazy_mul[i]*x%mod;
            mul[i]=(ll)mul[i]*powmod(x,r-l+1)%mod;
            return;
        }
        int m=(l+r)>>1;
        prop(i,l,r);
        add(qs,qe,x,l,m,2*i);
        add(qs,qe,x,m+1,r,2*i+1);
        update(i);
    }
    int get(int qs,int qe,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return 1;
        if(qs<=l&&qe>=r)
        {
            return mul[i];
        }
        int m=(l+r)>>1;
        prop(i,l,r);
        return (ll)get(qs,qe,l,m,2*i)*get(qs,qe,m+1,r,2*i+1)%mod;
    }
}st2;
vector<ll> mask(301);
int main()
{
    for(int i=0;i<primes.size();i++)
    {
        inv[i]=(1-powmod(primes[i],mod-2)+mod)%mod;
    }
    for(int i=1;i<=300;i++)
    {
        for(int j=0;j<primes.size();j++)
        {
            if(i%primes[j]==0)
                mask[i]|=(1LL<<j);
        }
    }
	int n,q;
	scanf("%i %i",&n,&q);
	N=n;
	st.init();
    st2.init();
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        st2.add(i,i,a);
        st.add(i,i,mask[a]);
    }
    while(q--)
    {
        char niz[8];
        scanf("%s",niz);
        if(niz[0]=='T')
        {
            int l,r;
            scanf("%i %i",&l,&r);
            l--;
            r--;
            ll sol=st.get(l,r);
            int ans=st2.get(l,r);
            //printf("%i\n",ans);
            for(int j=0;j<primes.size();j++)
            {
                if(sol&(1LL<<j))
                {
                    ans=(ll)ans*inv[j]%mod;
                }
            }
            printf("%i\n",ans);
        }
        else
        {
            int l,r,x;
            scanf("%i %i %i",&l,&r,&x);
            l--;
            r--;
            st2.add(l,r,x);
            st.add(l,r,mask[x]);
        }
    }
    return 0;
}