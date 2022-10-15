#include <iostream>

using namespace std;

#define ll long long

int n, m;
string d[2222];
int x[4][2222][2222];
ll s;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> d[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (d[i][j] == '#') break;
            x[0][i][j] = 1;
        }
        if (i != 0 && i != n-1 && x[0][i][m-1]) s++;
        for (int j = m-1; j >= 0; j--) {
            if (d[i][j] == '#') break;
            x[1][i][j] = 1;
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (d[i][j] == '#') break;
            x[2][i][j] = 1;
        }
        if (j != 0 && j != m-1 && x[2][n-1][j]) s++;
        for (int i = n-1; i >= 0; i--) {
            if (d[i][j] == '#') break;
            x[3][i][j] = 1;
        }
    }
    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            if (x[0][i][j] && x[2][i][j]) s++;
            if (x[0][i][j] && x[3][i][j]) s++;
            if (x[1][i][j] && x[2][i][j]) s++;
            if (x[1][i][j] && x[3][i][j]) s++;
        }
    }
    for (int i = 1; i < n-1; i++) {
        ll u = 0;
        for (int j = 1; j < m-1; j++) {
            s += (x[2][i][j]+x[3][i][j])*u;
            u += x[2][i][j];
            u += x[3][i][j];
            if (d[i][j] == '#') u = 0;
            if (j > 1 && x[2][i][j-1] && x[2][i][j]) s--;
            if (j > 1 && x[3][i][j-1] && x[3][i][j]) s--;
        }
    }
    for (int j = 1; j < m-1; j++) {
        ll u = 0;
        for (int i = 1; i < n-1; i++) {
            s += (x[0][i][j]+x[1][i][j])*u;
            u += x[0][i][j];
            u += x[1][i][j];
            if (d[i][j] == '#') u = 0;
            if (i > 1 && x[0][i-1][j] && x[0][i][j]) s--;
            if (i > 1 && x[1][i-1][j] && x[1][i][j]) s--;
        }
    }
    cout << s << "\n";
}