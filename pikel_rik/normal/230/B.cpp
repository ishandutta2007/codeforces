#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, x;
    cin >> n;

    vector<string> ans(n);

    bool visited[1000001];
    memset(visited, true, sizeof(visited));
    for (int i = 2; i*i <= 1000000; i++) {
        if (visited[i]) {
            for (int j = i*i; j <= 1000000; j+=i) {
                visited[j] = false;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x >= 4 and sqrt(x) == (int)sqrt(x) and visited[(int)sqrt(x)])
            ans[i] = "YES";
        else
            ans[i] = "NO";
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}