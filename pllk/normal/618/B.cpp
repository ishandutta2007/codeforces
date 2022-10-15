#include <iostream>

using namespace std;

int n;
int x[100][100];
int p[100];
int u[100][100];

void tee(int k) {
    for (int i = 1; i <= n; i++) {
        p[i] = x[k][i];
        if (p[i] == 0) p[i] = n;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            u[i][j] = min(p[i],p[j]);
            if (i == j) u[i][j] = 0;
        }
    }
}

bool samat() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (x[i][j] != u[i][j]) return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        tee(i);
        if (samat()) {
            for (int j = 1; j <= n; j++) cout << p[j] << " ";
            cout << "\n";
            return 0;
        }
    }
}