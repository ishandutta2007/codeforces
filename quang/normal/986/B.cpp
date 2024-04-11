#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n;
int a[N];
bool used[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    memset(used, 0, sizeof used);
    int cyc = 0;
    for (int i = 1; i <= n; i++) {
        if (used[i]) {
            continue;
        }
        cyc++;
        int u = i;
        while (!used[u]) {
            used[u] = 1;
            u = a[u];
        }
    }
    puts((cyc % 2 == 0) ? "Petr" : "Um_nik");
    return 0;
}