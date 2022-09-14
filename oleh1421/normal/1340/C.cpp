#include <bits/stdc++.h>
typedef long long ll;
#define endl '\n'
using namespace std;
const int N=10000100;
const int M=10010;
int dp[1010][M];
int d[M];
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;cin>>n>>m;
    for (int i=1;i<=m;i++) cin>>d[i];
    int r,g;cin>>g>>r;
    sort(d+1,d+m+1);
    for (int i=0;i<=1001;i++){
        for (int j=0;j<=m+1;j++){
            dp[i][j]=-1;
        }
    }
    dp[0][1]=0;
    queue<pair<int,int> >q;
    q.push({0,1});
    while (true){
        vector<pair<int,int> >v;
        while (!q.empty()){
            auto cur=q.front();
            v.push_back(cur);
            q.pop();
            int i=cur.first;
            int j=cur.second;
            if (j+1<=m){
                if (d[j+1]-d[j]+i<g){
                    if (dp[d[j+1]-d[j]+i][j+1]==-1){
                        dp[d[j+1]-d[j]+i][j+1]=dp[i][j];
                        q.push({d[j+1]-d[j]+i,j+1});
                    }
                }
            }
            if (j-1>=1){
                if (d[j]-d[j-1]+i<g){
                    if (dp[d[j]-d[j-1]+i][j-1]==-1){
                        dp[d[j]-d[j-1]+i][j-1]=dp[i][j];
                        q.push({d[j]-d[j-1]+i,j-1});
                    }
                }

            }
        }

        for (auto cur:v){
            int i=cur.first;
            int j=cur.second;
            if (j+1<=m){
                if (d[j+1]-d[j]+i==g){
                    if (dp[0][j+1]==-1){
                        dp[0][j+1]=dp[i][j]+1;
                        q.push({0,j+1});
                    }
                }
            }
            if (j-1>=1){
                if (d[j]-d[j-1]+i==g){
                    if (dp[0][j-1]==-1){
                        dp[0][j-1]=dp[i][j]+1;
                        q.push({0,j-1});
                    }
                }
            }
        }
        if (q.empty()) break;
    }
    ll res=-1;
    for (int i=0;i<g;i++){
        if (dp[i][m]==-1) continue;
        ll cur=(r+g+0ll)*(dp[i][m]+0ll)+i;
        if (i==0) cur-=r;
        if (res==-1 || cur<res) res=cur;
    }
    cout<<res;
    return 0;
}