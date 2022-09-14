#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define endl '\n'
const int N=85;
int dp[N][N][N*N/2];
int gr0[N][N];
int gr1[N][N];
vector<int>g[2];
int a[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i],g[a[i]].push_back(i);
    a[n+1]=1;
    g[1].push_back(n+1);
    for (int i=0;i<g[0].size();i++){
        for (int j=0;j<g[1].size();j++){
            gr0[i+1][j+1]=max(g[1].begin()-upper_bound(g[1].begin(),g[1].end(),g[0][i])+j+1,0);
            gr1[i+1][j+1]=max(g[0].begin()-upper_bound(g[0].begin(),g[0].end(),g[1][j])+i+1,0);
//            cout<<i+1<<" "<<j+1<<" "<<gr1[i+1][j+1]<<endl;
        }
    }
    n++;
    for (int i=0;i<=n;i++){
        for (int j=0;j<=n;j++){
            for (int t=0;t<=n*(n-1)/2;t++){
                dp[i][j][t]=N*N*N;
            }
        }
    }
    dp[0][0][0]=0;
    for (int i=0;i<n;i++){
        for (int j=0;j<=i && j<=g[0].size();j++){
            if (i-j>g[1].size()) continue;
            for (int t=0;t<=n*(n-1)/2;t++){
                int sum=0;
                for (int num=0;i+num+1<=n && j+num<=g[0].size();num++){
//                    if (dp[i][j][t]+num*(num-1)/2==0 && i+1==4 && j+num==3 && t+gr0[j+num][i-j]==0){
//                        cout<<"OOOK\n";
//                        cout<<i<<" "<<j<<" "<<t<<endl;
//                    }
                    if (num) sum+=gr0[j+num][i-j];
                    dp[i+num+1][j+num][t+sum+gr1[j+num][i-j+1]]=min(dp[i+num+1][j+num][t+sum+gr1[j+num][i-j+1]],dp[i][j][t]+num*(num-1)/2);
                }
            }
 
        }
    }
    n--;
    int tot=(int)g[0].size()*((int)g[0].size()-1)/2;
    int mx=0;
    for (int k=0;k<=n*(n-1)/2;k++){
        mx=max(mx,tot-dp[n+1][g[0].size()][k]);
        cout<<mx<<" ";
    }
    cout<<endl;
    return 0;
}