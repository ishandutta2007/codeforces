#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long a[n];
    vector<int> cnt[60];
    for(int i = 0; i<n; i++){
        cin >> a[i];
        for(int j = 0; j<60; j++){
            if(a[i] & (1LL << j)) cnt[j].push_back(i);
        }
    }

    vector<int> g[n];

    for(int i = 0; i<60; i++){
        if(cnt[i].size() >= 3){
            cout << 3;
            return 0;
        }

        else if(cnt[i].size() == 2){
            g[cnt[i][0]].push_back(cnt[i][1]);
            g[cnt[i][1]].push_back(cnt[i][0]);
        }
    }

    int comp[n];
    int cur = 0;
    for(int i = 0; i<n; i++){
        if(g[i].size()){
            comp[i] = cur;
            cur++;
        }
    }

    int h[cur][cur];
    int dist[cur][cur];
    int ans = 1e9 + 7;

    for(int i = 0; i<cur; i++){
        for(int j = 0; j<cur; j++){
            h[i][j] = 0;
        }
    }

    for(int i = 0; i<n; i++){
        for(int j: g[i]){
            h[comp[i]][comp[j]] = 1;
            h[comp[j]][comp[i]] = 1;
        }
    }
    /*
    for(int i = 0; i<cur; i++){
        for(int j = 0; j<cur; j++){
            cout << h[i][j] << " ";
        }
        cout << endl;
    }
    cout << "KENCR" << endl;
    */
    for(int i = 0; i<cur; i++){
        for(int j = 0; j<cur; j++){
            if(h[i][j] == 1){
                for(int k = 0; k<cur; k++){
                    for(int l = 0; l<cur; l++){
                        if(h[k][l] == 1) dist[k][l] = 1;
                        else dist[k][l] = 1e9 + 7;
                        if(k == i && l == j) dist[k][l] = 1e9 + 7;
                        if(k == j && l == i) dist[k][l] = 1e9 + 7;
                    }
                }

                for(int k = 0; k<cur; k++){
                    for(int l = 0; l<cur; l++){
                        for(int m = 0; m<cur; m++){
                            dist[l][m] = min(dist[l][m], dist[l][k] + dist[k][m]);
                        }
                    }
                }

                ans = min(ans, dist[i][j] + 1);
            }
        }
    }

    if(ans > 1e6){
        cout << -1;
    }

    else cout << ans;



}