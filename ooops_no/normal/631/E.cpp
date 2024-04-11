#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

struct line{
    int a, b;
};

ld inter(line a, line b){
    return (ld)(a.b - b.b) / (b.a - a.a);
}

vector<line> all;

bool bad(line a){
    return all.size() >= 2 && (inter(a, all.back()) < inter(all.back(), all[(int)(all.size()) - 2]));
}

void add(line a){
    while(bad(a)){
        all.pop_back();
    }
    all.pb(a);
}

int get(int x){
    int l = 0, r = all.size();
    while(r - l > 1){
        int mid = (r + l) / 2;
        if (inter(all[mid], all[mid - 1]) <= x) l = mid;
        else r = mid;
    }
    return all[l].a * x + all[l].b;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ans = 0, val = 0;
    cin >> n;
    vector<int> a(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        sum[i] = a[i] + sum[i - 1];
        ans += a[i] * i;
    }
    for (int r = 2; r <= n; r++){
        add({r - 1, -sum[r - 2]});
        val = max(val, get(a[r]) + sum[r - 1] - a[r] * r);
    }
    all.clear();
    for (int l = n - 1; l >= 1; l--){
        add({-(l + 1), -sum[l + 1]});
        val = max(val, get(-a[l]) + sum[l] - a[l] * l);
    }
    cout << ans + val << endl;
    return 0;
}