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

const int N=2e5;
const int D=400;
const int M=1e6+1;
vector<int> a(N);
vector<int> occ(M);
ll mo=0;
int l=0,r=-1;
struct query{int l,r,i;};
vector<query> q;
void adjust(int nl,int nr)
{
    while(l>nl)
    {
        l--;
        mo-=(ll)occ[a[l]]*occ[a[l]]*a[l];
        occ[a[l]]++;
        mo+=(ll)occ[a[l]]*occ[a[l]]*a[l];
    }
    while(r<nr)
    {
        r++;
        mo-=(ll)occ[a[r]]*occ[a[r]]*a[r];
        occ[a[r]]++;
        mo+=(ll)occ[a[r]]*occ[a[r]]*a[r];
    }
    while(l<nl)
    {
        mo-=(ll)occ[a[l]]*occ[a[l]]*a[l];
        occ[a[l]]--;
        mo+=(ll)occ[a[l]]*occ[a[l]]*a[l];
        l++;
    }
    while(r>nr)
    {
        mo-=(ll)occ[a[r]]*occ[a[r]]*a[r];
        occ[a[r]]--;
        mo+=(ll)occ[a[r]]*occ[a[r]]*a[r];
        r--;
    }
}
bool cmp(query a,query b)
{
    a.l/=D;
    b.l/=D;
    if(a.l!=b.l)
        return a.l<b.l;
    if(a.l%2)
        return a.r<b.r;
    return a.r>b.r;
}
int main()
{
    int n,qu;
    scanf("%i %i",&n,&qu);
    for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    for(int i=0;i<qu;i++)
    {
        int x,y;
        scanf("%i %i",&x,&y);
        x--;y--;
        q.pb({x,y,i});
    }
    vector<ll> ans(qu);
    sort(all(q),cmp);
    for(auto p:q)
    {
        adjust(p.l,p.r);
        ans[p.i]=mo;
    }
    for(int i=0;i<qu;i++)
        printf("%lld\n",ans[i]);
    return 0;
}