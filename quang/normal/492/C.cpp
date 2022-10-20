#include <bits/stdc++.h>
#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

long long n, r, avg, sum = 0;
pair<long long, long long> a[N];

bool cmp(pair<long long, long long> x, pair<long long, long long> y) {
    return x.second < y.second;
}

int main() {
    ios_base::sync_with_stdio(0);
  //  fi, fo;
    cin >> n >> r >> avg;
    avg = (avg * n);
    for(int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].first;
        a[i].first = r - a[i].first;
    }
    sort(a + 1, a + n + 1, cmp);
    sum = avg - sum;
    if(sum <= 0) {
        cout << 0;
        return 0;
    }
    long long res = 0;
    int cur = 1;
    while(sum > 0) {
        if(sum >= a[cur].first) {
            sum -= a[cur].first;
            res += a[cur].first * a[cur].second;
            cur++;
        }
        else {
            res += sum * a[cur].second;
            sum = 0;
        }
    }
    cout << res;
    return 0;
}