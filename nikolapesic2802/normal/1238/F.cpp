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

const int N=3e5+5;
vector<vector<int> > graf(N);
int dp[N][2];
int calc(int tr,int par,int s)
{
    if(dp[tr][s]!=-1)
        return dp[tr][s];
    dp[tr][s]=0;
    if(s==0)
    {
        vector<int> d(2,1);
        for(auto p:graf[tr])
            if(p!=par)
                d.pb(calc(p,tr,1));
        for(auto p:graf[tr])
            if(p!=par)
                dp[tr][s]=max(dp[tr][s],calc(p,tr,0));
        sort(d.rbegin(),d.rend());
        dp[tr][s]=max(dp[tr][s],(int)graf[tr].size()-1+d[0]+d[1]);
        return dp[tr][s];
    }
    int mx=1;
    for(auto p:graf[tr])
        if(p!=par)
            mx=max(mx,calc(p,tr,1));
    dp[tr][s]=max(dp[tr][s],(int)graf[tr].size()-1+mx);
    return dp[tr][s];
}
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int q;
	scanf("%i",&q);
	while(q--)
    {
        int n,a,b;
        scanf("%i",&n);
        for(int i=0;i<n;i++)
            graf[i].clear(),dp[i][0]=dp[i][1]=-1;
        for(int i=1;i<n;i++)
            scanf("%i %i",&a,&b),a--,b--,graf[a].pb(b),graf[b].pb(a);
        printf("%i\n",calc(0,0,0));
    }
    return 0;
}