#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int a[200001][25];
int cn[200001];
vector<int>g[200001];
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    for (int i=1;i<=n;i++){
        cin>>a[i][0];
        int cnt=0;
        int x=a[i][0];
        while (x){
            x/=2;
            a[i][++cnt]=x;
        }
        cn[i]=cnt;
    }
    for (int l=0;l<=21;l++){
        for (int i=1;i<=n;i++){
            if (cn[i]>=l){
                g[a[i][l]].push_back(l);
            }
        }
    }
    int minx=21*n;
    for (int i=1;i<=200000;i++){
        if (g[i].size()<k) continue;
        int sum=0;
        for (int j=0;j<k;j++) sum+=g[i][j];
        minx=min(minx,sum);
    }
    cout<<minx;


    return 0;
}


///2007521364118