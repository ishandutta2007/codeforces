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
int dp[N][2]; ///ways za n 0-ne mora da bude obojem, 1-mora
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
vector<vector<int> > graf(N);
int calc(int tr,int jeste,int par)
{
    if(graf[tr].size()==1)
        return 1;
    if(dp[tr][jeste]!=-1)
        return dp[tr][jeste];
    vector<int> nacini(3);
    nacini[0]=1;
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        vector<int> novi(3);
        int a=calc(p,0,tr);
        for(int i=0;i<3;i++)
            novi[i]=mul(nacini[i],a);
        int b=calc(p,1,tr);
        novi[1]=add(novi[1],mul(nacini[0],b));
        novi[2]=add(novi[2],mul(nacini[1],b));
        novi[2]=add(novi[2],mul(nacini[2],b));
        nacini=novi;
    }
    //printf("%i %i %i\n",nacini[0],nacini[1],nacini[2]);
    if(jeste==0)
    {
        dp[tr][jeste]=add(nacini[0],nacini[2]);
        return dp[tr][jeste];
    }
    else
    {
        dp[tr][jeste]=add(nacini[1],nacini[2]);
        return dp[tr][jeste];
    }
}
int main()
{
    memset(dp,-1,sizeof(dp));
	int n;
	scanf("%i",&n);
	for(int i=1;i<n;i++)
    {
        int a;
        scanf("%i",&a);
        a--;
        graf[a].pb(i);
        graf[i].pb(a);
    }
    graf[0].pb(0);
    printf("%i\n",calc(0,0,0));
    return 0;
}