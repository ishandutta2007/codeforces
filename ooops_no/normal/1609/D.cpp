#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
vector<int> par(N);
vector<int> sum(N, 1);
multiset<int> st;

int find_set(int v){
    if (v == par[v]) return v;
    else return par[v] = find_set(par[v]);
}

bool union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    if (a == b) return 0;
    if (sum[a] < sum[b]){
        swap(a, b);
    }
    par[b] = a;
    st.erase(st.find(sum[a] - 1));
    st.erase(st.find(sum[b] - 1));
    sum[a] += sum[b];
    st.insert(sum[a] - 1);
    return 1;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par.begin(), par.end(), 0);
    int n, d;
    cin >> n >> d;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }
    for (int i = 0; i < n; i++) st.insert(0);
    int cnt = 1;
    for (int i = 0; i < d; i++){
        bool f = union_set(x[i], y[i]);
        if (!f){
            cnt++;
        }
        vector<int> arr;
        for (auto to : st){
            arr.pb(to);
        }
        sort(arr.rbegin(), arr.rend());
        int ans = 0;
        for (int j = 0; j < min(cnt, (int)arr.size()); j++){
            ans += arr[j];
            if (j > 0) ans++;
        }
        cout << min(i + 1, ans) << endl;
    }
    return 0;
}