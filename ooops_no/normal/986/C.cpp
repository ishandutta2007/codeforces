#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = (1 << 23) + 10;
int par[N], sum[N];

int find_set(int v){
    return par[v] == v ? v : par[v] = find_set(par[v]);
}

bool union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a == b) return 0;
    if (sum[a] < sum[b]){
        swap(a, b);
    }
    sum[a] += sum[b];
    par[b] = a;
    return 1;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++){
        par[i] = i;
        sum[i] = 1;
    }
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    vector<int> mx(1 << n, 2e9), ok(1 << n), valid(1 << n, 2e9);
    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++){
        int rev = (1 << n) - 1 - a[i];
        mx[rev] = a[i];
        valid[a[i]] = a[i];
        ok[a[i]] = 1;
    }
    for (int i = (1 << n) - 1; i >= 0; i--){
        for (int j = 0; j < n; j++){
            if (!(i & (1 << j))){
                mx[i] = min(mx[i], mx[i + (1 << j)]);
                valid[i] = min(valid[i], valid[i + (1 << j)]);
            }
        }
    }
    for (int i = 0; i < (1 << n); i++){
        if (mx[i] != 2e9 && ok[i]) {
            union_set(i, mx[i]);
        }
    }
    for (int i = 0; i < (1 << n); i++){
        for (int j = 0; j < n; j++){
            if (!(i & (1 << j)) && mx[i] != 2e9 && mx[i + (1 << j)] != 2e9){
                if (sum[find_set(i)] == 1) continue;
                union_set(i, i + (1 << j));
            }
        }
    }
    set<int> st;
    for (auto to : a) st.insert(find_set(to));
    cout << st.size() << endl;
    return 0;
}