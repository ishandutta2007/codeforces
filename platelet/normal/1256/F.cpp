#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 2e5 + 5;

int n;
char s[N], t[N];
auto calc(char s[]) {
    int re = 0; array<int, 26> su; su.fill(0);
    rep(i, 1, n) {
        rep(j, s[i] - 96, 25) re ^= su[j] & 1;
        su[s[i] - 97]++;
    }
    return pair(re, su);
}

void solve() {
    scanf("%d%s%s", &n, s + 1, t + 1);
    auto [s1, s2] = calc(s);
    auto [t1, t2] = calc(t);
    if(s2 != t2) return void(puts("NO"));
    puts(*max_element(s2.begin(), s2.end()) > 1 || s1 == t1 ? "YES" : "NO");
}

int main() {
    int T;
    for(cin >> T; T--; solve());
}