#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int in[102][102];
bool used[102][102];
vector<pair<int, int>> p;

int v[102][102];

bool cmp(pair<int, int> x, pair<int, int> y)
{
    int a = x.first, b = x.second;
    int i = y.first, j = y.second;

    return in[a][b] < in[i][j];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        p.clear();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                used[i][j] = false;
                v[i][j] = 0;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> in[i][j];
                p.push_back({i, j});
            }
        }

        sort(p.begin(), p.end(), cmp);

        for(int i=0;i<m;i++)
        {
            int x = p[i].first, y = p[i].second;
            v[x][i] = in[x][y];
            used[x][y] = true;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0, k=0;j<m;j++, k++)
            {
                while(used[i][j]) j++;
                while(v[i][k]) k++;

                v[i][k] = in[i][j];
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cout << v[i][j] << " ";
            }
            cout << "\n";
        }
    }
}