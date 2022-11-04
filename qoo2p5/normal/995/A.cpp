#include <bits/stdc++.h>

using namespace std;

void run();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
    return 0;
}

const int N = 101;

struct Op {
    int i, r, c;
};

int n, k;
int a[4][N];
vector<Op> ops;

bool can() {
    for (int i = 0; i < n; i++) {
        if (a[0][i] > 0 && a[0][i] == a[1][i]) {
            ops.push_back({a[0][i], 1, i + 1});
            a[1][i] = 0;
            return true;
        }
        if (a[2][i] > 0 && a[2][i] == a[3][i]) {
            ops.push_back({a[2][i], 4, i + 1});
            a[2][i] = 0;
            return true;
        }
    }
    return false;
}

int count() {
    int result = 0;
    for (int i = 0; i < n; i++) {
        if (a[1][i]) {
            result++;
        }
        if (a[2][i]) {
            result++;
        }
    }
    return result;
}

void nxt(int &x, int &y) {
    if (x == 1) {
        if (y == n - 1) {
            x = 2;
        } else {
            y++;
        }
    } else if (x == 2) {
        if (y == 0) {
            x = 1;
        } else {
            y--;
        }
    } else {
        assert(false);
    }
}

void run() {
    cin >> n >> k;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    
    while (can());
    
    if (count() == 2 * n) {
        cout << "-1\n";
        return;
    }
    
    for (int shift = 0; shift < 102; shift++) {
        int x = -1, y = -1;
        for (int i = 0; i < n; i++) {
            if (a[1][i] == 0) {
                x = 1, y = i;
                break;
            }
            if (a[2][i] == 0) {
                x = 2, y = i;
                break;
            }
        }
        
        assert(x != -1 && y != -1);
        
        int sx = x, sy = y;
        int prv_x = sx, prv_y = sy;
        nxt(sx, sy);
        
        for (int i = 0; i < 2 * n - 1; i++) {
            assert(a[prv_x][prv_y] == 0);
            if (a[sx][sy]) {
                ops.push_back({a[sx][sy], prv_x + 1, prv_y + 1});
                swap(a[sx][sy], a[prv_x][prv_y]);
            }
            nxt(prv_x, prv_y);
            nxt(sx, sy);
        }
        
        while (can());
    }
    
    if (count() == 0) {
        cout << (int) ops.size() << "\n";
        for (auto &it : ops) {
            cout << it.i << " " << it.r << " " << it.c << "\n";
        }
    } else {
        cout << "-1\n";
    }
}