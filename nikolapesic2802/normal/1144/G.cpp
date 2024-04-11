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
const int N=50001,oo=INT_MAX;
int n,m,p;
vector<vector<int> > graf(N);
vector<int> pairU(N),pairV(N),dist(N);
bool bfs()
{
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(pairU[i]==0)
            dist[i]=0,q.push(i);
        else
            dist[i]=oo;
    dist[0]=oo;
    while(q.size())
    {
        int u=q.front();
        q.pop();
        if(dist[u]<dist[0])
            for(auto p:graf[u])
                if(dist[pairV[p]]==oo)
                    dist[pairV[p]]=dist[u]+1,q.push(pairV[p]);
    }
    return dist[0]!=oo;
}
bool dfs(int u)
{
    if(u==0)
        return true;
    for(auto p:graf[u])
        if(dist[pairV[p]]==dist[u]+1)
            if(dfs(pairV[p]))
            {
                pairV[p]=u;
                pairU[u]=p;
                return true;
            }
    return false;
}
int hopcroftKarp()
{
    int res=0;
    while(bfs())
        for(int i=1;i<=n;i++)
            if(pairU[i]==0&&dfs(i))
                res++;
    return res;
}
int main()
{
    int n;
    scanf("%i",&n);
    vector<int> seq(n+1);
    for(int i=0;i<n;i++)
        scanf("%i",&seq[i]);
    vector<int> sol(n);
    vector<int> inc,dec;
    inc.pb(-1);
    dec.pb(2e5+1);
    for(int i=0;i<n;i++)
    {
        if(seq[i]>inc.back())
        {
            if(seq[i]<dec.back())
            {
                if(seq[i+1]>seq[i])
                    inc.pb(seq[i]);
                else
                    dec.pb(seq[i]),sol[i]++;
            }
            else
                inc.pb(seq[i]);
        }
        else
        {
            if(seq[i]<dec.back())
                dec.pb(seq[i]),sol[i]++;
            else
            {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
        printf("%i ",sol[i]);
    return 0;
	scanf("%i %i %i",&n,&m,&p);
	for(int i=0;i<p;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        graf[a].pb(b);
    }
    printf("%i\n",hopcroftKarp());
    return 0;
}