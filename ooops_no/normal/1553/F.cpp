#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 6e5 + 10;
int t[N], sum[N];

pair<int,int> get(int r){
    int ans = 0, anss = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1){
        ans += t[r];
        anss += sum[r];
    }
    return {ans, anss};
}

void inc(int i, int d){
    for (; i < N; i = (i | (i + 1))){
        t[i] += 1;
        sum[i] += d;
    }
}

vector<int> solve(int n, vector<int> a){
    for (int i = 0; i < N; i++) {
        t[i] = 0;
        sum[i] = 0;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; i++){
        ans[i] += get(a[i] - 1).second;
        ans[i] += get(a[i] - 1).first * a[i];
        ans[i] += a[i] * (get(N - 1).first - get(a[i]).first);
        int now = a[i];
        while(now + a[i] < N){
            ans[i] += (get(now + a[i] - 1).second - get(now - 1).second) - (now * (get(now + a[i] - 1).first - get(now - 1).first));
            now += a[i];
        }
        inc(a[i], a[i]);
    }
    for (int i = 0; i < N; i++){
        t[i] = 0;
        sum[i] = 0;
    }
    for (int i = 0; i < n; i++){
        ans[i] -= get(a[i]).second;
        int now = a[i];
        while(now + a[i] < N){
            inc(now, now);
            inc(now + a[i], -now);
            now += a[i];
        }
    }
    for (int i = 0; i < n; i++){
        if (i > 0) ans[i] += ans[i - 1];
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    for (auto to : solve(n, a)){
        cout << to << endl;
    }
    return 0;
}