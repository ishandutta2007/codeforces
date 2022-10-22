#include <bits/stdc++.h>
using namespace std;

vector<int> p, ans;

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 2; i <= N; i++) {
        bool np = 0;
        for (int j = 2; j < i; j++) if (i % j == 0) np = 1;
        if (!np) p.push_back(i);
    }
    for (int i = 0; i < p.size(); i++) {
        int v = p[i];
        while (v <= N) {
            ans.push_back(v);
            v *= p[i];
        }
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
    printf("\n");
}