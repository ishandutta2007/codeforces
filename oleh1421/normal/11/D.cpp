#include<bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=19;
int a[N][N];
ll dp[(1<<N)][N];
int main(){
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++){
        int x,y;cin>>x>>y;
        x--;
        y--;
        a[x][y]=a[y][x]=1;
    }
    ll res=0ll;
    for (int mn=0;mn<n;mn++){
        memset(dp,0,sizeof(dp));
        dp[(1<<mn)][mn]=1;
        for (int mask=0;mask<(1<<n);mask+=(1<<mn)){
            for (int v=mn;v<n;v++){
                if (!(mask&(1<<v))) continue;
                for (int to=mn+1;to<n;to++){
                    if (!a[v][to]) continue;
                    if (mask&(1<<to)) continue;
                    dp[mask^(1<<to)][to]+=dp[mask][v];
                }
                if (__builtin_popcount(mask)>2 && a[v][mn]) res+=dp[mask][v];
            }
        }
    }
    cout<<res/2ll<<endl;

    return 0;
}