#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db long double
#define pii pair<int, int>
#define mkp make_pair
#define sz(x) ((int) x.size())
#define be(x) x.begin()
#define en(x) x.end()
using namespace std;
const int N = 1e5 + 7;
int n, m, a[N], lastans;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    L(i, 1, n) cin >> a[i];
    cin >> m;
    while(m--) {
        int opt, l, r, k; cin >> opt >> l >> r;
        l = (l + lastans - 1) % n + 1, r = (r + lastans - 1) % n + 1;
        if(l > r) swap(l, r);
        if(opt == 2) {
            cin >> k, k = (k + lastans - 1) % n + 1;
			int sum = 0;
			for(; l <= r; ++ l) sum += a[l] == k;
			cout << (lastans = sum) << endl;
        }
        else {
			int tmp = a[r];
			for(; r > l; --r) a[r] = a[r - 1];
			a[l] = tmp;
		}
    }
    return 0;
}