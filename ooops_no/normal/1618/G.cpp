#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 5e5 + 10;
int ans = 0;
vector<int> par(N);
vector<int> cnt(N);
vector<int> sum(N);
vector<int> mx(N);
vector<int> mn(N);
vector<int> pr(N);

int find_set(int v){
    if (v == par[v]) return v;
    else return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    ans -= sum[a];
    ans -= sum[b];
    mn[a] = min(mn[a], mn[b]);
    mx[a] = max(mx[a], mx[b]);
    cnt[a] += cnt[b];
    sum[a] = pr[mx[a]] - (mx[a] - cnt[a] >= 0 ? pr[mx[a] - cnt[a]] : 0);
    ans += sum[a];
    par[b] = a;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> a(n), b(m);
    vector<pair<int,int>> u, uu(q), e;
    vector<int> anss(q);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        u.pb({a[i], 1});
    }
    for (int i = 0; i < m; i++){
        cin >> b[i];
        u.pb({b[i], 0});
    }
    sort(u.begin(), u.end());
    for (int i = 0; i + 1 < u.size(); i++){
        e.pb({u[i + 1].first - u[i].first, i});
    }
    for (int i = 0; i < u.size(); i++){
        par[i] = i;
        cnt[i] = u[i].second;
        sum[i] = u[i].second * u[i].first;
        ans += sum[i];
        mn[i] = mx[i] = i;
        pr[i] = (i > 0 ? pr[i - 1] : 0) + u[i].first;
    }
    sort(e.begin(), e.end());
    for (int i = 0; i < q; i++){
        cin >> uu[i].first;
        uu[i].second = i;
    }
    sort(uu.begin(), uu.end());
    int i = 0;
    for (auto to : uu){
        while(i < e.size() && e[i].first <= to.first){
            union_set(e[i].second, e[i].second + 1);
            i++;
        }
        anss[to.second] = ans;
    }
    for (auto to : anss){
        cout << to << endl;
    }
    return 0;
}