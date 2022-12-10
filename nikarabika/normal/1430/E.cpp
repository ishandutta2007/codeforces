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

const int maxn = 200 * 1000 + 10;
int fen[maxn];

void add(int idx) {
    for (idx++; idx < maxn; idx += idx & -idx)
        fen[idx]++;
}

int get(int idx) {
    int ans = 0;
    for (; idx; idx -= idx & -idx)
        ans += fen[idx];
    return ans;
}

int get(int l, int r) {
    return get(r) - get(l);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    char s[n];
    cin >> s;
    vector<int> vec[26];
    for (int i = 0; i < n; i++)
        vec[s[i] - 'a'].push_back(i);
    reverse(s, s + n);
    int cnt[26] = {0};
    int perm[n];
    for (int i = 0; i < n; i++) {
        perm[i] = vec[s[i] - 'a'][cnt[s[i] - 'a']];
        cnt[s[i] - 'a']++;
    }
    LL ans = 0;
    for (int i = 0; i < n; i++) {
        ans += get(perm[i], n);
        add(perm[i]);
    }
    cout << ans << endl;
	return 0;
}