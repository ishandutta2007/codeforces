#define FILES freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FIXED cout << fixed << setprecision(20)
#define pb push_back
#define mp make_pair
#define hashmap unordered_map
#define hashset unordered_set
#define eps 1e-9
#define mod 1000000007
#define inf 1000000000000000007ll

#include <bits/stdc++.h>

using namespace std;
typedef unsigned int ui;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<vector<int>> graph;

vector<string> arr[4];
int n;

int solve(vector<int> nums) {
    vector<bool> used(4, false);
    used[nums[0]] = true;
    used[nums[1]] = true;
    used[nums[2]] = true;
    used[nums[3]] = true;
    for (auto i : used)
        if (!i) return mod;
    int ans = 0;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if (arr[i][j][k] != (int)(1 - (nums[i] + j + k) % 2)) ++ans;
    return ans;
}

int main() {
    cin >> n;
    for (int i = 0; i < 4; ++i) arr[i] = vector<string> (n);
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            for (auto &k : arr[i][j]) k -= '0';
        }
    int ans = mod;
    for (int a = 0; a < 4; ++a)
        for (int b = 0; b < 4; ++b)
            for (int c = 0; c < 4; ++c)
                for (int d = 0; d < 4; ++d) {
                    vector<int> nums(4);
                    nums[0] = a;
                    nums[1] = b;
                    nums[2] = c;
                    nums[3] = d;
                    ans = min(ans, solve(nums));
                }
    cout << ans;
    return 0;
}