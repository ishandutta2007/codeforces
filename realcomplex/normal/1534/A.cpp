#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 60;
char conf[N][N];

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        int n, m;
        cin >> n >> m;
        for(int i = 0 ; i <= n + 1; i ++ ){
            for(int j = 0 ; j <= m + 1; j ++ ){
                conf[i][j] = '?';
            }
        }
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= m ; j ++ ){
                cin >> conf[i][j];
            }
        }
        int p0 = 1;
        int p1 = 1;
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= m ; j ++ ){
                if(conf[i][j] == 'R'){
                    if((i + j) % 2 == 1) p0 = 0;
                    else p1 = 0;
                }
                else if(conf[i][j] == 'W'){
                    if((i + j) % 2 == 0) p0 = 0;
                    else p1 = 0;
                }
            }
        }
        if(p0){
            cout << "YES\n";
            for(int i = 1; i <= n; i ++ ){
                for(int j = 1; j <= m ; j ++ ){
                    if((i + j) % 2 == 0) cout << "R";
                    else cout << "W";
                }
                cout << "\n";
            }
        }
        else if(p1){
            cout << "YES\n";
            for(int i = 1; i <= n; i ++ ){
                for(int j = 1; j <= m ; j ++ ){
                    if((i + j) % 2 == 1) cout << "R";
                    else cout << "W";
                }
                cout << "\n";
            }
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}