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

const int N=51;
vector<string> mat(N);
int n;
int dp[N][N][N][N];
int sum[N][N];
int get(int x1,int y1,int x2,int y2)
{
    int s=sum[x2][y2];
    if(y1)
        s-=sum[x2][y1-1];
    if(x1)
        s-=sum[x1-1][y2];
    if(x1&&y1)
        s+=sum[x1-1][y1-1];
    return s;
}
int calc(int x1,int y1,int x2,int y2)
{
    if(x1>x2||y1>y2)
        return 0;
    if(dp[x1][y1][x2][y2]!=-1)
        return dp[x1][y1][x2][y2];
    if(get(x1,y1,x2,y2)==0)
        return dp[x1][y1][x2][y2]=0;
    dp[x1][y1][x2][y2]=max(x2-x1+1,y2-y1+1);
    for(int i=x1;i<x2;i++)
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],calc(x1,y1,i,y2)+calc(i+1,y1,x2,y2));
    for(int i=y1;i<y2;i++)
        dp[x1][y1][x2][y2]=min(dp[x1][y1][x2][y2],calc(x1,y1,x2,i)+calc(x1,i+1,x2,y2));
    return dp[x1][y1][x2][y2];
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%i",&n);
	for(int i=0;i<n;i++)
        cin >> mat[i];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            sum[i][j]=mat[i][j]=='#';
            if(i)
                sum[i][j]+=sum[i-1][j];
            if(j)
                sum[i][j]+=sum[i][j-1];
            if(i&&j)
                sum[i][j]-=sum[i-1][j-1];
        }
    printf("%i\n",calc(0,0,n-1,n-1));
    return 0;
}