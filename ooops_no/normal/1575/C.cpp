#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int MOD = 1e9 + 7, N = 2e5 + 10;
int t[N];

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b){
    return a - b < 0 ? a - b + MOD : a - b;
}

int mul(int a, int b){
    return (a * b % MOD);
}

void inc(int i, int d){
    for (; i < N; i = (i | (i + 1))){
        t[i] += d;
    }
}

int get(int r){
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1){
        ans += t[r];
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), pr(n + 1), ind(k);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        pr[i + 1] = (pr[i] + a[i]) % k;
    }
    if (pr.back() == 0){
        vector<int> cnt(k);
        for (int i = 1; i <= n; i++){
            cnt[pr[i]] = add(cnt[pr[i]], m);
        }
        int ans = 0;
        for (int i = 0; i < k; i++){
            ans = add(ans, mul(cnt[i], sub(cnt[i], 1)));
        }
        cout << add(ans, 1) << endl;
        return 0;
    }
    int now = 0, ans = 0;
    for (int i = 0; i < k; i++){
        ind[now] = i;
        now = (now + pr.back()) % k;
    }
    for (int i = n - 1; i >= 0; i--){
        inc(ind[pr[i + 1]], 1);
        int now = mul(get(k - 1), m / k);
        int r = ind[pr[i]], l = r - m % k + 1;
        if (l < 0){
            now = add(now, sub(get(k - 1), get(k + l - 1)));
            now = add(now, get(r));
        }
        else{
            now = add(now, sub(get(r), get(l - 1)));
        }
        ans = add(ans, mul(now, m));
    }
    for (int i = 0; i < N; i++) t[i] = 0;
    for (int i = 1; i < n; i++){
        inc(ind[pr[i]], 1);
        int now = mul(get(k - 1), m / k);
        int r = ind[(pr[i] - pr.back() + k) % k], l = r - m % k + 1;
        if (l < 0){
            now = add(now, sub(get(k - 1), get(k + l - 1)));
            now = add(now, get(r));
        }
        else{
            now = add(now, sub(get(r), get(l - 1)));
        }
        ans = add(ans, mul(now, m));
    }
    if (pr.back() * m % k == 0){
        ans = sub(ans, mul(n, m) - 1);
    }
    cout << ans << endl;
    return 0;
}