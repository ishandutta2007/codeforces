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

int n,k,a,b;
const int N=2e5+5;
vector<vector<int> > graf(N);
vector<int> d(N),dd(N);
void init(int tr,int par)
{
    d[tr]=1;
    for(auto p:graf[tr])
        if(p!=par)
            init(p,tr),d[tr]=max(d[tr],d[p]+1);
}
void check(int tr,int par,int dd1)
{
    dd[tr]=dd1;
    vector<int> de={dd1,0,0};
    for(auto p:graf[tr])
        if(p!=par)
            de.pb(d[p]);
    sort(de.rbegin(),de.rend());
    if(de[0]+de[1]>=k-1&&de[0]+de[2]>=k-1&&de[2]+de[1]>=k-1&&de[2]>0&&k>2)
        exit(printf("No\n")*0);
    for(auto p:graf[tr])
        if(p!=par){
            if(de[0]==d[p])
                check(p,tr,de[1]+1);
            else
                check(p,tr,de[0]+1);
        }
}
vector<int> color(N),value(N);
void doit(int tr,int par,int dir,int last)
{
    last=last+dir;
    if(last>k)
        last-=k;
    if(last<1)
        last+=k;
    color[tr]=last;
    vector<pair<int,int> > de;
    for(auto p:graf[tr])
        if(p!=par)
            de.pb({d[p],p});
    sort(de.rbegin(),de.rend());
    if(de.empty())
        return;
    if(de[0].f<=dd[tr])
    {
        for(auto p:graf[tr])
            if(p!=par)
                doit(p,tr,dir,last);
    }
    else
        for(auto p:graf[tr])
            if(p!=par)
            {
                if(p==de[0].s)
                    doit(p,tr,dir,last);
                else
                    doit(p,tr,dir*-1,last);
            }
}
int main()
{
	scanf("%i %i",&n,&k);
	for(int i=1;i<n;i++)
        scanf("%i %i",&a,&b),a--,b--,graf[a].pb(b),graf[b].pb(a);
    init(0,0);
    check(0,0,0);
    printf("Yes\n");
    doit(0,0,1,0);
    for(int i=0;i<n;i++)
        printf("%i ",color[i]);
    return 0;
}