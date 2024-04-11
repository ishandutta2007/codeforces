#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    int l, r;
    l = m;
    r = -1;
    char c[n][m];

    int empr, empc;
    empr = n;
    empc = m;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            cin >> c[i][j];
        }
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(c[i][j] == '#'){
                empr--;
                break;
            }
        }
    }

    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            if(c[j][i] == '#'){
                empc--;
                break;
            }
        }
    }

    if((empc > 0) ^ (empr > 0)){
        cout << -1;
        return 0;
    }

    int ans = 0;

    //cout << "KENCR" << endl;

    for(int j = 0; j<m; j++){
        int u, d, cnt2;
        cnt2 = 0;
        for(int i = 0; i<n; i++){
            if(c[i][j] == '#'){
                u = i;
                break;
            }
        }

        for(int i = 0; i<n; i++){
            if(c[i][j] == '#'){
                d = i;
                cnt2++;
            }
        }

        if(cnt2 == 0) continue;
        if(d - u != cnt2 - 1){
            cout << -1;
            return 0;
        }
    }

    for(int i = 0; i<n; i++){
        int ll = m;
        int cnt = 0;
        int rr = -1;

        for(int j = 0; j<m; j++){
            if(c[i][j] == '#'){
                ll = j;
                break;
            }
        }

        for(int j = 0; j<m; j++){
            if(c[i][j] == '#'){
                rr = j;
                cnt++;
            }
        }

        if(cnt == 0){
            r = -1;
            l = m;
            continue;
        }

        //cout << ll << " " << rr << endl;
        if(rr - ll != cnt - 1){
            cout << -1;
            return 0;
        }

        if(r < ll){
            l = ll;
            r = rr;
            ans++;
            continue;
        }

        if(l > rr){
            l = ll;
            r = rr;
            ans++;
            continue;
        }

        l = ll;
        r = rr;
    }

    cout << ans << endl;


}