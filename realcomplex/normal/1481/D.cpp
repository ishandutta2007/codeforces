#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
char typ[N][N];
int in[N][2];
int out[N][2];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        for(int d =0 ; d < 2; d ++ ){
            in[i][d] = -1;
            out[i][d] = -1;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cin >> typ[i][j];
            if(typ[i][j] == 'a'){
                in[j][0]=i;
                out[i][0]=j;
            }
            else if(typ[i][j] == 'b'){
                in[j][1]=i;
                out[i][1]=j;
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n ; j ++ ){
            if(typ[i][j] == typ[j][i] && typ[i][j] != '*'){
                cout << "YES\n";
                for(int b = 1; b <= m + 1; b ++ ){
                    if(b % 2 == 1){
                        cout << i << " ";
                    }
                    else{
                        cout << j << " ";
                    }
                }
                cout << "\n";
                return;
            }
        }
    }
    if(m % 2 == 0){
        for(int i = 1; i <= n; i ++ ){
            for(int p = 0 ;p < 2; p ++ ){
                if(in[i][p] != -1 && out[i][p] != -1){
                    vector<int> lef, rig;
                    cout << "YES\n";
                    for(int j = 0; j < m/2;j ++ ){
                        if(j % 2 == 0){
                            lef.push_back(in[i][p]);
                            rig.push_back(out[i][p]);
                        }
                        else{
                            lef.push_back(i);
                            rig.push_back(i);
                        }
                    }
                    reverse(lef.begin(), lef.end());
                    for(auto x : lef){
                        cout << x << " ";
                    }
                    cout << i << " ";
                    for(auto x : rig){
                        cout << x << " ";
                    }
                    return;
                }
            }
        }
    }
    else{
        for(int p = 1; p <= n; p ++ ){
            for(int q = 1; q <= n; q ++ ){
                if(typ[p][q] != '*'){
                    for(int b = 0; b < 2; b ++ ){
                        if(in[p][b] != -1 && out[q][b] != -1){
                            vector<int> lef, rig;
                            for(int t = 0; t < m/2; t ++ ){
                                if(t % 2 == 0){
                                    lef.push_back(in[p][b]);
                                    rig.push_back(out[q][b]);
                                }
                                else{
                                    lef.push_back(p);
                                    rig.push_back(q);
                                }
                            }
                            reverse(lef.begin(), lef.end());
                            cout << "YES\n";
                            for(auto x : lef) cout << x << " ";
                            cout << p << " " << q << " ";
                            for(auto x : rig) cout << x << " ";
                            cout << "\n";
                            return;
                        }
                    }
                }
            }
        }
    }
    cout << "NO\n";
}

int main(){
    fastIO;
    int testc;
    cin >> testc;
    for(int ti = 1; ti <= testc; ti ++ ){
        solve();
    }
    return 0;
}