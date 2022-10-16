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
int cnt=0;
vector<set<ll,greater<ll> > > extra(N);
vector<vector<int> > graf(N);
vector<int> done(N),num(N);
vector<ll> w(N);
int main()
{
    ll sol=0;
	int n,m,a,b;
	scanf("%i %i",&n,&m);
	for(int i=1;i<=n;i++)
        scanf("%lld",&w[i]),sol+=w[i];
    for(int i=0;i<m;i++)
        scanf("%i %i",&a,&b),graf[a].pb(b),graf[b].pb(a),num[a]++,num[b]++;
    int s;
    scanf("%i",&s);
    queue<int> q;
    for(int i=0;i<=n;i++)
        if(graf[i].size()==1)
            q.push(i);
    while(q.size())
    {
        int tr=q.front();
        q.pop();
        if(tr==s)
            continue;
        sol-=w[tr];
        done[tr]=1;
        ll bonus=0;
        if(extra[tr].size())
            bonus=*extra[tr].begin();
        extra[tr].clear();
        for(auto p:graf[tr])
        {
            if(done[p])
                continue;
            num[p]--;
            if(num[p]==1)
                q.push(p);
            extra[p].insert(w[tr]+bonus);
        }
    }
    for(int i=0;i<=n;i++)
        for(auto p:extra[i])
            extra[N-1].insert(p);
    if(extra[N-1].size())
        sol+=*extra[N-1].begin();
    printf("%lld\n",sol);
    return 0;
}