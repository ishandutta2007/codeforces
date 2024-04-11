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

const int N=15005,M=2*N;
vector<vector<int> > graf(N);
vector<int> inCycle(N),siz(N),dep(N),indeks(N),cycle,visited(N);
vector<ll> pref,pref2,dpp;
int koji,parr;
int trazi;
ll dp2[2][M],sum;
int findCyc(int tr,int par)
{
    visited[tr]=1;
    for(auto p:graf[tr])
    {
        if(p==par)
            continue;
        if(visited[p]==0)
            if(int d=findCyc(p,tr))
            {
                if(d==1)
                    inCycle[tr]=1;
                if(trazi==tr)
                    d=2;
                return d;
            }
        if(visited[p]==1)
        {
            trazi=p;
            inCycle[tr]=1;
            return 1;
        }
    }
    visited[tr]=2;
    return 0;
}
void dfs(int tr,int par)
{
    siz[tr]=1;
    for(auto p:graf[tr])
        if(p!=par&&!inCycle[p])
            dfs(p,tr),siz[tr]+=siz[p];
    sum+=siz[tr];
}
void dfs2(int tr,int par)
{
    siz[tr]=1;
    if(inCycle[tr])
    {
        koji=tr;
        parr=par;
        sum+=siz[tr];
        return;
    }
    for(auto p:graf[tr])
        if(p!=par)
            dep[p]=dep[tr]+1,dfs2(p,tr),siz[tr]+=siz[p];
    sum+=siz[tr];
}
vector<ll> dpsol(M);
int main()
{
    //freopen("in.txt","r",stdin);
	int n,a,b;
	scanf("%i",&n);
	for(int i=0;i<n;i++)
        scanf("%i %i",&a,&b),graf[a].pb(b),graf[b].pb(a);
    findCyc(0,0);
    for(int i=0;i<n;i++)
        if(inCycle[i]==1)
            cycle.pb(i);
    for(auto p:cycle)
    {
        sum=0;
        dfs(p,p);
        dpp.pb(siz[p]);
        pref.pb(siz[p]);
        pref2.pb(sum-siz[p]);
    }
    for(int i=0;i<(int)cycle.size();i++)
        dpp.pb(dpp[i]),pref.pb(pref[i]),pref2.pb(pref2[i]),indeks[cycle[i]]=i;
    int m=dpp.size();
    for(int i=1;i<m;i++)
        pref[i]+=pref[i-1],pref2[i]+=pref2[i-1];
    for(int i=0;i<2;i++)
        for(int j=0;j<M;j++)
            dp2[i][j]=LLONG_MAX/2;
    for(int i=m-1;i>=0;i--)
        for(int j=i;j<m;j++)
        {
            if(i==j)
            {
                dp2[i&1][j]=dpp[i];
                continue;
            }
            if(dp2[(i+1)&1][j]>=dp2[i&1][j-1])
                dp2[i&1][j]=dp2[(i+1)&1][j];
            else
                dp2[i&1][j]=dp2[i&1][j-1];
            dp2[i&1][j]+=pref[j];
            if(i)
                dp2[i&1][j]-=pref[i-1];
            if(j==i+m/2-2)
                dpsol[i]=dp2[i&1][j];
        }
    int i=cycle[0];
    sum=0;
    dep[i]=1;
    dfs2(i,i);
    ll sol=sum;
    int ind=indeks[i];
    sol+=n-1;
    sol+=dpsol[ind+1];
    sol+=pref2[ind+m/2-1];
    if(ind)
        sol-=pref2[ind-1];
    ll total=sol;
    for(i=0;i<n;i++){
        if(graf[i].size()==1)
        {
            sum=0;
            dep[i]=1;
            dfs2(i,i);
            sol=sum;
            int ind=indeks[koji],ostali=n-siz[i];
            sol+=(ll)ostali*dep[koji];
            sol+=dpsol[ind+1];
            sol+=pref2[ind+m/2-1];
            if(ind)
                sol-=pref2[ind-1];
            if(sol<=total)
                continue;
            sum=0;
            dfs(parr,parr);
            sol-=sum;
            total=max(total,sol);
        }
    }
    printf("%lld\n",total);
    return 0;
}