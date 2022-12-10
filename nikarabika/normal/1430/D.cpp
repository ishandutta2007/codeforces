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

int solve() {
    int n;
    cin >> n;
    char prev = '!';
    int cnt = 0;
    deque<int> deq;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (prev != c and cnt) {
            deq.push_back(cnt);
            cnt = 0;
        }
        cnt++;
        prev = c;
    }
    deq.push_back(cnt);
    int ptr = 0;
    int ans = 0;
    while (sz(deq)) {
        while (ptr < sz(deq) and (ptr == -1 or deq[ptr] == 1))
            ptr++;
        if (ptr < sz(deq))
            deq[ptr]--;
        else
            deq.pop_back();
        
        if (sz(deq))
            deq.pop_front(), ptr--;

        ans++;
    }
    cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
	cin >> q;
	while (q--)
		solve();
	return 0;
}