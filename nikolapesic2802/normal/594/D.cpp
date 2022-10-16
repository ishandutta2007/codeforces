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
const int N=2e5+5,M=1e6+5,mod=1e9+7;
vector<int> factor(M);
int mul(int a,int b)
{
    return (ll)a*b%mod;
}
int powmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
vector<int> inv(M);
vector<vector<int> > factors(N);
vector<vector<int> > mesta(M);
struct segTree{
    vector<int> m;
    void init()
    {
        m.resize(4*N,1);
    }
    void update(int i)
    {
        m[i]=mul(m[2*i],m[2*i+1]);
    }
    void multi(int pos,int k,int l=0,int r=N-1,int i=1)
    {
        if(l>pos||r<pos)
            return;
        if(l==pos&&r==pos)
        {
            m[i]=mul(m[i],k);
            return;
        }
        int mi=(l+r)>>1;
        multi(pos,k,l,mi,2*i);
        multi(pos,k,mi+1,r,2*i+1);
        update(i);
    }
    int get(int qs,int qe,int l=0,int r=N-1,int i=1)
    {
        if(qs>r||qe<l)
            return 1;
        if(qs<=l&&qe>=r)
            return m[i];
        int mi=(l+r)>>1;
        return mul(get(qs,qe,l,mi,2*i),get(qs,qe,mi+1,r,2*i+1));
    }
}st;
int main()
{
    st.init();
    for(int i=1;i<M;i++)
        inv[i]=powmod(i,mod-2);
    vector<int> primes;
    for(int i=2;i<M;i++)
    {
        if(!factor[i])
            primes.pb(i),factor[i]=i;
        for(auto p:primes)
        {
            if((ll)p*i>=M)
                break;
            factor[p*i]=p;
            if(i%p==0)
                break;
        }
    }
	int n;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        st.multi(i,a);
        while(a!=1)
        {
            factors[i].pb(factor[a]);
            mesta[factor[a]].pb(i);
            a/=factor[a];
        }
    }
    for(int i=2;i<M;i++)
    {
        reverse(all(mesta[i]));
        if(mesta[i].size())
        {
            int gde=mesta[i].back();
            st.multi(gde,i-1);
            st.multi(gde,inv[i]);
        }
    }
    vector<vector<pair<int,int> > > qu(n);
    int q;
    scanf("%i",&q);
    vector<int> sol(q);
    for(int i=0;i<q;i++)
    {
        int l,r;
        scanf("%i %i",&l,&r);
        l--;r--;
        qu[l].pb({r,i});
    }
    for(int i=0;i<n;i++)
    {
        for(auto p:qu[i])
            sol[p.s]=st.get(i,p.f);
        for(auto p:factors[i])
        {
            mesta[p].pop_back();
            if(mesta[p].size())
            {
                int gde=mesta[p].back();
                st.multi(gde,p-1);
                st.multi(gde,inv[p]);
            }
        }
    }
    for(int i=0;i<q;i++)
        printf("%i\n",sol[i]);
    return 0;
}