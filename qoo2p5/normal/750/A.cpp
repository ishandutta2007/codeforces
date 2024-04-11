#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void run() {
    int n, k;
    cin >> n >> k;
    int res = 0;
    int cur_t = 240 - k;
    while (res < n && cur_t - 5 * (res + 1) >= 0) {
        res++;
        cur_t -= 5 * res;
    }
    
    cout << res << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}