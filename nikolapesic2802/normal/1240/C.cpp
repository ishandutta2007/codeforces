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

const int N=5e5+5;
vector<vector<ll> > dp(N,vector<ll>(2));
vector<vector<pair<int,int> > > graf(N);
int k;
ll calc(int tr,int par,int uzeo)
{
    if(dp[tr][uzeo]!=-1)
        return dp[tr][uzeo];
    vector<ll> benefits;
    dp[tr][uzeo]=0;
    for(auto p:graf[tr])
        if(p.f!=par)
        {
            ll bez=calc(p.f,tr,0);
            ll sa=calc(p.f,tr,1)+p.s;
            dp[tr][uzeo]+=bez;
            benefits.pb(sa-bez);
        }
    sort(benefits.rbegin(),benefits.rend());
    int imam=k-uzeo;
    for(int i=0;i<min(k-uzeo,(int)benefits.size());i++)
        if(benefits[i]>0)
            dp[tr][uzeo]+=benefits[i];
        else
            break;
    return dp[tr][uzeo];
}
int main()
{
	int q;
	scanf("%i",&q);
	while(q--)
    {
        int n,u,v,w;
        scanf("%i %i",&n,&k);
        for(int i=0;i<n;i++)
            graf[i].clear(),dp[i][0]=dp[i][1]=-1;
        for(int i=1;i<n;i++)
            scanf("%i %i %i",&u,&v,&w),u--,v--,graf[u].pb({v,w}),graf[v].pb({u,w});
        printf("%lld\n",calc(0,0,0));
    }
    return 0;
}