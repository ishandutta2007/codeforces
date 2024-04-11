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
const int N=3605,mod=998244353;
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
int pwrmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
vector<int> fact,ifact(N);
int dpH[N][N],dpW[N][N];
bool takenH[N],takenW[N];
int h,w,n;
int calcH(int x,int koliko)
{
    if(x>=h-1)
        return koliko==0;
    if(dpH[x][koliko]!=-1)
        return dpH[x][koliko];
    dpH[x][koliko]=calcH(x+1,koliko);
    if(koliko&&!takenH[x]&&!takenH[x+1])
        dpH[x][koliko]=add(dpH[x][koliko],calcH(x+2,koliko-1));
    return dpH[x][koliko];
}
int calcW(int x,int koliko)
{
    if(x>=w-1)
        return koliko==0;
    if(dpW[x][koliko]!=-1)
        return dpW[x][koliko];
    dpW[x][koliko]=calcW(x+1,koliko);
    if(koliko&&!takenW[x]&&!takenW[x+1])
        dpW[x][koliko]=add(dpW[x][koliko],calcW(x+2,koliko-1));
    return dpW[x][koliko];
}

int nCk(int n,int k)
{
    if(n<k)
        return 0;
    return mul(mul(fact[n],ifact[k]),ifact[n-k]);
}
int main()
{
    fact.pb(1);
    for(int i=1;i<N;i++)
        fact.pb(mul(fact.back(),i));
    ifact[N-1]=pwrmod(fact[N-1],mod-2);
    for(int i=N-2;i>=0;i--)
        ifact[i]=mul(ifact[i+1],(i+1));
	for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            dpH[i][j]=dpW[i][j]=-1;
	scanf("%i %i %i",&h,&w,&n);
	for(int i=0;i<2*n;i++)
    {
        int x,y;
        scanf("%i %i",&x,&y);
        x--;y--;
        takenH[x]=1;
        takenW[y]=1;
    }
    int mx=max(h,w),cntH=0,cntW=0;
    for(int i=0;i<h;i++)
        if(!takenH[i])
            cntH++;
    for(int i=0;i<w;i++)
        if(!takenW[i])
            cntW++;
    int sol=0;
    for(int i=0;i<=mx;i++)
        for(int j=0;j<=mx;j++)
        {
            int hh=mul(calcH(0,j),fact[j]);
            int ostalo=cntH-2*j;
            hh=mul(hh,nCk(ostalo,i));
            int ww=mul(calcW(0,i),fact[i]);
            int ow=cntW-2*i;
            ww=mul(ww,nCk(ow,j));
            hh=mul(hh,ww);
            sol=add(sol,hh);
        }
    printf("%i\n",sol);
    return 0;
}