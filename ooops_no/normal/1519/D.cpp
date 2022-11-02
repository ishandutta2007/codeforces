#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n), pr(n), sf(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    for (int i = 0; i < n; i++){
        pr[i] = a[i] * b[i];
        if (i > 0) pr[i] += pr[i - 1];
    }
    for (int i = n - 1; i >= 0; i--){
        sf[i] = a[i] * b[i];
        if (i + 1 < n) sf[i] += sf[i + 1];
    }
    int ans = pr[n - 1];
    for (int i = 0; i < n; i++){
        int now = 1, sum_now = a[i] * b[i];
        while(i - now >= 0 && i + now < n){
            sum_now += a[i - now] * b[i + now] + a[i + now] * b[i - now];
            int need = sum_now;
            if (i - now > 0) need += pr[i - now - 1];
            if (i + now + 1 < n) need += sf[i + now + 1];
            ans = max(ans, need);
            now++;
        }
        if (i + 1 < n){
            int now = 0, sum_now = 0;
            while(i - now >= 0 && i + now + 1 < n){
                sum_now += a[i - now] * b[i + now + 1] + a[i + now + 1] * b[i - now];
                int need = sum_now;
                if (i - now > 0) need += pr[i - now - 1];
                if (i + now + 2 < n) need += sf[i + now + 2];
                ans = max(ans, need);
                now++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}