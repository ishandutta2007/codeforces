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
const int N=1e5+5;
vector<int> color(N),done(N);
vector<vector<int> > graf(N);
int n;
int mod=1e9+7;
int add(int x,int y)
{
    x+=y;
    if(x>=mod)
        x-=mod;
    return x;
}
int mul(int x,int y)
{
    return (ll)x*y%mod;
}
int dp[N][2]; ///vertex,did we cut an edge on the path between this one and the first colored one above it
void Solve(int tr)
{
    done[tr]=1;
    if(color[tr]==1)
        dp[tr][1]=1;
    else
        dp[tr][0]=1;
    for(auto p:graf[tr])
    {
        if(done[p])
            continue;
        Solve(p);
        if(color[tr]==1)
            dp[tr][1]=mul(dp[tr][1],add(dp[p][0],dp[p][1]));
        else
        {
            dp[tr][1]=add(mul(dp[tr][1],add(dp[p][0],dp[p][1])),mul(dp[tr][0],dp[p][1]));
            dp[tr][0]=mul(dp[tr][0],add(dp[p][0],dp[p][1]));
        }
    }
}

int main()
{
	scanf("%i",&n);
    for(int i=1;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        graf[a].pb(i);
        graf[i].pb(a);
    }
	for(int i=0;i<n;i++)
        scanf("%i",&color[i]);
    /*vector<int> in(n);
    queue<int> del;
    for(int i=0;i<n;i++)
    {
        in[i]=graf[i].size();
        if(in[i]==1&&color[i]==0)
            del.push(i);
    }
    vector<int> inside(n,1);
    while(del.size())
    {
        int tr=del.front();
        done[tr]=1;
        inside[tr]=0;
        del.pop();
        for(auto p:graf[tr])
        {
            in[p]--;
            if(in[p]==1&&color[p]==0)
                del.push(p);
        }
    }
    int start=-1;
    for(int i=0;i<n;i++)
        if(!done[i])
            start=i;
    if(start==-1)
    {
        printf("0\n");
        return 0;
    }*/
    ///Solve
    Solve(0);
    printf("%i\n",dp[0][1]);
    return 0;
}