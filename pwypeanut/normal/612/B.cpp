#include <bits/stdc++.h>
using namespace std;

pair<int, int> P[200005];
int N;

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &P[i].first);
        P[i].second = i;
    }
    sort(P, P + N);
    long long ans = 0;
    for (int i = 1; i < N; i++) ans += abs(P[i].second - P[i-1].second);
    cout << ans << endl;
}