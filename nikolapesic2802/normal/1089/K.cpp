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
int N=1e6+5;
vector<ll> maxx(4*N),lazy(4*N);
void prop(int i)
{
    maxx[2*i]+=lazy[i];
    maxx[2*i+1]+=lazy[i];
    lazy[2*i+1]+=lazy[i];
    lazy[2*i]+=lazy[i];
    lazy[i]=0;
}
void add(int qs,int qe,int x,int l=0,int r=N-1,int i=1)
{
    if(qs>r||qe<l)
        return;
    if(qs<=l&&qe>=r)
    {
        maxx[i]+=x;
        lazy[i]+=x;
        return;
    }
    prop(i);
    int m=(l+r)>>1;
    add(qs,qe,x,l,m,2*i);
    add(qs,qe,x,m+1,r,2*i+1);
    maxx[i]=max(maxx[2*i+1],maxx[2*i]);
}
ll get(int qs,int qe,int l=0,int r=N-1,int i=1)
{
    if(qs>r||qe<l)
        return LLONG_MIN;
    if(qs<=l&&qe>=r)
        return maxx[i];
    prop(i);
    int m=(l+r)>>1;
    return max(get(qs,qe,l,m,2*i),get(qs,qe,m+1,r,2*i+1));
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<pair<int,int> > mapa(n);
    for(int i=0;i<N;i++)
        add(i,i,i-N);
    for(int i=0;i<n;i++)
    {
        char c;
        cin >> c;
        if(c=='?')
        {
            int a;
            scanf("%i",&a);
            printf("%lld\n",get(0,a)-get(a+1,a+1)+1);
        }
        if(c=='+')
        {
            int p,q;
            scanf("%i %i",&p,&q);
            mapa[i]={p,q};
            add(0,p,q);
        }
        if(c=='-')
        {
            int a;
            scanf("%i",&a);
            add(0,mapa[a-1].f,-mapa[a-1].s);
        }
    }
}