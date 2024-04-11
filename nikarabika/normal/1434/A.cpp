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

const int maxn = 100 * 1000 + 100;
int a[maxn],
    b[maxn],
    ptr[maxn],
    n;
set<pii> s;
vector<int> vec[maxn];

int solve() {
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    sort(a, a + 6);
    cin >> n;
    for (int j = 0; j < n; j++) {
        cin >> b[j];
        for (int i = 5; i >= 0; i--) {
            vec[j].PB(b[j] - a[i]);
        }
    }
    for (int i = 0; i < n; i++)
        s.insert(MP(vec[i][0], i));
    int ans = 1000 * 1000 * 1000;
    while (true) {
        smin(ans, s.rbegin()->L - s.begin()->L);
        int id = s.begin()->R;
        s.erase(s.begin());
        ptr[id]++;
        if (ptr[id] == 6)
            break;
        s.insert(MP(vec[id][ptr[id]], id));
    }
    cout << ans << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int q;
    q = 1;
	while (q--)
		solve();
	return 0;
}