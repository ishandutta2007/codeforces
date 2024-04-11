#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector <long long> happy;

void gen(long long x) {
    if (x > 1000000000) {
        return;
    }
    happy.push_back(x);
    gen(x * 10 + 4);
    gen(x * 10 + 7);
}

long long line(long long l1, long long r1, long long l2, long long r2) {
    long long ll = max(l1, l2);
    long long rr = min(r1, r2);
    return max(0LL, rr - ll + 1);
}

int main() {
    long long l1, r1, l2, r2;
    int k;
    scanf("%I64d %I64d %I64d %I64d %d", &l1, &r1, &l2, &r2, &k);
    happy.push_back(0);
    happy.push_back(2000000000);
    gen(4);
    gen(7);
    sort(happy.begin(), happy.end());
    long long cnt = 0;
    long long all = (r1 - l1 + 1) * (r2 - l2 + 1);
    for (int i = 1; ; i++) {
        int j = i + k - 1;
        if (j >= happy.size() - 1) {
            break;
        }
        cnt += line(l1, r1, happy[i - 1] + 1, happy[i]) * line(l2, r2, happy[j], happy[j + 1] - 1);
        cnt += line(l2, r2, happy[i - 1] + 1, happy[i]) * line(l1, r1, happy[j], happy[j + 1] - 1);
        if (k == 1 && l1 <= happy[i] && happy[i] <= r1 && l2 <= happy[i] && happy[i] <= r2) {
            cnt--;
        }
    }
    double ans = (cnt + 0.0) / all;
    printf("%.9f\n", ans);
    return 0;
}