#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e9 + 7;

void run() {
    int l1, l2, l3;
    cin >> l1 >> l2 >> l3;
    if (l2 > l1) swap(l1, l2);
    if (l3 > l1) swap(l1, l3);
    if (l3 > l2) swap(l3, l2);
    if (l1 == l2 + l3 || (l2 == l3 && l1 % 2 == 0) || (l1 == l2 && l3 % 2 == 0)) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(5);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}