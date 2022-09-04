#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, k, ans = 100000;

int main(){
    #ifdef ONPC
    ifstream cin("a.in");
    ofstream cout("a.out");
    #endif // ONPC
    ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        if (x > 0 && x <= k)
            ans = min(ans, abs(m - i));
    }
    cout << ans * 10;
}