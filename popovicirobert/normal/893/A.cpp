#include <bits/stdc++.h>
#define lsb(x)
#define ll long long

using namespace std;

bool ok[4];

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, j, x;
    ios::sync_with_stdio(false);
    cin >> n;
    ok[1] = ok[2] = 1;
    for(i = 1; i <= n; i++) {
        cin >> x;
        if(ok[x] == 0) {
            cout << "NO";
            return 0;
        }
        for(j = 1; j <= 3; j++) {
            if(ok[j] == 0)
                ok[j] = 1;
            else if(ok[j] == 1 && j != x)
                ok[j] = 0;
        }
    }
    cout << "YES";
    //cin.close();
    //cout.close();
    return 0;
}