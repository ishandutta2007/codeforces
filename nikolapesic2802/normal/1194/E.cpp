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

const int N=10001,M=5e3+1;
vector<int> sum(4*N);
void post(int pos,int x,int l=0,int r=N-1,int i=1)
{
    if(x)
        sum[i]++;
    else
        sum[i]--;
    if(l==r)
        return;
    int m=(l+r)>>1;
    if(pos<=m)
        post(pos,x,l,m,2*i);
    else
        post(pos,x,m+1,r,2*i+1);
}
int get(int qs,int qe,int l=0,int r=N-1,int i=1)
{
    if(qs>r||qe<l)
        return 0;
    if(qs<=l&&qe>=r)
        return sum[i];
    int m=(l+r)>>1;
    return get(qs,qe,l,m,2*i)+get(qs,qe,m+1,r,2*i+1);
}
int main()
{
	int n;
	scanf("%i",&n);
	vector<pair<pair<int,int>,int> > ver;
	vector<pair<int,pair<int,int> > > hor;
	vector<int> x,y;
	for(int i=0;i<n;i++)
    {
        int x1,y1,x2,y2;
        scanf("%i %i %i %i",&x1,&y1,&x2,&y2);
        x.pb(x1);
        x.pb(x2);
        y.pb(y1);
        y.pb(y2);
        if(x1>x2)
            swap(x1,x2);
        if(y1>y2)
            swap(y1,y2);
        if(x1==x2)
        hor.pb({x1,{y1,y2}});
        else
        ver.pb({{x1,x2},y1});
    }
    sort(all(x));
    sort(all(y));
    x.erase(unique(all(x)),x.end());
    map<int,int> mapa;
    for(int i=0;i<(int)x.size();i++)
        mapa[x[i]]=i;
    y.erase(unique(all(y)),y.end());
    map<int,int> mapa2;
    for(int i=0;i<(int)y.size();i++)
        mapa2[y[i]]=i;
    for(auto &p:ver)
        p.f.f=mapa[p.f.f],p.f.s=mapa[p.f.s],p.s=mapa2[p.s];
    for(auto &p:hor)
        p.f=mapa[p.f],p.s.f=mapa2[p.s.f],p.s.s=mapa2[p.s.s];
    sort(all(hor));
    ll ans=0;
    int oo=INT_MAX;
    for(int i=0;i<(int)hor.size();i++)
    {
        vector<pair<int,pair<int,int> > > events;
        for(int j=i+1;j<(int)hor.size();j++)
            events.pb(hor[j]);
        for(auto p:ver)
        {
            if(p.s>=hor[i].s.f&&p.s<=hor[i].s.s&&p.f.f<=hor[i].f)
            {
                events.pb({p.f.s,{oo,p.s}});
                post(p.s,1);
            }
        }
        sort(all(events));
        for(auto p:events)
        {
            if(p.s.f==oo)
                post(p.s.s,0);
            else{
                ll br=get(p.s.f,p.s.s);
                ans+=(ll)br*(br-1)/2;
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}