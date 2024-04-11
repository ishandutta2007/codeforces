#include <bits/stdc++.h>
using namespace std;

int N, Q, arr[100005], arr2[100005];
pair<int, int> st[100005][18];


pair<int, int> query(int x, int y) {
    int l = (y - x + 1);
    int level = log2(l);
    return max(st[x][level], st[y - (1 << level) + 1][level]);
}

long long f(int x, int y) {
    if (x > y) return 0;
    pair<int, int> m = query(x, y);
    int l = m.second - x + 1, r = (y - x) - l + 2;
    //printf("%d %d: %d %d %d\n", x, y, l, r, m.first);
    return f(x, m.second - 1) + f(m.second + 1, y) + (long long)l * r * m.first;
}

int main() {
    scanf("%d%d", &N, &Q);
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    for (int i = 0; i < N-1; i++) arr2[i] = abs(arr[i+1] - arr[i]);
    for (int i = 0; i < N; i++) st[i][0] = make_pair(arr2[i], i);
    for (int i = 1; i <= log2(N); i++) {
        for (int j = 0; j <= N - (1 << i); j++) st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
    }
    for (int i = 0; i < Q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y-=2;
        cout << f(x, y) << endl;
    }
}