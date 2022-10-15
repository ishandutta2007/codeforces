#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "petrol.inp"
#define FILE_OUT "petrol.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(1000000007))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define endl "\n"
typedef long long ll;
//-------------HASH----------//
//-------------END-----------//
int n,m,i,j,k,t,t1,p,aad,bad,bruh[30],maxx=0,istree,cnt=0;
int used[100001],a[10001],tab[11]={2,3,5,7,11,13,17,19,23,29,31};
string s,md[5001];
vector<int> gt[100001];
void dfs(int cur, int prev)
{
    if (!istree) return;
    used[cur]=1;
    for (int i=0;i<gt[cur].size();i++)
    {
        int a=gt[cur][i];
        if (a!=prev)
        {
            if (used[a]) {istree=0; return;}
            else dfs(a,cur);
        }
    }
}
int main(){
 //   ofile;
    nfio;
    cin>>n>>m;
    for (i=0;i<m;i++)
    {
        cin>>aad>>bad;
        gt[aad].push_back(bad);
        gt[bad].push_back(aad);
    }
    for (i=1;i<=n;i++) if (!used[i])
    {
        istree=1;
        dfs(i,i);
        cnt+=istree;
    }
    cout<<cnt;
}