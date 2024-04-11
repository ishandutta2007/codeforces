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

const int N=2e3+5;
vector<vector<pair<int,int> > > skip1(N),skip2(N);
vector<int> mn(N),mx(N),par(N),degree(N),siz(N);
int t;
int main()
{
    int n,a,y;
    scanf("%i",&n);
    fill(all(mn),INT_MAX);
    fill(all(mx),0);
    fill(all(siz),1);
    fill(all(degree),0);
    scanf("%i",&a);
    for(int i=1;i<a;i++)
        scanf("%i",&par[i]),par[i]--,degree[i]++,degree[par[i]]++;
    degree[0]++;
    siz[0]--;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&y);
        y--;
        mn[y]=mx[y]=i;
        queue<int> q;
        q.push(y);
        while(q.size())
        {
            int tr=q.front();
            skip1[mn[tr]].pb({mx[tr]+1,siz[tr]});
            q.pop();
            degree[par[tr]]--;
            mn[par[tr]]=min(mn[par[tr]],mn[tr]);
            mx[par[tr]]=max(mx[par[tr]],mx[tr]);
            siz[par[tr]]+=siz[tr];
            if(degree[par[tr]]==1)
                q.push(par[tr]);
        }
    }
    fill(all(mn),INT_MAX);
    fill(all(mx),0);
    fill(all(siz),1);
    fill(all(degree),0);
    scanf("%i",&a);
    for(int i=1;i<a;i++)
        scanf("%i",&par[i]),par[i]--,degree[i]++,degree[par[i]]++;
    degree[0]++;
    siz[0]--;
    for(int i=0;i<n;i++)
    {
        scanf("%i",&y);
        y--;
        mn[y]=mx[y]=i;
        queue<int> q;
        q.push(y);
        while(q.size())
        {
            int tr=q.front();
            skip2[mn[tr]].pb({mx[tr]+1,siz[tr]});
            q.pop();
            degree[par[tr]]--;
            mn[par[tr]]=min(mn[par[tr]],mn[tr]);
            mx[par[tr]]=max(mx[par[tr]],mx[tr]);
            siz[par[tr]]+=siz[tr];
            if(degree[par[tr]]==1)
                q.push(par[tr]);
        }
    }
    vector<int> dp(n+1);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        dp[i]=dp[i+1];
        for(auto p:skip1[i])
            dp[i]=max(dp[i],p.s+dp[p.f]);
        for(auto p:skip2[i])
            dp[i]=max(dp[i],p.s+dp[p.f]);
    }
    printf("%i\n",dp[0]);
    return 0;
}