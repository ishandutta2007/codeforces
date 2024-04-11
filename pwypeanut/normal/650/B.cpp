#include <bits/stdc++.h>
using namespace std;

int N, A, B, T;
long long pref[500005], a[500005], np[500005], newpref[500005];
char s[500005];

int main() {
    scanf("%d%d%d%d", &N, &A, &B, &T);
    scanf("%s", &s);
    for (int i = 0; i < N; i++) {
        if (s[i] == 'w') pref[i] = B + 1;
        else pref[i] = 1;
    }
    for (int i = 0; i < N; i++) a[i] = pref[i];
    for (int i = 1; i < N; i++) pref[i] += pref[i - 1];
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        long long sum = pref[i - 1] + (long long)(i - 1) * A;
        if (sum > T) continue;
        long long left = T - sum;
        int bot = 0, top = N - i + 1, mid;
        while (bot + 1 < top) {
            mid = (bot + top) / 2;
            long long cost = (long long)(i - 1 + mid) * A + (pref[N - 1] - pref[N - 1 - mid]);
            if (cost > left) top = mid;
            else bot = mid;
        }
        ans = max(ans, (long long)i + bot);
    }
    for (int i = 0; i < N; i++) np[i] = a[N - i - 1];
    for (int i = 0; i < N; i++) newpref[i] = np[(i + N - 1) % N];
    for (int i = 1; i < N; i++) newpref[i] += newpref[i - 1];

    for (int i = 1; i <= N; i++) {
        long long sum = newpref[i - 1] + (long long)(i - 1) * A;
        if (sum > T) continue;
        long long left = T - sum;
        int bot = 0, top = N - i + 1, mid;
        while (bot + 1 < top) {
            mid = (bot + top) / 2;
            long long cost = (long long)(i - 1 + mid) * A + (newpref[N - 1] - newpref[N - 1 - mid]);
            if (cost > left) top = mid;
            else bot = mid;
        }
        ans = max(ans, (long long)i + bot);
    }

    cout << ans << endl;
}