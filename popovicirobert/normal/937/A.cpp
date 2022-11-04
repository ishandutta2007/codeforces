#include <bits/stdtr1c++.h>

using namespace std;

int v[601];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(true);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    sort(v + 1, v + n + 1);
    int ans = 0;
    v[0] = -1e9;
    for(i = 1; i <= n; i++) {
        if(v[i] > 0 && v[i] != v[i - 1])
            ans++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}