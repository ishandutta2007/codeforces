#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, q;
    cin >> n >> p;

    vector<int> a(p, 0);
    for (int i = 0; i < p; i++) {
        cin >> a[i];
    }

    cin >> q;
    vector<int> b(q, 0);
    for (int i = 0; i < q; i++) {
        cin >> b[i];
    }

    vector<int> visited(n, 0);
    for (int i = 0; i < p; i++) {
        visited[a[i]-1] = 1;
    }
    for (int i = 0; i < q; i++) {
        visited[b[i]-1] = 1;
    }

    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
        cout << "Oh, my keyboard!";
    else
        cout << "I become the guy.";

    return 0;
}