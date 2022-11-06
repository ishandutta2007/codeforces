#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;

const int N = (int) 1e5 + 123;

int n;
int cnt[N];

void run() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        
        for (int d = 1; d * d <= s; d++) {
            int subd = s / d;
            if (d * subd != s) {
                continue;
            }
            
            cnt[d]++;
            if (subd != d) {
                cnt[subd]++;
            }
        }
    }
    
    int ans = *max_element(cnt + 2, cnt + N);
    ans = max(ans, 1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}