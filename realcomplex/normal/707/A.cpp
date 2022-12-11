#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {

    ios_base::sync_with_stdio(false);cin.tie(false);
    int n,m;
    cin >> n >> m;
    char s;
    for(int i = 0;i<n;i++){
        for(int x = 0;x<m;x++){
            cin >> s;
            if(s != 'B' && s != 'W' && s!='G'){
                cout << "#Color";
                return 0;
            }
        }
    }
    cout << "#Black&White";
    return 0;
}