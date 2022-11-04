#include <bits/stdc++.h>
#define lsb(x)

using namespace std;

const int MAXN = (int) 2e5;

bool ok[MAXN + 1];

int main(){
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, x;
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    ok[0] = 1;
    for(i = 1; i <= n; i++) {
        cin >> x;
        if(ok[x] == 1)
            ok[x] = 0;
        else
            ans++;
        ok[i] = 1;
    }
    cout << ans + 1;
    //cin.close();
    //cout.close();
    return 0;
}