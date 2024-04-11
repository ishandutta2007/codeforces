#include <bits/stdc++.h>
using namespace std;

int N, twos[1000005], fives[1000005];
vector<int> ans;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= 1000000; i++) {
        int ti = i;
        while (ti % 2 == 0) {
            twos[i]++;
            ti/=2;
        }
        ti = i;
        while (ti % 5 == 0) {
            fives[i]++;
            ti/=5;
        }
    }
    int ts = 0, fs = 0;
    for (int i = 1; i <= 1000000; i++) {
        ts += twos[i];
        fs += fives[i];
        int a = min(ts, fs);
        if (a == N) ans.push_back(i);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) {
        if (i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
}