#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair
#define MAXN 100005

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    char conf[n+2][m+2];
    for(int j = 1;j<=n;j++){
        for(int i = 1;i<=m;i++){
            cin >> conf[j][i];
        }
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        for(int x = 1;x<=m;x++){
            if(conf[i][x] == 'W'){
                if(conf[i][x-1] == 'P' ||conf[i][x+1] == 'P' || conf[i-1][x] == 'P' || conf[i+1][x] == 'P'){
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}