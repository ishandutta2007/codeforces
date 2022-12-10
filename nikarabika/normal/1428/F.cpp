//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 5e5 + 10;
vector<pll> st;
LL n;
LL curans;
LL maxseg;

LL seglen(pii seg) {
    return seg.R - seg.L;
}

void pop();

void push(pll seg) {
    LL len = seglen(seg);
    while (sz(st) and len >= seglen(st.back()))
        pop();
    if (sz(st) == 0) {
        maxseg = len;
        curans = (n - seg.R) * len;
    }
    else {
        maxseg = seglen(st.front());
        pll nxt = st.back();
        curans += (nxt.L + len - seg.R) * len;
    }
    st.push_back(seg);
}

void pop() {
    if (sz(st) == 0)
        return;
    if (sz(st) == 1) {
        st.pop_back();
        curans = 0;
    }
    else {
        pll seg = st.back();
        st.pop_back();
        pll nxt = st.back();
        curans -= (nxt.L + seglen(seg) - seg.R) * seglen(seg);
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    string s;
    cin >> n
        >> s;
    st.reserve(n);
    int cnt = 0;
    LL ans = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') {
            cnt = 0;
        }
        else {
            if (cnt) pop();
            cnt++;
            push(MP(i, i + cnt));
        }
        ans += curans + maxseg * (maxseg + 1) / 2LL;
    }
    cout << ans << '\n';
	return 0;
}