#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 10;

vector<int> par(N), sum(N, 1);
int ans = 0;

int find_set(int v){
    if (v == par[v]) return v;
    else return par[v] = find_set(par[v]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);
    ans -= sum[a] * (sum[a] - 1) / 2;
    ans -= sum[b] * (sum[b] - 1) / 2;
    if (sum[a] < sum[b]){
        swap(a, b);
    }
    par[b] = a;
    sum[a] += sum[b];
    ans += sum[a] * (sum[a] - 1) / 2;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    iota(par.begin(), par.end(), 0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, pair<int,int>>> u;
    for (int i = 0; i < n - 1; i++){
        int a, b, c;
        cin >> a >> b >> c;
        u.pb({c, {a, b}});
    }
    sort(u.begin(), u.end());
    vector<int> anss(m);
    vector<pair<int,int>> uu(m);
    for (int i = 0; i < m; i++){
        cin >> uu[i].first;
        uu[i].second = i;
    }
    sort(uu.begin(), uu.end());
    int j = 0;
    for (int i = 0; i < uu.size(); i++){
        while(j < u.size() && u[j].first <= uu[i].first){
            union_set(u[j].second.first, u[j].second.second);
            j++;
        }
        anss[uu[i].second] = ans;
    }
    for (auto to : anss){
        cout << to << ' ';
    }
    return 0;
}