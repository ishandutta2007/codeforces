#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 100000 + 5;

int N;
pair<int,int> p[MAX_N];
long long ans, f[MAX_N];

bool cmp_by_ac(const pair<int,int> &a, const pair<int,int> &b) {
    return a.first + a.second < b.first + b.second;
}

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i ++) {
        scanf("%d%d", &p[i].first, &p[i].second);
        ans += p[i].second;
    }
    sort(p + 1, p + 1 + N);
    int t = 0;
    for (int i = 2, j = 1; i <= N; i ++) {
        if (p[i].first <= p[j].first + p[j].second) {
            f[i] = f[j];
        } else {
            f[i] = f[j] + p[i].first - p[j].first - p[j].second;
        }
        if (p[i].first + p[i].second > p[j].first + p[j].second) {
            j = i;
        }
    }
    printf("%lld\n", ans + f[N]);
    return 0;
}