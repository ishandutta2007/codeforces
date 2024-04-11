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

ll dist(pair<int,int> a,pair<int,int> b){
    return (ll)(a.f-b.f)*(a.f-b.f)+(ll)(a.s-b.s)*(a.s-b.s);
}
pair<ll,vector<pair<int,int> > > calc(vector<pair<int,int> > &p){
    if(p.size()==2){
        if(p[0].s>p[1].s)
            swap(p[0],p[1]);
        return {dist(p[0],p[1]),p};
    }
    if(p.size()==1)
        return {LLONG_MAX,p};
    int m=p.size()/2,x=p[m].f;
    vector<pair<int,int> > l,r,sol;
    for(int i=0;i<p.size();i++)
        if(i<m)
            l.pb(p[i]);
        else
            r.pb(p[i]);
    auto aa=calc(l),bb=calc(r);
    l=aa.s;
    r=bb.s;
    ll d=min(aa.f,bb.f);
    l.pb({INT_MAX,INT_MAX});
    r.pb({INT_MAX,INT_MAX});
    int i=0,j=0;
    while(i<l.size()-1||j<r.size()-1)
        if(l[i].s<r[j].s)
            sol.pb(l[i]),i++;
        else
            sol.pb(r[j]),j++;
    vector<pair<int,int> > points;
    for(auto p:sol)
        if((ll)(p.f-x)*(p.f-x)<d)
            points.pb(p);
    for(int i=0;i<points.size();i++)
        for(int j=i-1;j>=0&&(ll)(points[j].s-points[i].s)*(points[j].s-points[i].s)<d;j--)
            d=min(d,dist(points[i],points[j]));
    return {d,sol};
}
int main()
{
    vector<pair<int,int> > p;
    int n,tr=0,a;
    scanf("%i",&n);
    for(int i=0;i<n;i++)
        scanf("%i",&a),tr+=a,p.pb({i,tr});
    sort(all(p));
    printf("%lld\n",calc(p).f);
}