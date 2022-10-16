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
vector<ll> a(N),b(N);
int n,k;
bool test(ll p)
{
    vector<vector<pair<ll,ll> > > events(k+1);
    for(int i=0;i<n;i++)
        if(a[i]/b[i]<k)
            events[a[i]/b[i]].pb({a[i],b[i]});
    int tr=0;
    for(int i=0;i<k;i++)
    {
        while(events[tr].size()==0&&tr<k)
            tr++;
        if(tr==k)
            return true;
        if(tr<i)
            return false;
        pair<ll,ll> cur=events[tr].back();
        events[tr].pop_back();
        if((cur.f+p)/cur.s<k)
            events[(cur.f+p)/cur.s].pb({cur.f+p,cur.s});
    }
    return true;
}
int main()
{
	scanf("%i %i",&n,&k);
	for(int i=0;i<n;i++)
        scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%lld",&b[i]);
    ll lim=3e12;
    ll l=0,r=lim;
    while(l<r)
    {
        ll mid=(l+r)>>1;
        if(test(mid))
            r=mid;
        else
            l=mid+1;
    }
    if(l==lim)
        l=-1;
    printf("%lld\n",l);
    return 0;
}