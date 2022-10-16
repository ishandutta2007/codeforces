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

int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	vector<pair<ll,ll> > islands(n);
	ll b;
	for(int i=0;i<n;i++)
        scanf("%lld %lld",&islands[i].f,&islands[i].s);
    vector<pair<ll,ll> > intervals;
    ///LLONG_MAX=query
    vector<pair<ll,pair<ll,int> > > querys;
    for(int i=0;i<n-1;i++)
        querys.pb({islands[i+1].f-islands[i].s,{islands[i+1].s-islands[i].f,i}});
    for(int i=0;i<m;i++)
        scanf("%lld",&b),querys.pb({b,{LLONG_MAX,i+1}});
    sort(all(querys));
    set<pair<ll,int> > q;
    vector<int> sol(n);
    int dodao=0;
    for(auto p:querys)
    {
        //cout << p << endl;
        if(p.s.f!=LLONG_MAX)
        {
            q.insert(p.s);
            continue;
        }
        if(q.size()==0)
            continue;
        ll minn=(*q.begin()).f;
        if(minn<p.f)
        {
            printf("No\n");
            return 0;
        }
        dodao++;
        sol[(*q.begin()).s]=p.s.s;
        q.erase(q.begin());
    }
    if(dodao!=n-1)
    {
        printf("No\n");
        return 0;
    }
    printf("Yes\n");
    for(int i=0;i<n-1;i++)
        printf("%i ",sol[i]);
    return 0;
}