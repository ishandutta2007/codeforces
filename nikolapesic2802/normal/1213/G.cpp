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

const int N=2e5+5;
vector<int> par(N),siz(N);
int find(int tr){return tr==par[tr]?tr:par[tr]=find(par[tr]);}
ll sol=0;
int merge(int a,int b){sol+=(ll)siz[find(b)]*siz[find(a)];siz[find(b)]+=siz[find(a)];par[find(a)]=find(b);}
int main()
{
    for(int i=0;i<N;i++)
        par[i]=i,siz[i]=1;
    int n,q,a,b,c;
    scanf("%i %i",&n,&q);
    vector<pair<int,pair<int,int> > > e;
    for(int i=1;i<n;i++)
        scanf("%i %i %i",&a,&b,&c),e.pb({c,{a,b}});
    vector<pair<int,int> > qq;
    vector<ll> ans(q);
    for(int i=0;i<q;i++)
        scanf("%i",&a),qq.pb({a,i});
    sort(all(qq));
    qq.pb({INT_MAX,-1});
    sort(all(e));
    int tr=0;
    for(auto p:e)
    {
        while(qq[tr].f<p.f)
            ans[qq[tr].s]=sol,tr++;
        merge(p.s.f,p.s.s);
    }
    while(tr<q)
        ans[qq[tr].s]=sol,tr++;
    for(int i=0;i<q;i++)
        printf("%lld ",ans[i]);
}