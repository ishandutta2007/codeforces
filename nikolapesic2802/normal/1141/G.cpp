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
vector<vector<int> > graf(N);
vector<int> degree(N);
int limit;
map<int,int> num[N];
vector<int> coloring;
int solve(int tr,int par,int color)
{
    int a=limit;
    if(a<degree[tr])
    {
        int c=0;
        for(auto p:graf[tr])
        {
            if(p==par)
                continue;
            coloring[num[tr][p]]=c;
            solve(p,tr,c);
        }
    }
    else
    {
        int c=0;
        for(auto p:graf[tr])
        {
            if(p==par)
                continue;
            if(c==color)
                c++;
            assert(c<limit);
            coloring[num[tr][p]]=c;
            solve(p,tr,c);
            c++;
        }
    }
}
int main()
{
	int n,k;
	scanf("%i %i",&n,&k);
	for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;
        b--;
        degree[a]++;
        degree[b]++;
        graf[a].pb(b);
        graf[b].pb(a);
        num[a][b]=i-1;
        num[b][a]=i-1;
    }
    vector<pair<int,int> > degrees;
    for(int i=0;i<n;i++)
        degrees.pb({degree[i],i});
    sort(all(degrees));
    reverse(all(degrees));
    limit=degrees[k].f;
    coloring.resize(n-1);
    solve(degrees[0].s,-1,-1);
    printf("%i\n",limit);
    for(auto p:coloring)
        printf("%i ",p+1);
    return 0;
}