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
#define ld long double
#define vi vector<int>
mt19937 Rand(time(0));

int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }

const int inf = 1e9 + 7;
int n, q;
string s;
int cnt = 0;

bool f(int id) {
    return id + 2 < n && id >= 0 && s[id] == 'a' && s[id + 1] == 'b' && s[id + 2] == 'c';
}

int g(int id) {
    int res = 0;
    for (int i = id - 2; i <= id; ++i)
        res += f(i);
    return res;
}

void run() {
    cin >> n >> q >> s;
    for (int i = 0; i < n; ++i)
        cnt += f(i);
    while (q--) {
        int pos;
        string t;
        cin >> pos >> t; --pos;
        cnt -= g(pos);
        s[pos] = t[0];
        cnt += g(pos);
        cout << cnt << endl;
    }
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        run();
    }
}