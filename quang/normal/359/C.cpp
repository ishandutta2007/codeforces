#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010, MOD = 1000000007;

int n, x;
long long sum;

long long Pow(long long a) {
    long long res = 1;
    for(long long j = 1ll * x; a; j = j * j % MOD) {
        if(a % 2) res = res * j % MOD;
        a /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> x;
    vector <long long> a(n + 1, 0), b;
    for(int i = 1; i <= n; i++) cin >> a[i], sum += a[i];
    for(int i = 1; i <= n; i++) b.push_back(sum - a[i]);
    sort(b.rbegin(), b.rend());

    while(1) {
        long long v = b.back();
        int cnt = 0;
        if(b.back() >= sum) {
            cout << Pow(sum);
            return 0;
        }
        while(!b.empty() && b.back() == v) {
            cnt++;
            b.pop_back();
        }
        if(cnt % x) {
            cout << Pow(v);
            return 0;
        } else {
            for(int i = 1; i <= cnt / x; i++)
                b.push_back(v + 1);
        }
    }
    return 0;
}