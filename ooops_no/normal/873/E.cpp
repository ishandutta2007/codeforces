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

const int N = 3010;
pair<int,int> t[4 * N];

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        t[v] = {val, pos};
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m){
        update(2 * v, l, m, pos, val);
    }
    else{
        update(2 * v + 1, m + 1, r, pos, val);
    }
    t[v] = max(t[v * 2], t[v * 2 + 1]);
}

pair<int,int> get(int v, int tl, int tr, int l, int r){
    if (l > r) return {-1e18, -1e18};
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; i++){
        cin >> v[i].first;
        v[i].second = i;
	}
	sort(v.begin(), v.end());
	update(1, 0, n - 1, 0, v[0].first);
	for (int i = 1; i < n; i++){
        update(1, 0, n - 1, i, v[i].first - v[i - 1].first);
	}
	int ans[3];
	ans[0] = ans[1] = ans[2] = -1e18;
	pair<int,int>p;
	for (int i = 1; i < n; i++){
        for (int j = 1; j < n; j++){
            if (max(i, j) <= min(i, j) * 2 && i + j < n){
                int mx = v[n - i].first - v[n - i - 1].first, mx1 = v[n - i - j].first - v[n - i - j - 1].first;
                int mn = (max(i, j) + 1) / 2;
                int mnn = min(i, j) * 2;
                int ind = n - i - j;
                if (ind - mn < 0) continue;
                int lol = get(1, 0, n - 1, max(0ll, ind - mnn), ind - mn).first;
                if (ans[0] < mx){
                    ans[0] = mx, ans[1] = mx1, ans[2] = lol;
                    p.first = i, p.second = j;
                }
                else if (ans[0] == mx){
                    if (ans[1] < mx1){
                        ans[0] = mx, ans[1] = mx1, ans[2] = lol;
                        p.first = i, p.second = j;
                    }
                    else if (ans[1] == mx1){
                        if (ans[2] < lol){
                            ans[0] = mx, ans[1] = mx1, ans[2] = lol;
                            p.first = i, p.second = j;
                        }
                    }
                }
            }
        }
	}
	vector<int> kek(n, -1);
	int now = n - 1;
	for (int i = 0; i < p.first; i++){
        kek[v[now].second] = 1;
        now--;
	}
	for (int i = 0; i < p.second; i++){
        kek[v[now].second]= 2;
        now--;
	}
	int i = p.first, j = p.second;
	int ind = n - i - j;
	int mn = (max(i, j) + 1) / 2;
    int mnn = min(i, j) * 2;
    pair<int,int> lol = get(1, 0, n - 1, max(0ll, ind - mnn), ind - mn);
    for (int j = lol.second; j < n; j++){
        if (kek[v[j].second] == -1){
            kek[v[j].second] = 3;
        }
        else{
            break;
        }
    }
    for (int i = 0; i < n; i++){
        cout << kek[i] << " ";

    }
	return 0;
}