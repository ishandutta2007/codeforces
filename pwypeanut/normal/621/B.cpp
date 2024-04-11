#include <bits/stdc++.h>
using namespace std;

int N, p[4005], m[4005];

int main() {
    scanf("%d", &N);
    while(N--) {
        int x, y;
        scanf("%d%d", &x, &y);
        p[x + y]++;
        m[x - y + 2000]++;
    }
    long long sum = 0;
        for (int i = 0; i < 4005; i++) sum += (long long)p[i] * (p[i] - 1) / 2 + (long long)m[i] * (m[i] - 1) / 2;
    cout << sum << endl;
}