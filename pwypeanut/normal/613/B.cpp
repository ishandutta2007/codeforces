#include <bits/stdc++.h>
using namespace std;

int N, A, cf, cm;
long long arr[100005], pref[100005];
pair<long long, int> pos[100005];
long long M;

long long lift(int x, int len) { // cost to lift min to x
    int pos1 = lower_bound(arr, arr + len, x) - arr - 1;
    if (x == -1) return 0;
    return (long long)(pos1 + 1) * x - pref[pos1];
}

int main() {
    cin >> N >> A >> cf >> cm >> M;
    for (int i = 0; i < N; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) pos[i].first = arr[i];
    sort(arr, arr + N);
    for (int i = 0; i < N; i++) pref[i] = arr[i];
    for (int i = 1; i < N; i++) pref[i] += pref[i-1];
    long long ans = -1, thres = 0, mini = 0;
    for (int i = 0; i <= N; i++) {
        // i = number of things i should max out
        long long costmax = (long long)A * i - (pref[N-1] - ((N-1-i < 0) ? 0 : pref[N-1-i]));
        long long costleft = M - costmax;
        if (costleft < 0) continue;
        int bot = 0, top = A + 1, mid;
        while (bot + 1 < top) {
            mid = (bot + top) / 2;
            long long costlift = lift(mid, N - i);
            if (costlift > costleft) top = mid;
            else bot = mid;
        }
        long long curans = (long long)i * cf + (long long)bot * cm;
        if (curans > ans) {
            //printf("%d\n", i);
            ans = curans;
            thres = arr[N - i - 1];
            mini = bot;
        }
    }
    cout << ans << endl;
    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        if (pos[i].first > thres) cout << A;
        else cout << max(mini, pos[i].first);
    }
    cout << endl;
}