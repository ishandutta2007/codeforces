#include <bits/stdc++.h>
using namespace std;

int N, T, arr[105], no[305], dpfront[105][305], dpback[105][305];
vector< pair<int, int> > V[105], back[105];

int main() {
    scanf("%d%d", &N, &T);
    T--;
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
    memset(dpfront, -63, sizeof(dpfront));
    memset(dpback, -63, sizeof(dpback));
    for (int i = 0; i < N; i++) no[arr[i]]++;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (arr[i] <= arr[j]) {
                V[i].push_back(make_pair(j, 0));
                back[j].push_back(make_pair(i, 0));
            }
        }
        for (int j = 0; j < i; j++) {
            if (arr[i] <= arr[j]) {
                V[i].push_back(make_pair(j, 1));
                back[j].push_back(make_pair(i, 1));
            }
        }
    }
    for (int i = 0; i < N; i++) dpfront[i][0] = 1;
    for (int i = 0; i <= 300; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < back[j].size(); k++) {
                if (i - back[j][k].second >= 0) dpfront[j][i] = max(dpfront[j][i], dpfront[back[j][k].first][i - back[j][k].second] + 1);
            }
        }
    }
    for (int i = 0; i < N; i++) dpback[i][0] = 1;
    for (int i = 0; i <= 300; i++) {
        for (int j = N - 1; j >= 0; j--) {
            for (int k = 0; k < V[j].size(); k++) {
                if (i - V[j][k].second >= 0) dpback[j][i] = max(dpback[j][i], dpback[V[j][k].first][i - V[j][k].second] + 1);
            }
        }
    }
    //printf("%d\n", dpfront[0][1]);
    int ans = 0, a = 0, b = 0, c = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 300; j++) {
            for (int k = 0; k <= 300; k++) {
                if (j + k > T) continue;
                if (dpfront[i][j] + dpback[i][k] + no[arr[i]] * (T - j - k) > ans) {
                    a = i;
                    b = j;
                    c= k;
                }
                ans = max(ans, dpfront[i][j] + dpback[i][k] + no[arr[i]] * (T - j - k));
            }
        }
    }
    printf("%d\n", ans - 1);
}