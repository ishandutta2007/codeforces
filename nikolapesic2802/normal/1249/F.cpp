#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
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

const int N=201;
vector<vector<int> > graf(N);
int dp[N][N],val[N],n,k,a,b;
int calc(int tr,int par,int t)
{
    if(dp[tr][t]!=-1)
        return dp[tr][t];
    vector<int> vals(k+1);
    for(auto p:graf[tr])
        if(p!=par)
            for(int i=0;i<=k;i++)
                vals[i]+=calc(p,tr,i);
    dp[tr][t]=0;
    if(!t)
        dp[tr][t]=vals[k]+val[tr];
    for(auto p:graf[tr])
        if(p!=par)
        {
            for(int i=max(0,t-1);i<=max(t-1,(k-1)/2);i++)
            {
                int ostali=max(k-i-1,t-1);
                dp[tr][t]=max(dp[tr][t],vals[ostali]-calc(p,tr,ostali)+calc(p,tr,i));
            }
        }
    return dp[tr][t];
}
int main()
{
    //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	memset(dp,-1,sizeof(dp));
    cin >> n >> k;
    for(int i=1;i<=n;i++)
        cin >> val[i];
    for(int i=1;i<n;i++)
        cin >> a >> b,graf[a].pb(b),graf[b].pb(a);
    printf("%i\n",calc(1,1,0));
    return 0;
}