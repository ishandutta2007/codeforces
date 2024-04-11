#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<map>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int MOD = 998244353, N = 5e5 + 10;
int t[N];

int add(int a, int b){
    a += b;
    if (a >= MOD) a -= MOD;
    return a;
}

struct p{
    int x, y, s;
};

bool cmp(p a, p b){
    return a.x < b.x;
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
    int n;
    cin >> n;
    vector<p> v(n);
    vector<int> ans(n);
    vector<int> u;
    for (int i = 0; i < n; i++){
        cin >> v[i].x >> v[i].y >> v[i].s;
        u.pb(v[i].x);
        u.pb(v[i].y);
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < n; i++){
        ans[i] = (v[i].x - v[i].y);
        ans[i] = add(ans[i], (get(N - 1) - get(lower_bound(u.begin(), u.end(), v[i].y) - u.begin() - 1)) % MOD);
        inc(lower_bound(u.begin(), u.end(), v[i].x) - u.begin(), ans[i]);
    }
    int anss = 0;
    for (int i = 0; i < n; i++){
        if (v[i].s){
            anss = add(anss, ans[i]);
        }
    }
    cout << add(anss, v.back().x + 1) << endl;
    return 0;
}