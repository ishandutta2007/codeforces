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
vector<pair<int,int> > edges;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	deque<int> chain;
	int n,a;
	scanf("%i",&n);
	vector<pair<int,int> > d;
	for(int i=0;i<n;i++)
        scanf("%i",&a),d.pb({a,i+1});
    sort(d.rbegin(),d.rend());
    queue<int> unfilled;
    chain.pb(d[0].s*2);
    for(int i=0;i<d[0].f-1;i++)
        chain.pb(INT_MAX),unfilled.push(chain.size()-1);
    chain.pb(d[0].s*2-1);
    for(int i=1;i<n;i++)
    {
        if(unfilled.empty())
        {
            if(d[i].f==1)
            {
                edges.pb({chain[0],d[i].s*2});
                edges.pb({d[i].s*2,d[i].s*2-1});
                continue;
            }
            edges.pb({chain[0],d[i].s*2});
            edges.pb({chain[d[i].f-2],d[i].s*2-1});
            continue;
        }
        int tr=unfilled.front();
        unfilled.pop();
        chain[tr]=d[i].s*2;
        int nxt=tr+d[i].f-1;
        if(nxt==chain.size()-1)
        {
            chain.pb(d[i].s*2-1);
            continue;
        }
        edges.pb({-nxt,d[i].s*2-1});
    }
    for(auto &p:edges)
        if(p.f<0)
            p.f=chain[-p.f];
    for(int i=0;i<chain.size()-1;i++)
        edges.pb({chain[i],chain[i+1]});
    for(auto p:edges)
        printf("%i %i\n",p.f,p.s);
    return 0;
}