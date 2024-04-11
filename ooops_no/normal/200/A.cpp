#include <bits/stdc++.h>
using namespace std;

#define pb push_back

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2010;
pair<int,int> l[N][N], r[N][N];
int cntl[N][N], cntr[N][N];

pair<int,int> find_set_l(int i, int j)
{
    if (i == l[i][j].first && j == l[i][j].second) return {i, j};
    else return l[i][j] = find_set_l(l[i][j].first, l[i][j].second);
}

pair<int,int> find_set_r(int i, int j)
{
    if (i == r[i][j].first && j == r[i][j].second) return {i, j};
    else return r[i][j] = find_set_r(r[i][j].first, r[i][j].second);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    bool swp = 0;
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < N; j++)
        {
            l[i][j] = r[i][j] = {i, j};
        }
    }
    if (n > m)
    {
        swap(n, m);
        swp = 1;
    }
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        if (swp)
        {
            swap(x, y);
        }
        int mx = 1e9;
        pair<int, int> ans;
        int j = x;
        while(j >= 1 && abs(j - x) < mx + 5)
        {
            if (!swp)
            {
                bool f = 0;
                if (find_set_r(r[j][y].first, r[j][y].second).second <= m)
                {
                    if (abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second) < mx)
                    {
                        f = 1;
                    }
                    else if (abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second) == mx){
                        if (j < ans.first){
                            f = 1;
                        }
                        else if (j == ans.first){
                            if (find_set_r(r[j][y].first, r[j][y].second).second < ans.second){
                                f = 1;
                            }
                        }
                    }
                }
                if (f){
                    mx = abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second);
                    ans = {j, find_set_r(r[j][y].first, r[j][y].second).second};
                }
                f = 0;
                if (find_set_l(l[j][y].first, l[j][y].second).second > 0)
                {
                    if (abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second) < mx)
                    {
                        f = 1;
                    }
                    else if (abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second) == mx){
                        if (j < ans.first){
                            f = 1;
                        }
                        else if (j == ans.first){
                            if (find_set_l(l[j][y].first, l[j][y].second).second < ans.second){
                                f = 1;
                            }
                        }
                    }
                }
                if (f){
                    mx = abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second);
                    ans = {j, find_set_l(l[j][y].first, l[j][y].second).second};
                }
            }
            else
            {
                bool f = 0;
                if (find_set_l(l[j][y].first, l[j][y].second).second > 0)
                {
                    if (abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second) < mx)
                    {
                        f = 1;
                    }
                    else if (abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second) == mx){
                        if (find_set_l(l[j][y].first, l[j][y].second).second < ans.second){
                            f = 1;
                        }
                        else if (find_set_l(l[j][y].first, l[j][y].second).second == ans.second){
                            if (j < ans.first){
                                f = 1;
                            }
                        }
                    }
                }
                if (f){
                    mx = abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second);
                    ans = {j, find_set_l(l[j][y].first, l[j][y].second).second};
                }
                f = 0;
                if (find_set_r(r[j][y].first, r[j][y].second).second <= m)
                {
                    if (abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second) < mx)
                    {
                        f = 1;
                    }
                    else if (abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second) == mx){
                        if (find_set_r(r[j][y].first, r[j][y].second).second < ans.second){
                            f = 1;
                        }
                        else if (find_set_r(r[j][y].first, r[j][y].second).second == ans.second){
                            if (j < ans.first){
                                f = 1;
                            }
                        }
                    }
                }
                if (f){
                    mx = abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second);
                    ans = {j, find_set_r(r[j][y].first, r[j][y].second).second};
                }
            }
            j--;
        }
        j = x + 1;
        while(j <= n && abs(j - x) < mx + 5)
        {
            if (!swp)
            {
                bool f = 0;
                if (find_set_r(r[j][y].first, r[j][y].second).second <= m)
                {
                    if (abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second) < mx)
                    {
                        f = 1;
                    }
                    else if (abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second) == mx){
                        if (j < ans.first){
                            f = 1;
                        }
                        else if (j == ans.first){
                            if (find_set_r(r[j][y].first, r[j][y].second).second < ans.second){
                                f = 1;
                            }
                        }
                    }
                }
                if (f){
                    mx = abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second);
                    ans = {j, find_set_r(r[j][y].first, r[j][y].second).second};
                }
                f = 0;
                if (find_set_l(l[j][y].first, l[j][y].second).second > 0)
                {
                    if (abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second) < mx)
                    {
                        f = 1;
                    }
                    else if (abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second) == mx){
                        if (j < ans.first){
                            f = 1;
                        }
                        else if (j == ans.first){
                            if (find_set_l(l[j][y].first, l[j][y].second).second < ans.second){
                                f = 1;
                            }
                        }
                    }
                }
                if (f){
                    mx = abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second);
                    ans = {j, find_set_l(l[j][y].first, l[j][y].second).second};
                }
            }
            else
            {
                bool f = 0;
                if (find_set_l(l[j][y].first, l[j][y].second).second > 0)
                {
                    if (abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second) < mx)
                    {
                        f = 1;
                    }
                    else if (abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second) == mx){
                        if (find_set_l(l[j][y].first, l[j][y].second).second < ans.second){
                            f = 1;
                        }
                        else if (find_set_l(l[j][y].first, l[j][y].second).second == ans.second){
                            if (j < ans.first){
                                f = 1;
                            }
                        }
                    }
                }
                if (f){
                    mx = abs(x - j) + abs(y - find_set_l(l[j][y].first, l[j][y].second).second);
                    ans = {j, find_set_l(l[j][y].first, l[j][y].second).second};
                }
                f = 0;
                if (find_set_r(r[j][y].first, r[j][y].second).second <= m)
                {
                    if (abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second) < mx)
                    {
                        f = 1;
                    }
                    else if (abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second) == mx){
                        if (find_set_r(r[j][y].first, r[j][y].second).second < ans.second){
                            f = 1;
                        }
                        else if (find_set_r(r[j][y].first, r[j][y].second).second == ans.second){
                            if (j < ans.first){
                                f = 1;
                            }
                        }
                    }
                }
                if (f){
                    mx = abs(x - j) + abs(y - find_set_r(r[j][y].first, r[j][y].second).second);
                    ans = {j, find_set_r(r[j][y].first, r[j][y].second).second};
                }
            }
            j++;
        }
        if (!swp) cout << ans.first << " " << ans.second << "\n";
        else cout << ans.second << " " << ans.first << "\n";
        if (1)
        {
            int s = find_set_l(ans.first, ans.second).second;
            l[ans.first][s] = {ans.first, s - 1};
            s = find_set_r(ans.first, ans.second).second;
            r[ans.first][s] = {ans.first, s + 1};
        }
    }
    return 0;
}