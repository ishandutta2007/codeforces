#include<vector>
#include<map>
#include<algorithm>
#include<set>
#include<iostream>
#include<string>
#include<set>
#include<queue>

using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")

#define pb push_back
#define int long long
#define ld long double

const int N = 5e5 + 10;
vector<pair<int,int>> t(4 * N);
vector<int> add(4 * N);

void push(int v){
    t[v].first += add[v];
    if (v * 2 < 4 * N){
        add[v * 2] += add[v];
        add[v * 2 + 1] += add[v];
    }
    add[v] = 0;
}

pair<int,int> func(pair<int,int> a, pair<int,int> b){
    if (a.first != b.first) return min(a, b);
    else {
        return {a.first, a.second + b.second};
    }
}

void build(int v, int l, int r){
    if (l == r){
        t[v] = {0, 1};
        return ;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m), build(2 * v + 1, m + 1, r);
    t[v] = func(t[v * 2], t[v * 2 + 1]);
}

void update (int v, int tl, int tr, int l, int r, int addd) {
    push(v);
	if (l > r)
		return;
    push(v);
	if (l == tl && tr == r){
		add[v] += addd;
        push(v);
    }
	else {
	    push(v);
		int tm = (tl + tr) / 2;
		update (v*2, tl, tm, l, min(r,tm), addd);
		update (v*2+1, tm+1, tr, max(l,tm+1), r, addd);
		t[v] = func(t[v * 2 + 1], t[v * 2]);
	}
}

int get(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r) return 0;
    if (tl == l && tr == r){
        push(v);
        if (t[v].first == 0) return t[v].second;
        else return 0;
    }
    int tm = (tl + tr) / 2;
    push(v);
    return (get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n);
    vector<vector<int>> pos(n + 1, vector<int>(1, -1));
    int ans = 0;

    for (int i = 0; i < n; i++){
        int s = pos[a[i]].size();
        if (s == 1){
            update(1, 0, n, pos[a[i]][s - 1] + 1, i + 1, 1);
        }
        if (s == 2){
            update(1, 0, n, pos[a[i]][s - 1] + 2, i + 1, 1);
        }
        if (s >= 3){
            update(1, 0, n, 0, pos[a[i]][s - 3] + 1, 1e9);
            update(1, 0, n, pos[a[i]][s - 1] + 2, i + 1, 1);
            update(1, 0, n, pos[a[i]][s - 3] + 2, pos[a[i]][s - 2] + 1, -1);
        }
        pos[a[i]].pb(i);
        if (get(1, 0, n, 1, n) != 0){
            ans += get(1, 0, n, 1, n) - (n - i - 1);
        }
        //cout << endl << endl << ans << endl << endl;
    }
    cout << ans << endl;
    return 0;
}