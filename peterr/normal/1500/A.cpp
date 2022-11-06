#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200000;
const int MAXM = 2500000;
pair<int, int> a[MAXN + 1];
vector<pair<int, int>> prs[2 * MAXM + 1];
int dx[2] = {0, 1};
int dy[2] = {1, 0};

void printAns(int x, int y, int z, int w)
{
    cout << "YES\n";
    cout << x << " " << y << " " << z << " " << w << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    bool ans = false;
    int ans1 = -1;
    int ans2 = -1;
    int ans3 = -1;
    int ans4 = -1;
    map<int, vector<int>> mp;
    int found = -1;
    for (int i = 1; i <= n; i++)
    {
        mp[a[i].first].push_back(a[i].second);
        if (mp[a[i].first].size() == 4)
        {
            ans = true;
            ans1 = mp[a[i].first][0];
            ans2 = mp[a[i].first][1];
            ans3 = mp[a[i].first][2];
            ans4 = mp[a[i].first][3];
            break;
        }
        else if (mp[a[i].first].size() == 2)
        {
            if (found == -1)
            {
                found = a[i].first;
            }
            else
            {
                ans = true;
                ans1 = mp[a[i].first][0];
                ans2 = mp[found][0];
                ans3 = mp[a[i].first][1];
                ans4 = mp[found][1];
                break;
            }
        }
    }
    if (ans)
    {
        printAns(ans1, ans2, ans3, ans4);
        return 0;
    }
    set<pair<int, int>> visited;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    pq.push({a[1].first + a[2].first, 1, 2});
    prs[a[1].first + a[2].first].push_back({1, 2});
    while (!pq.empty())
    {
        tuple<int, int, int> tup = pq.top();
        pq.pop();
        int x = get<1>(tup);
        int y = get<2>(tup);
        for (int i = 0; i < 2; i++)
        {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (yy > n || xx > n || xx >= yy || visited.count({xx, yy}))
                continue;
            int s = a[xx].first + a[yy].first;
            bool good = false;
            for (pair<int, int> pr : prs[s])
            {
                if (pr.first != xx && pr.first != yy && pr.second != xx && pr.second != yy)
                {
                    ans1 = a[xx].second;
                    ans2 = a[yy].second;
                    ans3 = a[pr.first].second;
                    ans4 = a[pr.second].second;
                    good = true;
                    break;
                }
            }
            if (good)
                break;
            visited.insert({xx, yy});
            pq.push({s, xx, yy});
            prs[s].push_back({xx, yy});
        }
    }
    if (ans1 != -1)
        printAns(ans1, ans2, ans3, ans4);
    else
        cout << "NO\n";
    return 0;
}