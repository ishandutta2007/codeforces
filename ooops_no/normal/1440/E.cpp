#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb emplace_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 2e5 + 100;
ll t[4 * N], add[4 * N];
int a[N], col[4 * N];
int n, q;

void push(int v){
    if (add[v] != 0){
        t[v] = add[v] * col[v];
        if (v * 2 < 4 * N){
            add[v * 2] = add[v];
            add[v * 2 + 1] = add[v];
        }
        add[v] = 0;
    }
}

void build(int v, int l, int r){
    col[v] = r - l + 1;
    if (l == r){
        t[v] = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m), build(2 * v + 1, m + 1, r);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

ll get(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r) return 0;
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

void update(int v, int tl, int tr, int l, int r, ll val){
    push(v);
    if (l > r) return;
    if (tl == l && tr == r){
        add[v] = val;
        push(v);
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

int go(int v, int l, int r, ll val){
    if (l == r){
        return r - 1;
    }
    push(v * 2);
    int m = (l + r) / 2;
    if (t[v * 2] > val){
        return go(2 * v, l, m, val);
    }
    else{
        push(v * 2 + 1);
        return go(2 * v + 1, m + 1, r, val - t[v * 2]);
    }
}

int solve(int i, ll val){
    if (get(1, 0, n - 1, i, n - 1) <= val) return n - 1;
    val += get(1, 0, n - 1, 0, i - 1);
    push(1);
    return go(1, 0, n - 1, val);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    set<pair<pair<int,int>, int>> st;
    set<pair<int,int>> stt;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        st.insert({{i, i}, a[i]});
        stt.insert({a[i], -i});
    }
    build(1, 0, n - 1);
    while(q--){
        int t, x, y;
        cin >> t >> x >> y;
        x--;
        if (t == 1){
            auto it = st.upper_bound({{x, n + 1}, n + 1});
            it--;
            int l = (*it).first.first, r = (*it).first.second, val = (*it).second;
            if (r != x){
                st.erase({{l, r}, val});
                stt.erase({val, -l});
                st.insert({{l, x}, val});
                stt.insert({val, -l});
                st.insert({{x + 1, r}, val});
                stt.insert({val, -(x + 1)});
            }
            int left = -1;
            while(1){
                auto it = st.upper_bound({{x, n + 1}, n + 1});
                it--;
                int l = (*it).first.first, r = (*it).first.second, val = (*it).second;
                if (val > y){
                    break;
                }
                left = l;
                st.erase({{l, r}, val});
                stt.erase({val, -l});
                if (l == 0) break;
            }
            if (left == -1){
                continue;
            }
            st.insert({{left, x}, y});
            update(1, 0, n - 1, left, x, y);
            stt.insert({y, -left});
        }
        else{
            int cnt = 0, i = x;
            if (y - get(1, 0, n - 1, i, i) < 0){
                auto it = stt.upper_bound({y, n + 1});
                if (it != stt.begin()){
                    it--;
                    i = abs(it->second);
                }
                else i = n;
            }
            while (i < n){
                int v = solve(i, y);
                cnt += v - i + 1;
                y -= get(1, 0, n - 1, i, v);
                if (v == n - 1) break;
                auto it = stt.upper_bound({y, n + 1});
                if (it != stt.begin()){
                    it--;
                    i = abs(it->second);
                }
                else i = n;

            }
            cout << cnt << '\n';
        }
    }
    return 0;
}