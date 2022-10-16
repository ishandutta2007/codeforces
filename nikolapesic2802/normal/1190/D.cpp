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
vector<int> sum(4*N);
void sett(int pos,int l=0,int r=N-1,int i=1)
{
    if(l>pos||r<pos)
        return;
    if(l==r)
    {
        sum[i]=1;
        return;
    }
    int m=(l+r)>>1;
    sett(pos,l,m,2*i);
    sett(pos,m+1,r,2*i+1);
    sum[i]=sum[2*i]+sum[2*i+1];
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
	int n,m;
	scanf("%i",&n);
	vector<pair<int,int> > points(n+1,{-1,-1});
	vector<int> xx;
	for(int i=0;i<n;i++)
        scanf("%i %i",&points[i].s,&points[i].f),xx.pb(points[i].s);
    sort(all(xx));
    xx.erase(unique(all(xx)),xx.end());
    gp_hash_table<int,int> mapa;
    for(int i=0;i<xx.size();i++)
        mapa[xx[i]]=i;
    for(auto &p:points)
        p.s=mapa[p.s];
    sort(points.rbegin(),points.rend());
    ll sol=0;
    set<int> tr;
    vector<int> x(1,points[0].s);
    for(int i=1;i<=n;i++)
    {
        if(points[i].f==points[i-1].f)
        {
            x.pb(points[i].s);
            continue;
        }
        reverse(all(x));
        sol-=(ll)get(0,x.front()-1)*(get(0,x.front()-1)+1)/2;
        for(int i=1;i<x.size();i++)
            sol-=(ll)get(x[i-1]+1,x[i]-1)*(get(x[i-1]+1,x[i]-1)+1)/2;
        sol-=(ll)get(x.back()+1,N)*(get(x.back()+1,N)+1)/2;
        for(auto p:x)
            tr.insert(p),sett(p);
        sol+=(ll)tr.size()*(tr.size()+1)/2;
        x.clear();
        x.pb(points[i].s);
    }
    printf("%lld\n",sol);
    return 0;
}