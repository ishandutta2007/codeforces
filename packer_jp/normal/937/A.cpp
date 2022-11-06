#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

#define int long long
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int N;
set<int> a;

signed main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        if (x != 0) {
            a.insert(x);
        }
    }
    cout << a.size() << endl;
    return 0;
}