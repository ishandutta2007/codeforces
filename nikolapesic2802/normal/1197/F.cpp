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
vector<vector<int> > operator*(vector<vector<int> > a,vector<vector<int> > b)
{
    vector<vector<int> > sol(a.size(),vector<int>(b[0].size()));
    for(int i=0;i<a.size();i++)
        for(int j=0;j<b[0].size();j++)
            for(int k=0;k<b.size();k++)
                sol[i][j]=add(sol[i][j],mul(a[i][k],b[k][j]));
    return sol;
}
const int L=64,N=1001;
vector<vector<int> > numbers;
map<vector<int>,int> mapa;
vector<vector<int> > base(L,vector<int>(L));
vector<vector<vector<int> > > colors(3,vector<vector<int> >(L,vector<int>(L)));
int moze[3][3];
vector<int> a(N);
int n;
vector<vector<pair<int,int> > > arr(N);
void build()
{
    for(int i=0;i<L;i++)
    {
        for(int j=0;j<3;j++)
        {
            vector<int> imam;
            for(int k=0;k<3;k++)
                if(moze[j][k])
                    imam.pb(numbers[i][2-k]);
            sort(imam.rbegin(),imam.rend());
            imam.erase(unique(all(imam)),imam.end());
            int mex=0;
            while(imam.size()&&imam.back()==mex)
                imam.pop_back(),mex++;
            vector<int> sol;
            for(int k=1;k<3;k++)
                sol.pb(numbers[i][k]);
            sol.pb(mex);
            colors[j][i][mapa[sol]]++;
            base[i][mapa[sol]]++;
        }

    }
}
vector<vector<int> > stepeni[31];
vector<vector<int> > powr(vector<vector<int> > a,int k)
{
    for(int p=0;k;k>>=1,p++)
        if(k&1)
            a=a*stepeni[p];
    return a;
}
int nacini[N][4];
int dp[N][4];
int calc(int tr,int x)
{
    if(tr==n)
        return x==0;
    if(dp[tr][x]!=-1)
        return dp[tr][x];
    dp[tr][x]=0;
    for(int i=0;i<4;i++)
        dp[tr][x]=add(dp[tr][x],mul(nacini[tr][i],calc(tr+1,x^i)));
    return dp[tr][x];
}
int main()
{
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
            for(int k=0;k<4;k++)
                numbers.pb({i,j,k}),mapa[numbers.back()]=mapa.size();
    scanf("%i",&n);
    for(int i=0;i<n;i++)
        scanf("%i",&a[i]);
    int m,x,y,z;
    scanf("%i",&m);
    for(int i=0;i<m;i++)
        scanf("%i %i %i",&x,&y,&z),arr[x-1].pb({y-1,z-1});
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            scanf("%i",&moze[i][j]);
    build();
    stepeni[0]=base;
    for(int j=1;j<31;j++)
        stepeni[j]=stepeni[j-1]*stepeni[j-1];
    for(int i=0;i<n;i++)
    {
        sort(all(arr[i]));
        vector<vector<int> > sol(1,vector<int>(L));
        sol[0][63]=1;
        int last=-1;
        for(auto p:arr[i])
            sol=powr(sol,p.f-last-1),sol=sol*colors[p.s],last=p.f;
        sol=powr(sol,a[i]-1-last);
        for(int j=0;j<64;j++)
            nacini[i][numbers[j].back()]=add(nacini[i][numbers[j].back()],sol[0][j]);
    }
    printf("%i\n",calc(0,0));
}