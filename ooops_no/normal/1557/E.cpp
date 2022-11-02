#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

vector<pair<int,int>> d;

bool ok(pair<int,int> a, pair<int,int> b){
    if (a.first == b.first) return 1;
    if (a.second == b.second) return 1;
    if (abs(a.first - b.first) == abs(a.second - b.second)) return 1;
    return 0;
}

bool check(int i, int j){
    return i >= 1 && i <= 8 && j >= 1 && j <= 8;
}

vector<pair<int,int>> clear(vector<pair<int,int>> a, pair<int,int> p){
    vector<pair<int,int>> b;
    for (auto to : a){
        if (!ok(to, p) && check(to.first, to.second)) b.pb(to);
    }
    return b;
}

int read(){
    string s;
    cin >> s;
    if (s == "Up-Left") return 0;
    if (s == "Up") return 1;
    if (s == "Up-Right") return 2;
    if (s == "Left") return 3;
    if (s == "Right") return 4;
    if (s == "Down-Left") return 5;
    if (s == "Down") return 6;
    if (s == "Down-Right") return 7;
    return -1;
}

void solve(){
    int n = 4, m = 4;
    vector<pair<int,int>> all, all_begin;
    for (int i = 1; i <= 8; i++){
        for (int j = 1; j <= 8; j++){
            all.pb({i, j});
            all_begin.pb({i, j});
        }
    }
    cout << n << ' ' << m << endl;
    int cnt = 0;
    while(1){
        int f = read();
        if (f == -1) return;
        for (int i = 0; i < all.size(); i++){
            all[i].first += d[f].first;
            all[i].second += d[f].second;
        }
        all = clear(all, {n, m});
        int now = 1e18;
        if (all.size() < 2) break;
        pair<int,int> p = {-1, -1};
        shuffle(all_begin.begin(), all_begin.end(), rnd);
        for (auto [i, j] : all_begin){
            if (!ok({i, j}, {n, m})) continue;
            if (i == n && j == m) continue;
            vector<int> sum(8);
            for (auto to : all){
                for (int k = 0; k < d.size(); k++){
                    if (check(to.first + d[k].first, to.second + d[k].second) && !ok({to.first + d[k].first, to.second + d[k].second}, {i, j})){
                        sum[k]++;
                    }
                }
            }
            if (*max_element(sum.begin(), sum.end()) < now){
                now = *max_element(sum.begin(), sum.end());
                p = {i, j};
            }
        }
        n = p.first, m = p.second;
        cout << n << ' ' << m << endl;
    }
    int i = all[0].first, j = all[0].second;
    if (n != 1){
        cout << 1 << ' ' << m << endl;
        n = 1;
        int f = read();
        if (f == -1) return;
        i += d[f].first;
        j += d[f].second;
    }
    if (m != 1){
        cout << n << ' ' << 1 << endl;
        m = 1;
        int f = read();
        if (f == -1) return;
        i += d[f].first;
        j += d[f].second;
    }
    while(1){
        if (i > n + 1){
            cout << n + 1 << ' ' << m << endl;
            n++;;
            int f = read();
            if (f == -1) return;
            i += d[f].first;
            j += d[f].second;
            continue;
        }
        if (j > m + 1){
            cout << n << ' ' << m + 1 << endl;
            m++;
            int f = read();
            if (f == -1) return ;
            i += d[f].first;
            j += d[f].second;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = -1; i <= 1; i++){
        for (int j = -1; j <= 1; j++){
            if (i == 0 && j == 0) continue;
            d.pb({i, j});
        }
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}