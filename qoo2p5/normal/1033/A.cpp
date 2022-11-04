#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const long long INF = (long long) 1e12 + 100;

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = 1005;

int n;
int ax, ay, bx, by, cx, cy;
bool used[N][N];

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

void dfs(int i, int j) {
    if (used[i][j]) return;
    used[i][j] = 1;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            dfs(i + dx, j + dy);
        }
    }
}

void run() {
    cin >> n >> ax >> ay >> bx >> by >> cx >> cy;
    memset(used, 1, sizeof used);
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) used[i][j] = 0;
    for (int i = 0; i <= n; i++) {
        if (ax + i <= n) used[ax + i][ay] = 1;
        if (ay + i <= n) used[ax][ay + i] = 1;
        if (ax - i >= 1) used[ax - i][ay] = 1;
        if (ay - i >= 1) used[ax][ay - i] = 1;
        if (ax + i <= n && ay + i <= n) used[ax + i][ay + i] = 1;
        if (ax + i <= n && ay - i >= 1) used[ax + i][ay - i] = 1;
        if (ax - i >= 1 && ay + i <= n) used[ax - i][ay + i] = 1;
        if (ax - i >= 1 && ay - i >= 1) used[ax - i][ay - i] = 1;
    }
    dfs(bx, by);
    cout << (used[cx][cy] ? "YES" : "NO") << "\n";
}