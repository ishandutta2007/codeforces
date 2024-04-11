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

pair<pair<int,int>,int> solve1d(vector<pair<pair<int,int>,int> > x)
{
    vector<pair<int,int> > d;
    for(auto p:x)
        d.pb({p.f.s,p.s});
    sort(all(d));
    int n=d.size();
    for(int i=0;i<n/2;i++)
        printf("%i %i\n",d[2*i].s,d[2*i+1].s);
    return {{x.front().f.f,d.back().f},d.back().s};
}
pair<pair<int,int>,pair<int,int> > solve2d(vector<pair<pair<int,int>,pair<int,int> > > x)
{
    vector<pair<pair<int,int>,int> > d,novi,tr;
    for(auto p:x)
        d.pb({{p.f.s,p.s.f},p.s.s});
    sort(all(d));
    int n=d.size();
    d.pb({{INT_MIN,-1},-1});
    for(int i=0;i<n;i++)
    {
        tr.pb(d[i]);
        if(d[i].f.f!=d[i+1].f.f)
        {
            if(tr.size()%2)
                novi.pb(solve1d(tr));
            else
                solve1d(tr);
            tr.clear();
        }
    }
    if(novi.empty())
    {
        return {{-1,-1},{-1,-1}};
    }
    sort(all(novi));
    for(int i=0;i<novi.size()/2;i++)
        printf("%i %i\n",novi[2*i].s,novi[2*i+1].s);
    return {{x.front().f.f,novi.back().f.f},{novi.back().f.s,novi.back().s}};
}
int main()
{
    int n;
    scanf("%i",&n);
	vector<pair<pair<int,int>,pair<int,int> > > p(n),novi,tr;
	for(int i=0;i<n;i++)
        scanf("%i %i %i",&p[i].f.f,&p[i].f.s,&p[i].s.f),p[i].s.s=i+1;
    sort(all(p));
    p.pb({{INT_MIN,-1},{-1,-1}});
    for(int i=0;i<n;i++)
    {
        tr.pb(p[i]);
        if(p[i].f.f!=p[i+1].f.f)
        {
            if(tr.size()%2)
                novi.pb(solve2d(tr));
            else
                solve2d(tr);
            tr.clear();
        }
    }
    sort(all(novi));
    for(int i=0;i<novi.size()/2;i++)
        printf("%i %i\n",novi[2*i].s.s,novi[2*i+1].s.s);
    return 0;
}