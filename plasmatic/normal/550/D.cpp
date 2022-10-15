// ./d-regular-bridge.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K; cin >> K;
    if (K % 2 == 0) cout << "NO\n";
    else if (K == 1) cout << "YES\n2 1\n1 2\n";
    else {
        cout << "YES\n" << 2*(2*K-1) << ' ' << 2*(K*(K-1)+(K/2))+1 << '\n';

        for (auto i = 1; i <= K; i++)
            for (auto j = 1; j < K; j++)
                cout << i << ' ' << K+j << '\n';
        for (auto i = 2; i <= K; i += 2)
            cout << i << ' ' << i+1 << '\n';

        for (auto i = 1; i <= K; i++)
            for (auto j = 1; j < K; j++)
                cout << 2*K-1+i << ' ' << 3*K-1+j << '\n';
        for (auto i = 2; i <= K; i += 2)
            cout << 2*K-1+i << ' ' << 2*K+i << '\n';

        cout << "1 " << 2*K << '\n';
    }

    return 0;
}