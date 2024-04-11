#include <bits/stdc++.h>

using namespace std;

struct Line
{
    int x1, x2, y1, y2;
    bool horz;
    bool operator<(const Line &otherLine) const
    {
        if (y2 == otherLine.y2)
        {
            if (horz)
            {
                return true;
            }
            return false;
        }
        return y2 < otherLine.y2;
    }
};

const int MAXN = 5000;
const int MAXX = 10001;
vector<Line> h;
vector<Line> v;
vector<Line> lines;
int bit[MAXX + 1];

int query(int i)
{
    int ans = 0;
    while (i > 0)
    {
        ans += bit[i];
        i -= (-i & i);
    }
    return ans;
}

void add(int i, int amt)
{
    while (i <= MAXX)
    {
        bit[i] += amt;
        i += (-i & i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Line l;
        cin >> l.x1 >> l.y1 >> l.x2 >> l.y2;
        l.x1 += 5001;
        l.x2 += 5001;
        l.horz = (l.x1 != l.x2);
        if (l.x1 > l.x2)
            swap(l.x1, l.x2);
        if (l.y1 > l.y2)
            swap(l.y1, l.y2);
        lines.push_back(l);
    }
    sort(lines.begin(), lines.end());
    long long ans = 0;
    for (int i = 0; i < (int) lines.size(); i++)
    {
        if (!lines[i].horz)
            continue;
        int curY = lines[i].y1;
        int left = lines[i].x1;
        int right = lines[i].x2;
        for (int j = i + 1; j < (int) lines.size(); j++)
        {
            if (!lines[j].horz && lines[j].x1 >= left && lines[j].x1 <= right && lines[j].y1 <= curY)
            {
                add(lines[j].x1, 1);
            }
        }
        for (int j = i + 1; j < (int) lines.size(); j++)
        {
            if (lines[j].horz)
            {
                int segs = query(lines[j].x2) - query(lines[j].x1 - 1);
                ans += (long long) segs * (segs - 1) / 2;
            }
            else if (lines[j].x1 >= left && lines[j].x1 <= right && lines[j].y1 <= curY)
            {
                add(lines[j].x1, -1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}