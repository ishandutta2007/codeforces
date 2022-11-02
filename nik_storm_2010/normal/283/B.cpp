#include<iostream>

using namespace std;
const int N = 200000 + 10;

long long a[N], mem[N][2];
int n;

long long solve(int x, int d) {
    if (x <= 0 || x > n) return 0;
    if (mem[x][d] != 0) return mem[x][d];
    mem[x][d] = -1;
    if (d == 0) {
        long long c = solve(x + a[x], 1);
        if (c != -1) mem[x][d] = c + a[x]; else mem[x][d] = c;
    }
    else {
        long long c = solve(x - a[x], 0);
        if (c != -1) mem[x][d] = c + a[x]; else mem[x][d] = c;
    }
    return mem[x][d];
}

int main() {
    cin >> n;
    for (int i = 2; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        mem[1][0] = 0;
        a[1] = i;
        cout << solve(1, 0) << endl;
    }
    return 0;
}