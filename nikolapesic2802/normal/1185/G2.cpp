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
int n,T;
const int N=51;
vector<int> songs[3];
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
int dp[N][N][N*N][3];
int calc(int tr,int koliko,int t,int d)
{
    if(t<0)
        return 0;
    if(t==0||koliko==0)
    {
        if(t==0&&koliko==0)
            return dp[tr][koliko][t][d]=1;
        return dp[tr][koliko][t][d]=0;
    }
    if(tr>=(int)songs[d].size())
        return dp[tr][koliko][t][d]=0;
    if(dp[tr][koliko][t][d]!=-1)
        return dp[tr][koliko][t][d];
    dp[tr][koliko][t][d]=add(calc(tr+1,koliko,t,d),calc(tr+1,koliko-1,t-songs[d][tr],d));
    return dp[tr][koliko][t][d];
}
int powmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
        if(k&1)
            ans=mul(ans,x);
    return ans;
}
int ways[N][N][N][4];
int calcways(int a,int b,int c,int d)
{

    if(a==0&&b==0&&c==0)
        return dp[a][b][c][d]=1;
    if(ways[a][b][c][d]!=-1)
        return ways[a][b][c][d];
    //printf("%i %i %i %i\n",a,b,c,d);
    ways[a][b][c][d]=0;
    if(d!=0&&a)
        ways[a][b][c][d]=add(ways[a][b][c][d],calcways(a-1,b,c,0));
    if(d!=1&&b)
        ways[a][b][c][d]=add(ways[a][b][c][d],calcways(a,b-1,c,1));
    if(d!=2&&c)
        ways[a][b][c][d]=add(ways[a][b][c][d],calcways(a,b,c-1,2));
    return ways[a][b][c][d];
}
vector<int> fact;
int main()
{
    fact.pb(1);
    for(int i=1;i<N;i++)
        fact.pb(mul(fact.back(),i));
    memset(ways,-1,sizeof(ways));
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++)
                for(int o=0;o<4;o++)
                    calcways(i,j,k,o);
    //printf("%i\n",calcways(1,1,1,4));
	scanf("%i %i",&n,&T);
	for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%i %i",&a,&b);
        songs[b-1].pb(a);
    }
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N*N;k++)
                for(int o=0;o<3;o++)
                    calc(i,j,k,o);
    int ans=0;
    for(int i=0;i<=(int)songs[0].size();i++)
    {
        for(int Ki=0;Ki<=T;Ki++)
        {
            int sol=dp[0][i][Ki][0];
            if(sol==0)
                continue;
            for(int j=0;j<=(int)songs[1].size();j++)
            {
                for(int k=0;k<=(int)songs[2].size();k++)
                {
                    int total=i+j+k;
                    int anss=ways[i][j][k][3];
                    anss=mul(anss,mul(fact[i],mul(fact[j],fact[k])));
                    if(anss==0)
                        continue;
                    anss=mul(anss,sol);
                    for(int Kj=0;Kj<=T-Ki;Kj++)
                    {
                        int sol2=dp[0][j][Kj][1];
                        if(sol2==0)
                            continue;
                        int Kk=T-Ki-Kj;
                        int sol3=dp[0][k][Kk][2];
                        int dodajem=mul(mul(anss,sol2),sol3);
                        ans=add(ans,dodajem);
                    }
                }
            }
        }
    }
    printf("%i\n",ans);
    return 0;
}