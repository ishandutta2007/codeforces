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
vector<int> fact;
const int mod=998244353;
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
    vector<int> nxt;
    vector<int> sol;
    vector<int> sum;
    void construct()
    {
        sum.resize(nxt.size());
        sum[0]=sol[0];
        for(int i=1;i<(int)nxt.size();i++)
            sum[i]=mul(sum[i-1],sol[i]);
    }
    int getBez(int i)
    {
        int sol=1;
        if(i)
            sol=mul(sol,sum[i-1]);
        sol=mul(sol,sum[nxt.size()-1]);
        sol=mul(sol,powmod(sum[i],mod-2));
        sol=mul(sol,fact[nxt.size()]);
        return sol;
    }
    int getSol()
    {
        return mul(sum[nxt.size()-1],fact[nxt.size()]);
    }
};
vector<node> graf(N);
int init(int tr,int par)
{
    int trsol=1;
    int cnt=1;
    for(int i=0;i<(int)graf[tr].nxt.size();i++)
    {
        int p=graf[tr].nxt[i];
        if(p==par)
            continue;
        graf[tr].sol[i]=init(p,tr);
        trsol=mul(trsol,graf[tr].sol[i]);
        cnt++;
    }
    trsol=mul(trsol,fact[cnt]);
    return trsol;
}
int sol=0;
void solve(int tr,int par)
{
    graf[tr].construct();
    sol=add(sol,graf[tr].getSol());
    for(int i=0;i<(int)graf[tr].nxt.size();i++)
    {
        int p=graf[tr].nxt[i];
        if(p==par)
            continue;
        int sol=graf[tr].getBez(i);
        for(auto &d:graf[p].sol)
            if(d==-1)
                d=sol;
        solve(p,tr);
    }
}
int main()
{
    fact.pb(1);
    for(int i=1;i<N;i++)
        fact.pb(mul(fact.back(),i));
	int n;
	scanf("%i",&n);
	for(int i=1;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        a--;b--;
        graf[a].nxt.pb(b);
        graf[b].nxt.pb(a);
        graf[a].sol.pb(-1);
        graf[b].sol.pb(-1);
    }
    init(0,-1);
    solve(0,-1);
    printf("%i\n",sol);
    return 0;
}