#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define sz(x) (int) x.size()
#define INF (int) 1e9
#define LINF (ll) 1e18
#define EPS 1e-8
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)

int n, k;
vector<int> nums;
ll d[5100][5100];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> k;
    nums.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    int big = n % k;
    int small = k - big;
    int big_len = n / k + 1;
    int small_len = n / k;

    for (int i = 0; i <= big; i++) {
        for (int j = 0; j <= small; j++) {
            d[i][j] = LINF;
        }
    }

    d[0][0] = 0;

    for (int i = 0; i <= big; i++) {
        for (int j = 0; j <= small; j++) {
            int taken = i * big_len + j * small_len;

            if (i < big) {
                int m = taken + big_len - 1;
                ll add = nums[m] - nums[taken];
                d[i + 1][j] = min(d[i + 1][j], d[i][j] + add);
            }

            if (j < small) {
                int m = taken + small_len - 1;
                ll add = nums[m] - nums[taken];
                d[i][j + 1] = min(d[i][j + 1], d[i][j] + add);
            }
        }
    }

    cout << d[big][small] << "\n";

    return 0;
}