#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 55;
char conf[N][N];


void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < N ; i++ ){
        for(int j = 0 ; j < N ;j ++ ){
            conf[i][j] = '.';
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++ ){
            cin >> conf[i][j];
        }
    }
    bool valid = true;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            if(conf[i][j] == '*'){
                for(int xx = -1; xx <= 1; xx += 2){
                    for(int yy = -1; yy <= 1; yy += 2){
                        if(conf[i + xx][j] == '*' && conf[i][j + yy] == '*'){
                            if(conf[i + 2 * xx][j] == '*') valid = false;

                            if(conf[i][j + 2 * yy] == '*') valid = false;

                            if(conf[i + xx][j + yy] == '*') valid = false;

                            if(conf[i + 2 * xx][j + yy] == '*') valid = false;

                            if(conf[i + xx][j + 2 * yy] == '*') valid = false;

                            if(conf[i + 2 * xx][j - yy] == '*') valid = false;
                            if(conf[i + xx][j - yy] == '*') valid = false;
                            if(conf[i][j - yy] == '*') valid = false;
                            if(conf[i - xx][j - yy] == '*') valid = false;
                            if(conf[i - xx][j + 2 * yy] == '*') valid = false;
                            if(conf[i - xx][j + yy] == '*') valid = false;
                            if(conf[i - xx][j] == '*') valid = false;
                            conf[i][j]=conf[i+xx][j]=conf[i][j+yy]='.';
                        }
                    }
                }
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            if(conf[i][j] == '*'){
                valid = false;
            }
        }
    }
    if(valid){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}
int main(){
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;

}