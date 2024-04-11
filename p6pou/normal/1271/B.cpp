#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200 + 5;

int N;
char a[MAX_N];

int main() {
    scanf("%d", &N);
    scanf("%s", a + 1);
    int c = 0;
    for (int i = 1; i <= N; i ++) {
        c += a[i] == 'W';
    }
    if (N % 2 == 0 && c % 2 == 1) {
        printf("-1\n");
        return 0;
    }
    char aa = c % 2 == 0 ? 'W' : 'B';
    vector<int> ans;
    for (int i = 1; i < N; i ++) {
        if (a[i] == aa) {
            ans.push_back(i);
            a[i] = 'W' + 'B' - a[i];
            a[i + 1] = 'W' + 'B' - a[i + 1];
        }
    }
    printf("%d\n", ans.size());
    for (auto x: ans) {
        printf("%d ", x);
    }
    printf("\n");
    return 0;
}