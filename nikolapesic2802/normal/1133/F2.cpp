#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
    
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
    
using namespace std;
using namespace __gnu_pbds;
    
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>; ///find_by_order(),order_of_key()
template<class T1, class T2> ostream& operator<<(ostream& os, const pair<T1,T2>& a) { os << '{' << a.f << ", " << a.s << '}'; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<T>& a){os << '{';for(int i=0;i<sz(a);i++){if(i>0&&i<sz(a))os << ", ";os << a[i];}os<<'}';return os;}
template<class T> ostream& operator<<(ostream& os, const set<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T> ostream& operator<<(ostream& os, const multiset<T>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const map<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<class T1,class T2> ostream& operator<<(ostream& os, const gp_hash_table<T1,T2>& a) {os << '{';int i=0;for(auto p:a){if(i>0&&i<sz(a))os << ", ";os << p;i++;}os << '}';return os;}
template<int D, typename T> struct Vec : public vector<Vec<D - 1, T>> {static_assert(D >= 1, "Vector dimension must be greater than zero!");template<typename... Args>
Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}};template<typename T> struct Vec<1, T> : public vector<T> {
Vec(int n = 0, const T& val = T()) : vector<T>(n, val) {}};
//istream& operator>>(istream& is,__int128& a){string s;is>>s;a=0;for(auto p:s)a=a*10+p-'0';return is;}
//ostream& operator<<(ostream& os,__int128 a){bool neg=false;if(a<0)neg=true,a*=-1;ll high=(a/(__int128)1e18);ll low=(a-(__int128)1e18*high);string res;if(neg)res+='-';if(high>0){res+=to_string(high);string temp=to_string(low);res+=string(18-temp.size(),'0');res+=temp;}else res+=to_string(low);os<<res;return os;}

vector<int> ne[500050];
vector<pair<int,int>> res;
int par[500050];
int visited[500050];

int find(int x)
{
    //cout << "uso u find za " << x << endl;
    return x == par[x] ? x : par[x] = find(par[x]);
}

void merge(int a, int b)
{
    par[find(b)] = find(a);
}

void dfs(int pa, int x)
{
    for(int a : ne[x])
    {
        if(a != pa && !visited[a])
        {
            res.pb(make_pair(a, x));
            visited[a] = 1;
            dfs(x, a);
        }
    }
}

int main()
{
    //a
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m, D;
    cin >> n >> m >> D;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        ne[u].pb(v);
        ne[v].pb(u);
    }    
    for(int i = 1; i <= n; i++)
        par[i] = i;
    for(int i = 2; i <= n; i++)
    {
        for(int x : ne[i])
        {
            if(x != 1)
            {
                merge(min(i, x), max(i, x));
            }
        }
    }  

    int komp = 0;
    vector<int> naso(n+500);
    for(int i = 1; i <= n; i++)
        naso[i] = 0;

    for(int i = 2; i <= n; i++)
    {
        if(naso[find(i)] == 0)
            {
                naso[find(i)] = 1;
                komp++;
            }
    }
		
    if(komp > D || ne[1].size() < D)
    {
        cout << "NO";
        return 0;
    }

    int vis[n+500];
    int edge[n+500];
    
    visited[1] = 1;
    for(int i = 1; i <= n; i++)
        edge[i] = 0;

    for(int i = 1; i <= n; i++)
        vis[i] = 0;
    
    for(int x : ne[1])
    {
        if(vis[find(x)] == 0)
        {
            res.pb(make_pair(1,x));
            vis[find(x)]=1;
            edge[x] = 1;
            visited[x] = 1;
        }
    }

        int br = 0;
        for(int x : ne[1])
        {
            if(br == D - komp)
                break;
            if(edge[x] == 0)
            {
                res.pb(make_pair(1, x));
                visited[x] = 1;
                br++;
            }
        }
    for(int i=0;i<res.size();i++)
    	dfs(1,res[i].second);
    cout << "YES" << endl;
    for(auto r : res)
        cout << r.first << " " << r.second << endl;

    return 0;
}