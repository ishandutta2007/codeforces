#include <bits/stdc++.h>
using namespace std;

int T, N, M, K, A[1000005], B[1000005];
vector< pair<int, long long> > vA, vB;

int main() {
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d%d", &N, &M);
        vA.clear();
        vB.clear();
        for (int i = 0; i < N; i++) scanf("%d", &A[i]);
        scanf("%d", &K);
        for (int i = 0; i < K; i++) scanf("%d", &B[i]);
        for (int i = 0; i < N; i++) {
            int tmp = A[i], mul = 1;
            while (tmp % M == 0) {
                mul *= M;
                tmp /= M;
            }
            if (vA.size() == 0 || vA.back().first != tmp) {
                vA.push_back(make_pair(tmp, mul));
            } else vA.back().second += mul;
        }
        for (int i = 0; i < K; i++) {
            int tmp = B[i], mul = 1;
            while (tmp % M == 0) {
                mul *= M;
                tmp /= M;
            }
            if (vB.size() == 0 || vB.back().first != tmp) {
                vB.push_back(make_pair(tmp, mul));
            } else vB.back().second += mul;
        }
        printf(vA == vB ? "Yes\n" : "No\n");
    }
}