#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1E6;
const int MAXA = 1E9;
vector<int> nums;
int perm[MAXN];

int main()
{
    int n;
    int queries = 60;
    cin >> n;
    int mx = 0;
    int lo = 1, hi = MAXA;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        cout << "> " << mid << endl;
        cout.flush();
        int res;
        cin >> res;
        if (res)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid;
        }
        queries--;
    }
    mx = lo;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for (int i = 0; i < n; i++)
        perm[i] = i + 1;
    shuffle(perm, perm + n, rng);
    for (int i = 0; queries > 0 && i < n; i++)
    {
        cout << "? " << perm[i] << endl;
        cout.flush();
        int res;
        cin >> res;
        nums.push_back(res);
        queries--;
    }
    sort(nums.begin(), nums.end());
    int diff = nums[1] - nums[0];
    for (int i = 2; i < nums.size(); i++)
    {
        diff = __gcd(diff, nums[i] - nums[i - 1]);
    }
    cout << "! " << mx - diff * (n - 1) << " " << diff << endl;
    cout.flush();
    return 0;
}