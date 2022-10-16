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

const int N=2e3+5,mod=1e9+7;
int add(int a,int b)
{
    a+=b;
    if(a>=mod)
        a-=mod;
    return a;
}
int sub(int a,int b)
{
    a-=b;
    if(a<0)
        a+=mod;
    return a;
}
int mul(int a,int b)
{
    return (ll)a*b%mod;
}
int dp[N][N][2],cnt[N][N];
vector<string> mat;
int get(int x1,int y1,int x2,int y2)
{
    if(x1>x2||y1>y2)
        return 0;
    int sol=cnt[x2][y2];
    if(x1)
        sol-=cnt[x1-1][y2];
    if(y1)
        sol-=cnt[x2][y1-1];
    if(x1&&y1)
        sol+=cnt[x1-1][y1-1];
    return sol;
}
int getDp(int x1,int y1,int x2,int y2,int i)
{
    if(x1>x2||y1>y2)
        return 0;
    int sol=dp[x2][y2][i];
    if(x1)
        sol=sub(sol,dp[x1-1][y2][i]);
    if(y1)
        sol=sub(sol,dp[x2][y1-1][i]);
    if(x1&&y1)
        sol=add(sol,dp[x1-1][y1-1][i]);
    return sol;
}
int main()
{
	int n,m;
	scanf("%i %i",&n,&m);
	mat.resize(n);
	for(int i=0;i<n;i++)
        cin >> mat[i],reverse(all(mat[i]));
    reverse(all(mat));
    string dd(m-1,'R');
    dd+='.';
    mat.pb(dd);
    n++;
    //cout << mat << endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cnt[i][j]=mat[i][j]=='R';
            if(i)
                cnt[i][j]+=cnt[i-1][j];
            if(j)
                cnt[i][j]+=cnt[i][j-1];
            if(i&&j)
                cnt[i][j]-=cnt[i-1][j-1];
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<2;k++)
            {
                if(i==0)
                {
                    dp[i][j][k]=get(i,0,i,j)==0;
                    //printf("dp[%i][%i][%i]: %i\n",i,j,k,dp[i][j][k]);
                    if(j)
                        dp[i][j][k]=add(dp[i][j][k],dp[i][j-1][k]);
                    continue;
                }
                if(j==0)
                {
                    dp[i][j][k]=get(0,j,i,j)==0;
                    //printf("dp[%i][%i][%i]: %i\n",i,j,k,dp[i][j][k]);
                    if(i)
                        dp[i][j][k]=add(dp[i][j][k],dp[i-1][j][k]);
                    continue;
                }
                if(k==0)
                    dp[i][j][k]=getDp(i,get(i,0,i,j-1),i,j-1,1);
                else
                    dp[i][j][k]=getDp(get(0,j,i-1,j),j,i-1,j,0);
                //printf("dp[%i][%i][%i]: %i\n",i,j,k,dp[i][j][k]);
                dp[i][j][k]=add(dp[i][j][k],dp[i-1][j][k]);
                dp[i][j][k]=add(dp[i][j][k],dp[i][j-1][k]);
                dp[i][j][k]=sub(dp[i][j][k],dp[i-1][j-1][k]);
            }
    printf("%i\n",getDp(n-1,m-1,n-1,m-1,1));
    return 0;
}