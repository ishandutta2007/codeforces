#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define INF 1e10
#define fi first
#define se second
#define mp make_pair

int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;
    cin >> n >> m;
    char conf[n+1][m+1];
    int ans = 0;
    for(int j = 1;j<=n;j++){
        for(int i = 1;i<=m;i++){
            cin >> conf[j][i];
            if((conf[j][i] == 'f' || conf[j][i-1] == 'f' || conf[j-1][i] == 'f' || conf[j-1][i-1] == 'f')){
                if((conf[j][i] == 'a' || conf[j][i-1] == 'a' || conf[j-1][i] == 'a' || conf[j-1][i-1] == 'a')){
                    if((conf[j][i] == 'c' || conf[j][i-1] == 'c' || conf[j-1][i] == 'c' || conf[j-1][i-1] == 'c')){
                        if((conf[j][i] == 'e' || conf[j][i-1] == 'e' || conf[j-1][i] == 'e' || conf[j-1][i-1] == 'e')){
                            ans++;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}