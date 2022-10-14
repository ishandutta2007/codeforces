#include <bits/stdc++.h>
#define fi first
#define se second
#define db(x) cout << #x << " is " << x << "\n"
#define IOS ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
int segtree[4000005], vec[1000005];
void build(int n, int tl, int tr) {
    if (tl > tr) return;
    if (tl == tr) {
        segtree[n] = vec[tl]; return;
    }
    int mid = (tl + tr) / 2;
    build(n * 2, tl, mid); build(n * 2 + 1, mid + 1, tr);
    segtree[n] = min(segtree[n * 2], segtree[n * 2 + 1]);
}
int query(int n, int tl, int tr, int le, int ri) {
    if (le > ri) return 100;
    if (tl > tr || ri < tl || tr < le) return 100;
    if (le <= tl && tr <= ri) return segtree[n];
    int mid = (tl + tr) / 2;
    return min(query(n * 2, tl, mid, le, ri), query(n * 2 + 1, mid + 1, tr, le, ri));
}
int main() {
    IOS;
    int T; cin >> T; while (T--) {
        int N; cin >> N;
        for (int i = 0; i < N; i++) {
            char a; cin >> a;
            vec[i] = a - '0';
        }
        build(1, 0, N - 1);
        vector<int> check, ans(N, 0);
        int minim = 100;
        for (int i = 0; i < N; i++) {
            if (vec[i] <= query(1, 0, N - 1, i + 1, N - 1) && vec[i] <= minim) {
                ans[i] = 1;
                check.push_back(vec[i]);
            } else {
                minim = min(minim, vec[i]);
            }
        }
        for (int i = 0; i < N; i++) {
            if (ans[i] == 0) {
                ans[i] = 2;
                check.push_back(vec[i]);
            }
        }
        bool s = true;
        for (int i = 1; i < N; i++) {
            if (check[i] >= check[i - 1]) {
                continue;
            } else {
                s = false;
            }
        }
        if (s) {
            for (int i = 0; i < N; i++) {
                cout << ((ans[i] == 1)? 1 : 2);
            }
            cout << "\n";
        } else {
            cout << "-\n";
        }
    }
}