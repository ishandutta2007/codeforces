#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> point;

const int MAXN = 1000;
const int INF = 2E9 + 5;
point pts[MAXN];
map<int, vector<int>> horz;
map<int, vector<int>> vert;
vector<tuple<int, int, int>> edges;
int p[MAXN];
int s[MAXN];
int dist[MAXN];

int getRoot(int x)
{
    if (p[x] != x)
        p[x] = getRoot(p[x]);
    return p[x];
}

bool mge(int a, int b)
{
    int r1 = getRoot(a);
    int r2 = getRoot(b);
    if (r1 == r2)
        return false;
    if (s[r1] > s[r2])
        swap(r1, r2);
    p[r1] = r2;
    s[r2] += s[r1];
    return true;
}

void addPoint(int ind)
{
    point pt = pts[ind];
    vert[pt.first].push_back(ind);
    horz[pt.second].push_back(ind);
}

int check(int comps)
{
    int ans = INF;
    if (comps == 2)
    {
        for (auto it = horz.begin(); it != horz.end(); it++)
        {
            vector<int> v = it->second;
            for (int i = 1; i < (int) v.size(); i++)
            {
                if (getRoot(v[i]) == getRoot(v[i - 1]))
                    continue;
                int mid = (pts[v[i]].first + pts[v[i - 1]].first) / 2;
                ans = min(ans, max(abs(pts[v[i]].first - mid), abs(pts[v[i - 1]].first - mid)));
            }
        }
        for (auto it = vert.begin(); it != vert.end(); it++)
        {
            vector<int> v = it->second;
            for (int i = 1; i < (int) v.size(); i++)
            {
                if (getRoot(v[i]) == getRoot(v[i - 1]))
                    continue;
                int mid = (pts[v[i]].second + pts[v[i - 1]].second) / 2;
                ans = min(ans, max(abs(pts[v[i]].second - mid), abs(pts[v[i - 1]].second - mid)));
            }
        }
    }
    for (auto it1 = horz.begin(); it1 != horz.end(); it1++)
    {
        for (auto it2 = vert.begin(); it2 != vert.end(); it2++)
        {
            int x = it2->first;
            int y = it1->first;
            for (int i = 0; i < (int) it1->second.size(); i++)
            {
                if (i + 1 < (int) it1->second.size() && pts[it1->second[i + 1]].first <= x)
                    continue;
                if (i - 1 >= 0 && pts[it1->second[i - 1]].first >= x)
                    continue;
                for (int j = 0; j < (int) it2->second.size(); j++)
                {
                    if (j + 1 < (int) it2->second.size() && pts[it2->second[j + 1]].second <= y)
                        continue;
                    if (j - 1 >= 0 && pts[it2->second[j - 1]].second >= y)
                        continue;
                    dist[getRoot(it1->second[i])] = min(dist[getRoot(it1->second[i])], abs(x - pts[it1->second[i]].first));
                    dist[getRoot(it2->second[j])] = min(dist[getRoot(it2->second[j])], abs(y - pts[it2->second[j]].second));
                    int ii = i;
                    int jj = j;
                    if (ii - 1 >= 0 && pts[it1->second[i]].first > x)
                        ii = i - 1;
                    if (ii + 1 < (int) it1->second.size() && pts[it1->second[i]].first < x)
                        ii = i + 1;
                    if (jj - 1 >= 0 && pts[it2->second[j]].second > y)
                        jj = j - 1;
                    if (jj + 1 < (int) it2->second.size() && pts[it2->second[j]].second < y)
                        jj = j + 1;
                    dist[getRoot(it1->second[ii])] = min(dist[getRoot(it1->second[ii])], abs(x - pts[it1->second[ii]].first));
                    dist[getRoot(it2->second[jj])] = min(dist[getRoot(it2->second[jj])], abs(y - pts[it2->second[jj]].second));
                    int r1 = getRoot(it1->second[i]);
                    int r2 = getRoot(it1->second[ii]);
                    int r3 = getRoot(it2->second[j]);
                    int r4 = getRoot(it2->second[jj]);
                    int temp = 1;
                    int len = dist[r1];
                    if (r2 != r1)
                    {
                        temp++;
                        len = max(len, dist[r2]);
                    }
                    if (r3 != r2 && r3 != r1)
                    {
                        temp++;
                        len = max(len, dist[r3]);
                    }
                    if (r4 != r3 && r4 != r2 && r4 != r1)
                    {
                        temp++;
                        len = max(len, dist[r4]);
                    }
                    if (temp == comps)
                        ans = min(ans, len);
                    dist[r1] = INF;
                    dist[r2] = INF;
                    dist[r3] = INF;
                    dist[r4] = INF;
                }
            }
        }
    }
    if (ans == INF)
        ans = -1;
    return ans;
}

bool cmpx(int a, int b)
{
    return pts[a].first < pts[b].first;
}

bool cmpy(int a, int b)
{
    return pts[a].second < pts[b].second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    fill(dist, dist + n, INF);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        pts[i] = point(x, y);
        addPoint(i);
        p[i] = i;
        s[i] = 1;
    }
    for (auto &it : horz)
        sort(it.second.begin(), it.second.end(), cmpx);
    for (auto &it : vert)
        sort(it.second.begin(), it.second.end(), cmpy);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (pts[i].first == pts[j].first)
                edges.push_back(make_tuple(abs(pts[i].second - pts[j].second), i, j));
            else if (pts[i].second == pts[j].second)
                edges.push_back(make_tuple(abs(pts[i].first - pts[j].first), i, j));
        }
    }
    sort(edges.begin(), edges.end());
    int ans = INF;
    int ptr = 0;
    int comps = n;
    if (comps <= 4)
    {
        int temp = check(comps);
        if (temp != -1)
        {
            ans = temp;
        }
    }
    while (ptr < (int) edges.size())
    {
        int len = get<0>(edges[ptr]);
        bool reduced = false;
        while (ptr < (int) edges.size() && get<0>(edges[ptr]) == len)
        {
            if (mge(get<1>(edges[ptr]), get<2>(edges[ptr])))
            {
                reduced = true;
                comps--;
            }
            ptr++;
        }
        if (reduced)
        {
            if (comps == 1)
                ans = min(ans, len);
            else if (comps <= 4)
            {
                int otherLen = check(comps);
                if (otherLen != -1)
                {
                    ans = min(ans, max(len, otherLen));
                }
            }
        }
    }
    if (ans == INF)
        ans = -1;
    cout << ans << "\n";
    return 0;
}