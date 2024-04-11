#include <bits/stdc++.h>

using namespace std;

const int INF = 1E9;
const int MAXN = 4E5;
pair<int, int> a[MAXN];
map<int, int> mp;
int segPref[2 * MAXN];
int segSuf[2 * MAXN];
int segMid[2 * MAXN];

int query(int l, int r, int seg[2 * MAXN], bool mx)
{
    l += MAXN;
    r += MAXN;
    int ans = mx ? 0 : INF;
    while (l <= r)
    {
        if (l & 1)
            ans = mx ? max(ans, seg[l++]) : min(ans, seg[l++]);
        if (!(r & 1))
            ans = mx ? max(ans, seg[r--]) : min(ans, seg[r--]);
        l >>= 1;
        r >>= 1;
    }
    return ans;
}

void upd(int pos, int x, int seg[2 * MAXN], bool mx)
{
    pos += MAXN;
    seg[pos] = mx ? max(seg[pos], x) : min(seg[pos], x);
    pos >>= 1;
    while (pos)
    {
        seg[pos] = mx ? max(seg[pos * 2], seg[pos * 2 + 1]) : min(seg[pos * 2], seg[pos * 2 + 1]);
        pos >>= 1;
    }
}

int encode(int x)
{
    return mp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill(segSuf, segSuf + 2 * MAXN, INF);
    int n;
    cin >> n;
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        nums.push_back(a[i].first);
    }
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].second;
        nums.push_back(a[i].second);
        ans += abs(a[i].first - a[i].second);
    }
    sort(nums.begin(), nums.end());
    nums.resize(distance(nums.begin(), unique(nums.begin(), nums.end())));
    for (int i = 0; i < (int) nums.size(); i++)
    {
        mp[nums[i]] = i;
    }
    vector<pair<int, int>> intervals;
    vector<pair<int, int>> lines;
    for (int i = 0; i < n; i++)
    {
        int diff = a[i].second - a[i].first;
        if (diff > 0)
        {
            upd(encode(a[i].first), a[i].second, segPref, true);
            upd(encode(a[i].second), a[i].first, segSuf, false);
            lines.push_back({a[i].first, a[i].second});
        }
        else if (diff < 0)
        {
            intervals.push_back({a[i].second, a[i].first});
        }
    }
    sort(intervals.rbegin(), intervals.rend());
    sort(lines.begin(), lines.end());
    int best = 0;
    for (pair<int, int> pr : intervals)
    {
        while (lines.size() && lines.back().first >= pr.first)
        {
            pair<int, int> line = lines.back();
            upd(encode(line.second), line.second - line.first, segMid, true);
            lines.pop_back();
        }
        int len = pr.second - pr.first;
        int pos = query(0, encode(pr.first), segPref, true);
        best = max(best, min(pos - pr.first, len));
        pos = query(encode(pr.second), MAXN - 1, segSuf, false);
        best = max(best, min(pr.second - pos, len));
        best = max(best, query(encode(pr.first), encode(pr.second), segMid, true));
    }
    cout << ans - 2 * best << "\n";
    return 0;
}