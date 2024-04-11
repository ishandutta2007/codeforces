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

const int mod=1e9+7;
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int mul(int a,int b)
{
    return (ll)a*b%mod;
}
int powmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
struct node{
    vector<int> nxt,dp,pref,suf;
    //vector<vector<int> > dp,sum;
    void construct(int tr)
    {
        pref=suf=dp;
        for(int i=1,n=dp.size();i<n;i++)
            pref[i]=mul(pref[i-1],pref[i]);
        for(int n=dp.size(),i=n-2;i>=0;i--)
            suf[i]=mul(suf[i+1],suf[i]);
    }
    int getWithout(int i)
    {
        int sol=1;
        if(i)
            sol=mul(sol,pref[i-1]);
        if(i!=(int)pref.size()-1)
            sol=mul(sol,suf[i+1]);
        return sol;
    }
    int getSol()
    {
        return pref[pref.size()-1];
    }
};
const int N=2e5+5;
vector<node> graf(N);
int init(int tr,int par)
{
    int dp=1;
    for(int i=0;i<(int)graf[tr].nxt.size();i++)
    {
        int p=graf[tr].nxt[i];
        if(p==par)
            continue;
        int d=init(p,tr);
        graf[tr].dp[i]=add(d,1);
        dp=mul(dp,graf[tr].dp[i]);
    }
    return dp;
}
vector<int> sol(N);
void solve(int tr,int par)
{
    graf[tr].construct(tr);
    sol[tr]=graf[tr].getSol();
    for(int i=0;i<(int)graf[tr].nxt.size();i++)
    {
        int p=graf[tr].nxt[i];
        if(p==par)
            continue;
        int cnt=0;
        for(auto &d:graf[p].dp)
            if(d==-1)
                d=add(graf[tr].getWithout(i),1),cnt++;
        assert(cnt==1);
        solve(p,tr);
    }
}
int main()
{
	int n;
	scanf("%i",&n);
	for(int i=1;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        a--;
        //printf("%i %i\n",i,a);
        graf[i].nxt.pb(a);
        graf[a].nxt.pb(i);
        graf[i].dp.pb(-1);
        graf[a].dp.pb(-1);
    }
    init(0,-1);
    solve(0,-1);
    for(int i=0;i<n;i++)
        printf("%i ",sol[i]);
    return 0;
}