#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 5e5 + 5;

int n, p[2*N];
int pairs[N];

int visited[2*N];

int main() {
    ios::sync_with_stdio(false);

    cin >> n;

    if (n % 2 == 0) {
        cout << "First\n";
        for (int i = 0; i < n; i++)
            cout << i + 1 << ' ';
        for (int i = 0; i < n; i++)
            cout << i + 1 << ' ';
        cout << endl;

        int answer;
        cin >> answer;
    } else {
        cout << "Second" << endl;
        for (int i = 1; i <= 2 * n; i++) {
            cin >> p[i];
            pairs[p[i]] ^= i;
        }

        memset(visited, -1, sizeof(visited));
        for (int i = 1; i <= n; i++) {
            if (visited[i] == -1) {
                int x = i;
                while (true) {
                    int y = x ^ pairs[p[x]];
                    if (visited[x] != -1 or visited[y] != -1)
                        break;
                    visited[x] = 1;
                    visited[y] = 0;
                    if (y > n) {
                        x = y - n;
                    } else x = y + n;
                }
            }
        }

        ll sum = 0;
        for (int i = 1; i <= 2 * n; i++) {
            if (visited[i])
                sum += i;
        }
        if (sum % (2 * n) == 0) {
            for (int i = 1; i <= 2 * n; i++) {
                if (visited[i])
                    cout << i << ' ';
            }
        } else {
            for (int i = 1; i <= 2 * n; i++) {
                if (!visited[i])
                    cout << i << ' ';
            }
        }

        cout << endl;
        int correct;
        cin >> correct;
    }
    return 0;
}