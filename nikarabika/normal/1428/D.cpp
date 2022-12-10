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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    stack<int> vec[4];
    vector<pii> ans;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i] == 0)
            continue;
        else if (a[i] == 1) {
            ans.PB(MP(i, i));
            vec[1].push(i);
        }
        else if (a[i] == 2) {
            if (sz(vec[1]) == 0)
                return cout << -1 << '\n', 0;
            int ii = vec[1].top();
            vec[1].pop();
            ans.PB(MP(ii, i));
            vec[2].push(i);
        }
        else if (a[i] == 3) {
            int ii;
            if (sz(vec[3])) {
                ii = vec[3].top();
                vec[3].pop();
            }
            else if (sz(vec[2])) {
                ii = vec[2].top();
                vec[2].pop();
            }
            else if (sz(vec[1])) {
                ii = vec[1].top();
                vec[1].pop();
            }
            else
                return cout << -1 << '\n', 0;
            ans.PB(MP(i, i));
            ans.PB(MP(i, ii));
            vec[3].push(i);
        }
    }
    cout << sz(ans) << '\n';
    for (auto pos: ans)
        cout << pos.L + 1 << ' ' << pos.R + 1 << '\n';
	return 0;
}