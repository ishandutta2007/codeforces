#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n;
    cin >> n;
    char p[n][5];
    bool c = false;
    for(int j = 0;j<n;j++){
        for(int x = 0;x<5;x++){
            cin >> p[j][x];
        }
        if(c == false){
            if(p[j][0] == 'O' && p[j][1] == 'O'){
                c = true;
                p[j][0] = '+';
                p[j][1] = '+';
            }
        }
        if(c == false){
            if(p[j][3] == 'O' && p[j][4] == 'O'){
                c = true;
                p[j][3] = '+';
                p[j][4] = '+';
            }
        }
    }
    if(c == false){
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    for(int j = 0;j<n;j++){
        for(int x = 0;x<5;x++){
            cout << p[j][x];
        }
        cout << "\n";
    }
    return 0;
}