#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()

using namespace std;
using ull = unsigned long long;
using ll = long long;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 5e5 + 5;
const int s = 1e6;

int n, X[N];
bool visited[s+1], done[s+1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> X[i]; //sum(X) - |X| = s|Y| - sum(Y) //x, s - (x - 1), x - 1 + s - x => s - 1
        visited[X[i]] = true;
    }

    int cur = 1;
    cout << n << "\n";

    for (int i = 0; i < n; i++) {
        if (done[X[i]]) continue;

        if (!visited[s - X[i] + 1]) {
            cout << s - X[i] + 1 << " ";
            visited[s - X[i] + 1] = true;
        }
        else {
            while (visited[cur] or visited[s - cur + 1])
                cur += 1;

            visited[cur] = visited[s - cur + 1] = true;
            cout << cur << " " << s - cur + 1 << " ";

            done[s - X[i] + 1] = true;
        }
        done[X[i]] = true;
    }
    return 0;
}